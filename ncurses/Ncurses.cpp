/*
 * File: ncurses.cpp
 * File Created: Friday, 22nd January 2021 11:48:51 pm
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Sunday, 24th January 2021 2:42:13 am
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#include "Ncurses.hpp"
#include "WindowCurses.hpp"
#include "../ModuleHandling/CPU.hpp"
#include "../ModuleHandling/Network.hpp"
#include <iostream>
#include <stdexcept>

DisplayNcurses::DisplayNcurses()
{
    _isRunning = 1;
    _nbModule = 6;
    _nbModuleDisp = 6;
    _module_name.push_back("CPU");
    _module_name.push_back("Memory");
    _module_name.push_back("Network");
    _module_name.push_back("System");
    _module_name.push_back("Date");
    _module_name.push_back("Swap");
    _init_module.push_back(WINCPU);
    _init_module.push_back(WINMEMORY);
    _init_module.push_back(WINNETWORK);
    _init_module.push_back(WINSYSTEM);
    _init_module.push_back(WINDATE);
    _init_module.push_back(WINSWAP);
    initscr();
    start_color();
    if (!(can_change_color())) {
        _isRunning = 0;
        endwin();
        std::cout << "Your terminal does not support color" << std::endl;
    }
    if (_isRunning) {
        init_window();
        raw();
	    noecho();
        cbreak();
        mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, nullptr);
	    keypad(stdscr,TRUE);
        curs_set(0);
	    nodelay(stdscr,TRUE);
        refresh();
    }
}

DisplayNcurses::~DisplayNcurses()
{
    endwin();
}

void DisplayNcurses::create_window(int type)
{
    if (_nbModule == 6)
        return;
    WindowCurses *new_win = new WindowCurses(type);
    int x = 0;
    int y = 0;
    int cross = 0;

    switch (_nbModule) {
        case 0 : x = 0; y = 0; cross = 34; break;
        case 1 : x = 0; y = 37; cross = 71; break;
        case 2 : x = 0; y = 74; cross = 108; break;
        case 3 : x = 22; y = 0; cross = 34; break;
        case 4 : x = 22; y = 37; cross = 71; break;
        case 5 : x = 22; y = 74; cross = 108; break;
    }

    ++_nbModule;
    new_win->setWin(20, 35, x, y);
    new_win->setWinType(_init_module[type]);
    new_win->setName(_module_name[type]);
    new_win->setCross(cross, x);
    _sub_win.push_back(new_win);
}