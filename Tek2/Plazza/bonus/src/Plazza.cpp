/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** plazza_shell
*/

#include "Plazza.hpp"
#include "Kitchen.hpp"
#include "Graphical.hpp"
#include "DisplayLog.hpp"

std::vector<std::string> splitBuffer(std::string buffer, std::string delimiter)
{
    // SI y'a pas un ; -> alors tu retournes le buffer
    std::vector<std::string> res;
    if (buffer.find(delimiter) == std::string::npos) {
        res.push_back(buffer);
        return res;
    }
    size_t pos = 0;
    std::string token = "";
    while ((pos = buffer.find(delimiter)) != std::string::npos) {
        token = buffer.substr(0, pos);
        res.push_back(token);
        buffer.erase(0, pos + delimiter.length());
    }
    res.push_back(buffer);
    return res;
}

char asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}
PizzaType getPizzaType(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), asciitolower); // Lowercase
    if (str == "regina")
        return Regina;
    if (str == "margarita")
        return Margarita;
    if (str == "americana")
        return Americana;
    if (str == "fantasia")
        return Fantasia;
    std::cerr << "Error getPizzaType" << std::endl;
    return PizzaType::None;
}

PizzaSize getPizzaSize(std::string str)
{
    if (str == "S")
        return S;
    if (str == "M")
        return M;
    if (str == "L")
        return L;
    if (str == "XL")
        return XL;
    if (str == "XXL")
        return XXL;
    std::cerr << "Error getPizzaSize" << std::endl;
    return PizzaSize::Null;
}

size_t getPizzaNumber(int number)
{
    if (number < 0)
        return 0;
    return number;
}

command_t *fillCommandStruct(std::string buffer)
{
    std::smatch args;
    command_t *command = new command_t;
    std::regex regx("(\\w+) (S|M|L|XL|XXL) x(\\d+)");

    if (std::regex_search(buffer, args, regx)) {
        // MATCHED
        command->pizzaType = getPizzaType((args[1]));
        command->pizzaSize = getPizzaSize(args[2]);
        command->number = getPizzaNumber(std::stoi(args[3]));
    } else {
        std::cout << "No match regex command" << std::endl;
        delete(command);
        // ERROR HANDLING (EXCEPTIONS ETC.)
        return NULL;
    }
    if (!command->pizzaType || !command->pizzaSize || !command->number) {
        std::cout << "Error no valid argument" << std::endl;
        delete(command);
        return NULL;
    }
    return command;
}

std::vector<command_t *> parse_command(std::string buffer)
{
    std::vector<command_t *> res;
    std::vector<std::string> splittedCommand = splitBuffer(buffer, ";");
    for (auto command : splittedCommand) {
        command_t *strct = fillCommandStruct(command);
        if (strct)
            res.push_back(strct);
        else
            return std::vector<command_t *>();
    }
    return res;
}

void deleteCommands(std::vector<command_t *> commands)
{
    for (auto command: commands)
        if (command)
            delete command;
}

Plazza::Plazza(size_t multiplier, size_t Cooks, size_t time)
{
    this->_multiplizer = multiplier;
    this->_Cooks = Cooks;
    this->_time = time;
    this->_kitchen_nbr = 0;
    Logfile::initLogFile();
}

Plazza::~Plazza()
{
    for (size_t i = 0; i < this->_kitchen_nbr; i++) {
        std::cout << "Plazza send \"kill\" to kitchen " << std::to_string(i) << std::endl;
        this->_mq.at(i).out.send("kill\r\n");
    }
    for (size_t i = 0; i < this->_kitchen_nbr; i++)
        this->clearMQ(i);
    for (size_t i = 0; i < this->_mq.size(); i++) {
        this->_mq[i].in.close();
        this->_mq[i].out.close();
    }
}

void Plazza::createKitchen()
{
    this->_kitchen_nbr += 1;
    mq_t mq_tmp;
    kitchenStatus_t newKitchenStatus;
    newKitchenStatus._closed = false;
    for (size_t i = 0; i < this->_Cooks; i++) {
        cookStatus_t cookStatusTmp;
        cookStatusTmp._current = AVAILABLE;
        cookStatusTmp._next = AVAILABLE;
        newKitchenStatus._cooks.push_back(cookStatusTmp);
    }
    this->_kitchenStatus.push_back(newKitchenStatus);
    mq_tmp.in.open("/" + std::to_string(this->_kitchen_nbr) + "_in");  // "/id_in"
    mq_tmp.out.open("/" + std::to_string(this->_kitchen_nbr) + "_out"); // "/id_out"
    this->_mq.push_back(mq_tmp);
    pid_t pid = fork();
    if (pid == -1) {
        this->_kitchen_nbr -= 1;
        perror("fork");
        exit(84);
    } else if (pid == 0) {
        Kitchen kitchen(this->_multiplizer, this->_Cooks, this->_time);
        kitchen.setId(this->_kitchen_nbr);
        kitchen._mq.in.open("/" + std::to_string(kitchen.getId()) + "_out");
        kitchen._mq.out.open("/" + std::to_string(kitchen.getId()) + "_in");
        kitchen.run();
    } else {
        usleep(2000);
        std::string kitch("Creating new kitchen with id ");
        kitch.append(std::to_string(this->_kitchen_nbr));
        Logfile::logFile(kitch);
        // std::cout << "Creating new kitchen[" << this->_kitchen_nbr - 1 << "]" << std::endl;
    }
}

enum status_s Plazza::getEnumStatus(std::string arg)
{
    int nb = std::stoi(arg);

    if (nb == 0)
        return AVAILABLE;
    else
        return NOT_AVAILABLE;
}

std::vector<cookStatus_t> Plazza::parseStatus(std::string buffer)
{
    kitchenStatus_t res;
    std::smatch args;
    std::regex regx("\\w+\\[(\\d+)]:current (\\d+), next (\\d+)");

    std::cout << buffer << std::endl;
    if (std::regex_search(buffer, args, regx)) {
        // MATCHED
        size_t size = args.size() / 3;
        for (size_t i = 0; i < size; i++) {
            cookStatus_t cook;
            cook._current = this->getEnumStatus(args[(i * 3) + 1]);
            cook._next = this->getEnumStatus(args[(i * 3) + 2]);
            res._cooks.push_back(cook);
        }
    } else {
        std::cout << "No match regex" << std::endl;
        exit(84);
    }
    return res._cooks;
}

void logStatus(std::vector<kitchenStatus_t> kitchenStatus)
{
    std::cout << "KITCHEN STATUS" << std::endl;
    size_t kitchenI = 0;

    for (auto kitchen : kitchenStatus) {
        std::cout << "Kicthen[" << kitchenI << "]" << std::endl;
        size_t cooksI = 0;
        for (auto cook : kitchen._cooks) {
            std::cout << "\tCook[" << cooksI << "]: current " << cook._current << ", next " << cook._next << std::endl;
            cooksI++;
        }
        kitchenI++;
    }
    if (kitchenI == 0)
        std::cout << "No kitchen available on this log" << std::endl << std::endl;
}

void Plazza::clearMQ(size_t i)
{
    while (1) {
        if (this->_mq.at(i).in.receive() > 0) {
            // std::cout << "finished and received : " << this->_mq.at(i).in._buffer << std::endl;
            std::string buff(this->_mq.at(i).in._buffer);
            std::string kitch(buff);
            kitch.append(" with kitchen id ");
            kitch.append(std::to_string(i + 1));
            Logfile::logFile(kitch);
            if (buff.find("kill") != std::string::npos)
                this->_kitchenStatus[i]._closed = true;
        } else {
            break;
        }
    }
}

void Plazza::getStatus(void)
{
    // std::cout << "\nGet Status start" << std::endl;
    for (size_t i = 0; i < this->_kitchen_nbr; i++) {
        if (this->_kitchenStatus[i]._closed == false)
            this->clearMQ(i);
    }
    for (size_t i = 0; i < this->_kitchen_nbr; i++) {
        // std::cout << "Plazza send \"status\" to kitchen " << std::to_string(i) << std::endl;
        if (this->_kitchenStatus[i]._closed == false)
            this->_mq.at(i).out.send("status\r\n");
    }
    usleep(1000);
    for (size_t i = 0; i < this->_kitchen_nbr; i++) {
        if (this->_kitchenStatus[i]._closed == false) {
            this->_mq.at(i).in.receive();
            std::string buff(this->_mq.at(i).in._buffer);
            // std::cout << "Plazza received : " << buff << std::endl;
            if (buff.find("current") != std::string::npos) { // Si c'est bien un receive de getStatus
                // std::cout << "Plazza received status" << std::endl << buff << std::endl;
                this->_kitchenStatus[i]._cooks = this->parseStatus(buff);
            }
        }
    }
    // std::cout << "Get Status end\n" << std::endl;
}

void Plazza::sendCommandToKitchen(size_t kitchenI, size_t cookI, size_t cookStatus, PizzaType pizzaType, PizzaSize pizzaSize)
{
    std::string buff("Cooks[" + std::to_string(cookI) + "][" + std::to_string(cookStatus) + "]:" + std::to_string(pizzaType) + "," + std::to_string(pizzaSize) + "\r\n");

    std::string kitch("Cooking ");
    if (pizzaType == 1)
        kitch.append("Regina size ");
    else if (pizzaType == 2)
        kitch.append("Margarita size ");
    else if (pizzaType == 4)
        kitch.append("Americana size ");
    else if (pizzaType == 8)
        kitch.append("Fantasia size ");
    if (pizzaSize == S)
        kitch.append("S kitchen(");
    else if (pizzaSize == M)
        kitch.append("M kitchen(");
    else if (pizzaSize == L)
        kitch.append("L kitchen(");
    else if (pizzaSize == XL)
        kitch.append("XL kitchen(");
    else if (pizzaSize == XXL)
        kitch.append("XXL kitchen(");
    kitch.append(std::to_string(kitchenI + 1));
    kitch.append(") cook(");
    kitch.append(std::to_string(cookI + 1));
    kitch.append(")");
    Logfile::logFile(kitch);
    // std::cout << "Plazza send cmd: " << buff << std::endl;
    this->_mq.at(kitchenI).out.send(buff.c_str());
}

bool Plazza::fillKitchen(command_t *command)
{
    size_t kitchenI = 0;

    for (auto kitchenStatus : this->_kitchenStatus) {
        if (kitchenStatus._closed == false) {
            size_t cookI = 0;
            for (auto cook : kitchenStatus._cooks) {
                if (cook._current == AVAILABLE) {
                    // std::cout << "Plazza fill kitchen[" << kitchenI << "] cook [" << cookI << "] current" << std::endl;
                    this->sendCommandToKitchen(kitchenI, cookI, 0,  command->pizzaType, command->pizzaSize);
                    this->_kitchenStatus.at(kitchenI)._cooks.at(cookI)._current = NOT_AVAILABLE;
                    usleep(2000);
                    return true;
                }
                cookI++;
            }
        }
        kitchenI++;
    }
    kitchenI = 0;
    for (auto kitchenStatus : this->_kitchenStatus) {
        if (kitchenStatus._closed == false) {
            size_t cookI = 0;
            for (auto cook : kitchenStatus._cooks) {
                if (cook._next == AVAILABLE) {
                    // std::cout << "Plazza fill kitchen[" << kitchenI << "] cook [" << cookI << "] next" << std::endl;
                    this->sendCommandToKitchen(kitchenI, cookI, 1, command->pizzaType, command->pizzaSize);
                    this->_kitchenStatus.at(kitchenI)._cooks.at(cookI)._next = NOT_AVAILABLE;
                    usleep(2000);
                    return true;
                }
                cookI++;
            }
        }
        kitchenI++;
    }
    return false;
}

void Plazza::handlingCommand(command_t *command)
{
    // command->number
    // command->pizzaType
    // command->pizzaSize
    while (command->number) {
        if (!this->fillKitchen(command)) {
            this->createKitchen();
            this->fillKitchen(command);
        }
        command->number--;
    }
}

void Plazza::checkPizzaFinished()
{
    size_t i = 0;
    for (auto mq : this->_mq) {
        this->clearMQ(i);
        i++;
    }
}

int Plazza::runShell(void)
{
    std::string buffer;
    std::vector<command_t *> commands;
    Graphical *sfml = new Graphical();

    while (1) {
        sfml->loop(getDisplayLog(), _kitchen_nbr);
        if (sfml->_buffer.size() != 0) {
            commands = parse_command(sfml->_buffer);
            if (commands.size() > 0) {
                this->getStatus();
                // logStatus(this->_kitchenStatus);

                for (auto command : commands) {
                    this->handlingCommand(command);
                }
                deleteCommands(commands);
            }
            sfml->_buffer.clear();
        }
        usleep(1000);
        this->checkPizzaFinished();
    }
    return 0;
}
