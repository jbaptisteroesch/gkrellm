/*
 * File: launch_ncurses.cpp
 * File Created: Saturday, 23rd January 2021 1:04:40 am
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Sunday, 24th January 2021 2:50:52 am
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#include "Ncurses.hpp"
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <math.h>

void DisplayNcurses::refresh_win()
{
    for(std::vector<int>::size_type it = 0; it < _sub_win.size(); ++it)
        wrefresh(_sub_win[it]->getWin());
}

void DisplayNcurses::clear_win()
{
    for(std::vector<int>::size_type it = 0; it < _sub_win.size(); ++it)
        wclear(_sub_win[it]->getWin());
}

void DisplayNcurses::init_window()
{
    int x = 0;
    int y = 0;
    int val = 34;
    int z = 0;
    
    for (int i = 0; i < _nbModule; i++) {
        WindowCurses *new_win = new WindowCurses(i);
        if (z == 3)
            z = 0;
        if (z == 0)
            val = 34;
        if (z == 1)
            val = 71;
        if (z == 2)
            val = 108;
        new_win->setWin(20, 35, x, y);
        new_win->setWinType(_init_module[i]);
        new_win->setName(_module_name[i]);
        new_win->setCross(val, x);
        _sub_win.push_back(new_win);
        y += 37;
        z++;
        if (i == 2) {
            x += 22;
            y = 0;
        }
    }
}

void DisplayNcurses::draw_ui()
{
    for(int it = 0; it < _nbModule; ++it) {
        bool disp = _sub_win[it]->getIsDisp();
        if (disp) {
            const char *str = (_sub_win[it]->getName()).c_str();
            box(_sub_win[it]->getWin(), ACS_VLINE, ACS_HLINE);
            mvwprintw(_sub_win[it]->getWin(), 0, 1, "%s", str);
            mvwprintw(_sub_win[it]->getWin(), 0, 34, "X");
        }
    }
}

void DisplayNcurses::displayData()
{
    for (int i = 0; i < _nbModule; ++i) {
        bool disp = _sub_win[i]->getIsDisp();
        if (_sub_win[i]->getWinType() == WINMEMORY && disp) {
            _sub_win[i]->getRam().getMemory();
            mvwprintw(_sub_win[i]->getWin(), 7, 3, "Used memory : %d kB", _sub_win[i]->getRam().getMemoryUsed());
            mvwprintw(_sub_win[i]->getWin(), 9, 3, "Free memory : %d kB", _sub_win[i]->getRam().getMemoryFree());
            mvwprintw(_sub_win[i]->getWin(), 11, 3, "Max memory  : %d kB", _sub_win[i]->getRam().getMemoryMax());
            float flo = ((float)(_sub_win[i]->getRam().getMemoryUsed()) / (float)(_sub_win[i]->getRam().getMemoryMax())) * 100;
            flo = roundf(flo);
            int y = 8;
            mvwprintw(_sub_win[i]->getWin(), 15, 7, "[");
            for (int z = 0; z < (18 * flo * 0.01); z++) {
                mvwprintw(_sub_win[i]->getWin(), 15, y++, "|");
            }
            mvwprintw(_sub_win[i]->getWin(), 15, 26, "]");
        }
        if (_sub_win[i]->getWinType() == WINNETWORK && disp) {
            _sub_win[i]->getNetwork().refresh();
            mvwprintw(_sub_win[i]->getWin(), 8, 3, "Received packets : %ld", _sub_win[i]->getNetwork().get_received_packets());
            mvwprintw(_sub_win[i]->getWin(), 10, 3, "Send packets     : %ld", _sub_win[i]->getNetwork().get_send_packets());
        }
        if (_sub_win[i]->getWinType() == WINSWAP && disp) {
            _sub_win[i]->getSwap().refresh();
            mvwprintw(_sub_win[i]->getWin(), 7, 3, "Total swap : %d kB", _sub_win[i]->getSwap().getSwapTotal());
            mvwprintw(_sub_win[i]->getWin(), 9, 3, "Used swap  : %d kB", _sub_win[i]->getSwap().getSwapUsed());
            mvwprintw(_sub_win[i]->getWin(), 11, 3, "Free swap  : %d kB", _sub_win[i]->getSwap().getSwapFree());
        }
        if (_sub_win[i]->getWinType() == WINDATE && disp) {
            _sub_win[i]->getDate().refresh();
            const char *str_one = (_sub_win[i]->getDate().getDate()).c_str();
            const char *str_two = (_sub_win[i]->getDate().getTime()).c_str();
            const char *str_three = (_sub_win[i]->getDate().getUptime()).c_str();
            mvwprintw(_sub_win[i]->getWin(), 7, 3, "Date    : %s", str_one);
            mvwprintw(_sub_win[i]->getWin(), 9, 3, "Time    : %s", str_two);
            mvwprintw(_sub_win[i]->getWin(), 11, 3, "Uptime  : %s", str_three);
        }
        if (_sub_win[i]->getWinType() == WINSYSTEM && disp) {
            _sub_win[i]->sysInfo().refresh();
            const char *str_one = (_sub_win[i]->sysInfo().getUsername()).c_str();
            const char *str_two = (_sub_win[i]->sysInfo().getHostname()).c_str();
            const char *str_three = (_sub_win[i]->sysInfo().getPrettyName()).c_str();
            const char *str_four = (_sub_win[i]->sysInfo().getPourcentage()).c_str();
            const char *str_five = (_sub_win[i]->sysInfo().getRelease()).c_str();
            const char *str_six = (_sub_win[i]->sysInfo().getSysname()).c_str();
            const char *str_eight = (_sub_win[i]->sysInfo().getMachine()).c_str();
            mvwprintw(_sub_win[i]->getWin(), 3, 3, "Username    : %s", str_one);
            mvwprintw(_sub_win[i]->getWin(), 5, 3, "Hostname    : %s", str_two);
            mvwprintw(_sub_win[i]->getWin(), 7, 3, "Pretty Name : %s", str_three);
            mvwprintw(_sub_win[i]->getWin(), 9, 3, "Battery at  : %s %", str_four);
            mvwprintw(_sub_win[i]->getWin(), 11, 3, "Sysname     : %s", str_six);
            mvwprintw(_sub_win[i]->getWin(), 13, 3, "Release     : %s", str_five);
            mvwprintw(_sub_win[i]->getWin(), 15, 3, "Machine     : %s %", str_eight);
        }
        if (_sub_win[i]->getWinType() == WINCPU && disp) {
            _sub_win[i]->getCpu().refresh();
            int y = 10;
            std::vector<float> vec = _sub_win[i]->getCpu().getUsages();
            int x = 4;
            const char *str_one = (_sub_win[i]->getCpu().getModelName()).c_str();
            mvwprintw(_sub_win[i]->getWin(), 1, 2, "CPU name : %s", str_one);
            for (unsigned long int it = 0; it < vec.size(); it++) {
                float flo = vec[it];
                flo = roundf(flo);
                for (int z = 0; z < (17 * flo * 0.01); z++) {
                    mvwprintw(_sub_win[i]->getWin(), x, y++, "|");
                }
                y = 10;
                mvwprintw(_sub_win[i]->getWin(), x, 2, "CPU %ld :", it);
                mvwprintw(_sub_win[i]->getWin(), x, 28, "%.2f", vec[it]);
                x += 2;
            }
        }
    }
}

void DisplayNcurses::mouse_event(MEVENT event)
{
    std::vector<int> vec;
    for (unsigned long int i = 0; i < _sub_win.size(); ++i) {
        vec = _sub_win[i]->getCross();
        if (event.x == vec[0] && event.y == vec[1]) {
            _sub_win.erase(_sub_win.begin() + i);
            _nbModule--;
            int x, y = 0;
            for (int i = 0; i < _nbModule; ++i) {
                if (i < 3) {
                    _sub_win[i]->setWinPos(_sub_win[i]->getWin(), x, y);
                    y += 37;
                }
                if (i == 2) {
                    x += 22;
                    y = 0;
                }
                if (i > 2) {
                _sub_win[i]->setWinPos(_sub_win[i]->getWin(), x, y);
                    y += 37;
                }
            }
            clear();
        }
    }
}

void DisplayNcurses::analyse_getch(int c)
{
    if (c == 'a') {
        create_window(0);
        return;
    }
    if (c == 'z') {
        create_window(1);
        return;
    }
    if (c == 'e') {
        create_window(2);
        return;
    }
    if (c == 'r') {
        create_window(3);
        return;
    }
    if (c == 't') {
        create_window(4);
        return;
    }
    if (c == 'y') {
        create_window(5);
        return;
    }
}

void DisplayNcurses::setClose(void)
{
    int z = 0;
    int w = 0;
    for (int t = 0; t < _nbModule; ++t) {
        _sub_win[t]->clearCross();
        if (z == 3) {
            z = 0;
            w += 22;
        }
        if (z == 0)
            _sub_win[t]->setCross(34, w);
        else if (z == 1)
            _sub_win[t]->setCross(71, w);
        else if (z == 2)
            _sub_win[t]->setCross(108, w);
        z++;
    }
}

void DisplayNcurses::launch()
{
    if (!_isRunning)
        return;
    int c = getch();
    MEVENT event;
    srand(time(0));
    do {
        clear_win();
        displayData();
        draw_ui();
        usleep(40000);
        refresh_win();
        c = getch();
        if(getmouse(&event) == OK) {
            if (event.bstate & BUTTON1_PRESSED)
                getmouse(&event);
            mouse_event(event);
        }
        setClose();
        analyse_getch(c);
    } while (c != 27);
}