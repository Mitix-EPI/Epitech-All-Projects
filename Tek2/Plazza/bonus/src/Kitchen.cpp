 /*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int mult, int cooksNum, int time)
{
    for (int i = 0; i < cooksNum; i++) {
        this->_cooks.push_back(new Cooks());
    }
    this->_time = clock();
    this->_timeRefill = clock();
    this->_mq.in.open("/cmd_canal");
    this->_mq.out.open("/status_canal");
    this->_mult = mult;
    this->_timeIngredients = time;
    this->_pool = new Thread_pool(cooksNum);
    this->_ingredients["doe"] = 5;
    this->_ingredients["tomato"] = 5;
    this->_ingredients["gruyere"] = 5;
    this->_ingredients["ham"] = 5;
    this->_ingredients["mushrooms"] = 5;
    this->_ingredients["steak"] = 5;
    this->_ingredients["eggplant"] = 5;
    this->_ingredients["goatCheese"] = 5;
    this->_ingredients["chiefLove"] = 5;
    this->_posCommands = 0;
}

Kitchen::~Kitchen()
{
    this->clearMQ();
    this->_mq.in.close();
    this->_mq.out.close();
}

void Kitchen::clearMQ()
{
    while (1) {
        if (this->_mq.in.receive() > 0) {
            std::cout << "finished and received : " << this->_mq.in._buffer << std::endl;
            Logfile::logFile(this->_mq.in._buffer);
        } else {
            break;
        }
    }
}

std::string Kitchen::returnKitchen(void)
{
    std::string res;

    for (size_t i = 0; i < this->_cooks.size(); i++) {
        res.append("cook[");
        res.append(std::to_string(i));
        res.append("]:");
        if (this->_pool->_fpool.getSizeQueue() != 0)
            res.append("current 1, ");
        else
            res.append("current 0, ");
        if (i < (size_t)this->_pool->_fpool.getSizeQueue())
            res.append("next 1\r\n");
        else
            res.append("next 0\r\n");
    }
    // std::cout << std::endl << "res : " << res << std::endl << std::endl;
    return res;
}

void Kitchen::sendFinishedCommand(command_t *command)
{
    std::string res;
    command->waiting = true;
    // std::cout << std::endl << "type : " << std::to_string(command->pizzaType) << std::endl;
    // std::cout << "size : " << std::to_string(command->pizzaSize) << std::endl;
    res.append("Finished ");
    if (command->pizzaType == Regina)
        res.append("regina ");
    else if (command->pizzaType == Margarita)
        res.append("margarita ");
    else if (command->pizzaType == Americana)
        res.append("americana ");
    else if (command->pizzaType == Fantasia)
        res.append("fantasia ");
    else
        res.append("unknown ");
    if (command->pizzaSize == S)
        res.append("size S");
    else if (command->pizzaSize == M)
        res.append("size M");
    else if (command->pizzaSize == L)
        res.append("size L");
    else if (command->pizzaSize == XL)
        res.append("size XL");
    else if (command->pizzaSize == XXL)
        res.append("size XXL");
    else
        res.append("size Unknown");
    // std::cout << "sending to core this : " << res << std::endl;
    this->_mq.out.send(res.c_str());
}

bool Kitchen::acceptNewPizza(command_t command)
{
    this->_time = clock();
    this->_commands.push_back(&command);
    for (auto cook: this->_cooks)
        if (!cook->getCurrent().waiting) {
            cook->setCurrent(command);
            return true;
        }
    for (auto cook: this->_cooks)
        if (!cook->getNext().waiting) {
            cook->setNext(command);
            return true;
        }
    return false;
}

void Kitchen::timeSinceInactivity(void)
{
    static int is_entered = 0;
    clock_t time = clock() - this->_time;
    float sec = (float)time / CLOCKS_PER_SEC;
    if (sec >= 5 && is_entered == 0) {
        this->_mq.out.send("Kitchen kill");
        // std::cout << "killed kitchen" << std::endl;
        // exit(0);
        is_entered = 1;
    }
}

void Kitchen::parseCookCommand(std::string buffer)
{
    commandData_t *com = new commandData_t();
    std::string type;
    std::string size;
    std::string cookNum;
    std::string cookPos;
    size_t i = 6;
    for (; i < buffer.size() && buffer[i] != ']'; i++)
        cookNum.push_back(buffer[i]);
    i += 2;
    for (; i < buffer.size() && buffer[i] != ']'; i++)
        cookPos.push_back(buffer[i]);
    i += 2;
    for (; i < buffer.size() && buffer[i] != ','; i++)
        type.push_back(buffer[i]);
    i++;
    for (; i < buffer.size() && buffer[i] != '\r'; i++)
        size.push_back(buffer[i]);
    if (i < buffer.size()) {
        // MATCHED
        // std::cout << "Regex matched" << buffer << std::endl;
        com->command = new command_t();
        com->command->currentStep = 0;
        com->command->number = 1;
        com->command->waiting = true;
        if (type.compare("1") == 0) {
            com->command->pizzaType = Regina;
            com->command->steps = 5;
        } else if (type.compare("2") == 0) {
            com->command->pizzaType = Margarita;
            com->command->steps = 3;
        } else if (type.compare("4") == 0) {
            com->command->pizzaType = Americana;
            com->command->steps = 4;
        } else if (type.compare("8") == 0) {
            com->command->pizzaType = Fantasia;
            com->command->steps = 5;
        } else {
            std::cout << "no corresponding pizza type" << std::endl;
            return;
        }
        if (size.compare("1") == 0)
            com->command->pizzaSize = S;
        else if (size.compare("2") == 0)
            com->command->pizzaSize = M;
        else if (size.compare("4") == 0)
            com->command->pizzaSize = L;
        else if (size.compare("8") == 0)
            com->command->pizzaSize = XL;
        else if (size.compare("16") == 0)
            com->command->pizzaSize = XXL;
        else {
            std::cout << "no corresponding pizza size" << std::endl;
            return;
        }
        std::stringstream sstream(cookNum);
        size_t result;
        sstream >> result;
        if (result > this->_cooks.size()) {
            std::cout << "incorrect cook position for command" << std::endl;
            return;
        }
        com->mult = this->_mult;
        com->_ingredients = &this->_ingredients;
        com->command->waiting = true;
        com->command->status = 0;
        this->_commands.push_back(com->command);
        this->_pool->_fpool.push(Cooks::cookPizza, com);
    } else {
        std::cout << "No match regex kitchen" << std::endl;
        // ERROR HANDLING (EXCEPTIONS ETC.)
    }
}

void Kitchen::addIngredients(void)
{
    clock_t time = clock() - this->_timeRefill;
    int sec = time / CLOCKS_PER_SEC / 1000;
    if (sec >= this->_timeIngredients && 
    (this->_ingredients["doe"] < 5 ||
    this->_ingredients["tomato"] < 5 ||
    this->_ingredients["gruyere"] < 5 ||
    this->_ingredients["ham"] < 5 ||
    this->_ingredients["mushrooms"] < 5 ||
    this->_ingredients["steak"] < 5 ||
    this->_ingredients["eggplant"] < 5 ||
    this->_ingredients["goatCheese"] < 5 ||
    this->_ingredients["chiefLove"] < 5)) {
        this->_ingredients["doe"] += ((this->_ingredients["doe"] < 5) ? 1 : 0);
        this->_ingredients["tomato"] += ((this->_ingredients["tomato"] < 5) ? 1 : 0);
        this->_ingredients["gruyere"] += ((this->_ingredients["gruyere"] < 5) ? 1 : 0);
        this->_ingredients["ham"] += ((this->_ingredients["ham"] < 5) ? 1 : 0);
        this->_ingredients["mushrooms"] += ((this->_ingredients["mushrooms"] < 5) ? 1 : 0);
        this->_ingredients["steak"] += ((this->_ingredients["steak"] < 5) ? 1 : 0);
        this->_ingredients["eggplant"] += ((this->_ingredients["eggplant"] < 5) ? 1 : 0);
        this->_ingredients["goatCheese"] += ((this->_ingredients["goatCheese"] < 5) ? 1 : 0);
        this->_ingredients["chiefLove"] += ((this->_ingredients["chiefLove"] < 5) ? 1 : 0);
        this->_time = clock();
    }
}

void Kitchen::run(void)
{
    std::string buffer;

    while (1) {
        if (this->_mq.in.receive() > 0) {
            buffer = std::string(this->_mq.in._buffer);
            // std::cout << "Kitchen[" << this->getId() - 1<< "] receive cmd:" << buffer.c_str() << std::endl;
            if (buffer.compare("status\r\n") == 0) {
                std::string buff = this->returnKitchen();
                // std::cout << "Kitchen[" << this->getId() - 1 << "] send status:" << std::endl << buff.c_str() << std::endl;
                this->_mq.out.send(buff.c_str());
            } else if (buffer.find("Cooks") != std::string::npos && buffer.find("\r\n") != std::string::npos ) {
                this->parseCookCommand(buffer);
            } else if (buffer.compare("kill\r\n") == 0) {
                this->_mq.out.send("Kitchen killed");
                exit(0);
            }
            this->_time = clock();
        }
        for (size_t i = 0; i < this->_commands.size(); i++) {
            // std::cout << "command [" << std::to_string(i) << "] = " << std::to_string(this->_commands[i]->waiting) << std::endl;
            if (this->_commands[i]->waiting == false) {
                this->sendFinishedCommand(this->_commands[i]);
                this->_time = clock();
            }
            if (this->_commands[i]->status != 2)
                this->_time = clock();
        }
        this->timeSinceInactivity();
        this->addIngredients();
    }
}

Kitchen Kitchen::operator<<(Kitchen prev)
{
    return prev;
}

Kitchen Kitchen::operator>>(Kitchen next)
{
    return next;
}

int Kitchen::getId(void)
{
    return this->_id;
}

void Kitchen::setId(int id)
{
    this->_id = id;
}

void Kitchen::setMq(mq_t mq)
{
    this->_mq = mq;
}

mq_t Kitchen::getMq(void)
{
    return this->_mq;
}
