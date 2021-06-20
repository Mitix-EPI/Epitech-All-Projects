/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Ncurse
*/

#include "Ncurse.hpp"

Ncurse::Ncurse() : MonitorDisplay()
{
}

Ncurse::~Ncurse()
{
    this->destroy();
}

void Ncurse::init(void)
{
    // INIT Ncurses
    initscr(); // Start ncurses
    noecho();
    curs_set(0); // Cursor invisible
    start_color();
    keypad(stdscr, TRUE);
    use_default_colors();
    nodelay(stdscr, true);

    mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);

    // COLOR
    init_pair(0, COLOR_WHITE, -1);
    init_pair(1, COLOR_RED, COLOR_RED);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, -1);
    init_pair(7, COLOR_BLUE, -1);
    init_pair(8, COLOR_YELLOW, -1);
}

void Ncurse::run(void)
{
    MEVENT event;
    int ch;

    this->init();
    while (1) {
        ch = wgetch(stdscr);
        if (ch == KEY_MOUSE) {
            assert(getmouse(&event) == OK);

            if (event.x >= 0 && event.x <= 58 && event.y >= 5 && event.y <=  (int)(15 + (2 * (int)this->_cpu.getNumberCores()))) {
                this->_cpu.setIsShown();
            }
            if (event.x >= 59 && event.x <= 100 && event.y >= 5 && event.y <= 23) {
                this->_network.setIsShown();
            }
            if (event.x >= 0 && event.x <= 58 && event.y >= (15 + (2 * (int)this->_cpu.getNumberCores()) + 1) && event.y <= (15 + (2 * (int)this->_cpu.getNumberCores()) + 1 + 6)) {
                this->_task.setIsShown();
            }
        }
        this->update();
        this->display();
    }
}

void Ncurse::update(void)
{
    this->_cpu.clearMap();
    this->_cpu.updateData();
    this->_time.updateData();
    this->_user.updateData();
    this->_network.updateData();
}

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void Ncurse::displayCore()
{
    attron(COLOR_PAIR(2));
    rectangle(5, 0, 15 + (2 * (int)this->_cpu.getNumberCores()), 58);
    attroff(COLOR_PAIR(2));
    // CPUs
    mvprintw(6, 1, "%s with %d cores", this->_cpu.getModelName().c_str(), this->_cpu.getNumberCores());
    mvprintw(8, 1, "CPU average temperature: %d°C", this->_cpu.getTemperature());
    int y = 9;
    auto tab = this->_cpu.getPercentage();
    std::string all_cpu;
    auto all = this->_cpu.getCPUs();
    for (size_t length = 0; length < tab.size(); length += 1) {
        all_cpu = "cpu" + std::to_string(length);
        y += 2;
        mvprintw(y, 2, "%s", all_cpu.c_str());
        attron(COLOR_PAIR(3));
        for (int i = 1, length = 30; i < length; i++)
            mvprintw(y, i + 9, " ");
        attroff(COLOR_PAIR(3));
        int perc = (round(tab[all_cpu.c_str()]) * 30) / 100;
        attron(COLOR_PAIR(1));
        for (int i = 1; i < perc; i++)
            mvprintw(y, i + 9, " ");
        attroff(COLOR_PAIR(1));
        mvprintw(y, 43, "%.0f %%", round(tab[all_cpu.c_str()]));
    }

    // Mem
    int length = 30;
    y += 2;
    mvprintw(y, 2, "Memory");
    attron(COLOR_PAIR(3));
    for (int i = 1; i < length; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(4));
    int cachedMemoryPercentage = round((this->_mem.getCurrentRamMB() * 30) / this->_mem.getTotalRamMB());
    for (int i = 1; i < cachedMemoryPercentage; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(4));
    mvprintw(y, 43, "%.2fG/%.2fG", this->_mem.getCurrentRamMB(), this->_mem.getTotalRamMB());

    // Swap
    y += 2;
    mvprintw(y, 2, "Swap");
    attron(COLOR_PAIR(3));
    for (int i = 1, length = 30; i < length; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(5));
    int swapPercentage = round(((this->_mem.getFreeSwapMB() * 0.001) * 30) / this->_mem.getTotalSwapMB());
    if (swapPercentage < 2)
        swapPercentage = 2;
    for (int i = 1; i < swapPercentage; i++)
        mvprintw(y, i + 9, " ");
    attroff(COLOR_PAIR(5));
    mvprintw(y, 43, "%.1fM/%.2fG", this->_mem.getFreeSwapMB(), this->_mem.getTotalSwapMB());
}

void Ncurse::displayUserInfo()
{
    attron(COLOR_PAIR(0));
    rectangle(0, 0, 4, 58);
    mvprintw(1, 2, "Username: %s", this->_user.getUserName().c_str());
    int x = 2;
    size_t count = 0;
    mvprintw(2, x, "Host:    ");
    x += 10;
    for (const auto &it : this->_user.getHostName()) {
        mvprintw(2, x, "%s", it.c_str());
        x += it.length();
        count += 1;
        if (this->_user.getHostName().size() > count) {
            x += 2;
            mvprintw(2, x, ", ");
        }
    }
    mvprintw(3, 2, "Version:  %s", this->_user.getOsVersion().c_str());
    attroff(COLOR_PAIR(0));
    attron(COLOR_PAIR(6));
    rectangle(0, 59, 4, 100);
    attroff(COLOR_PAIR(6));
    std::string date = this->_time.getActualDate();
    std::replace(date.begin(), date.end(), ':', '/');
    mvprintw(1, 61, "Date: %s", date.c_str());
    mvprintw(2, 61, "Hour: %s", this->_time.getActualTime().c_str());
    mvprintw(3, 61, "Uptime: %s", this->_time.getUptime().c_str());
}

void Ncurse::displayDataTransfer()
{
    attron(COLOR_PAIR(7));
    rectangle(5, 59, 23, 100);
    attroff(COLOR_PAIR(7));
    mvprintw(6, 60, "Network Data Transfer:");
    int y = 8;
    std::vector<network_data_t> data = this->_network.getData();
    for (int i = 0; i < this->_network.getSize(); i++) {
        mvprintw(y, 65, "%s:", data[i].name.c_str());
        mvprintw(y + 1, 70, "UP   => %.2fKb/s", data[i].up);
        mvprintw(y + 2, 70, "DOWN => %.2fKb/s", data[i].down);
        y += 3;
    }
}

void Ncurse::displayProcess(void)
{
    std::ofstream file("toto.txt", std::ofstream::out);
    int y = 15 + (2 * (int)this->_cpu.getNumberCores()) + 1;
    file << this->_cpu.getNumberCores() << "     " << y;
    file.close();
    attron(COLOR_PAIR(8));
    rectangle(y, 0, y + 6, 58);
    attroff(COLOR_PAIR(8));
    mvprintw(y + 1, 22, "Load average :");
    mvprintw(y + 3, 14, "%.2f/5mn   %.2f/10mn   %.2f/15mn", this->_task.getAverage()[0], this->_task.getAverage()[1], this->_task.getAverage()[2]);
    mvprintw(y + 5, 19, "%.0f runninng / %.0f tasks", this->_task.getAverage()[3], this->_task.getAverage()[4]);
}

void Ncurse::display(void)
{
    clear();
    if (this->_cpu.isShown())
        displayCore();
    displayUserInfo();
    if (this->_network.isShown())
        displayDataTransfer();
    if (this->_task.isShown())
        displayProcess();
    refresh();
    clear();
    sleep(1);
}

void Ncurse::destroy(void)
{
    curs_set(1);
    endwin();
}
