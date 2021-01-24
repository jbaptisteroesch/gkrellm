/*
 * File: Windowcurses.cpp
 * File Created: Saturday, 23rd January 2021 1:35:12 pm
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Sunday, 24th January 2021 2:42:44 am
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#include "WindowCurses.hpp"
#include "Ncurses.hpp"
#include <iostream>

WindowCurses::WindowCurses(int type)
{
    switch (type) {
        case 0 : _cpu = new CPU(); break;
        case 1 : _ram = new ModuleMemory(); break;
        case 2 : _network = new Network(); break;
        case 3 : _sysInfo = new ModuleSystem(); break;
        case 4 : _date = new Date(); break;
        case 5 : _swap = new ModuleSwap(); break;
    }
    _is_disp = true;
}

WindowCurses::~WindowCurses()
{
}

void WindowCurses::launch()
{
}

void WindowCurses::refresh_win()
{
}

int WindowCurses::getSizeX() const
{
    return _size_x;
}

void WindowCurses::setSizeX(int x)
{
    _size_x = x;
}

void WindowCurses::setSizeY(int y)
{
    _size_y = y;
}

void WindowCurses::setWinType(Wintype type)
{
    _type = type;
}

int WindowCurses::getSizeY() const
{
    return _size_y;
}

Wintype WindowCurses::getWinType() const
{
    return _type;
}

void WindowCurses::setWin(int a, int b , int c, int d)
{
    _win = newwin(a, b, c, d);
}

WINDOW *WindowCurses::getWin() const
{
    return _win;
}

void WindowCurses::setName(const std::string &name)
{
    _name = name;
}

std::string WindowCurses::getName() const
{
    return _name;
}

CPU &WindowCurses::getCpu() const
{
    return *_cpu;
}

ModuleMemory &WindowCurses::getRam() const
{
    return *_ram;
} 

ModuleSystem &WindowCurses::sysInfo() const
{
    return *_sysInfo;
}

Network &WindowCurses::getNetwork() const
{
    return *_network;
}

Date &WindowCurses::getDate() const
{
    return *_date;
}

ModuleSwap &WindowCurses::getSwap() const
{
    return *_swap;
}

std::vector<int> WindowCurses::getCross() const
{
    return _cross;
}

void WindowCurses::setCross(int x, int y)
{
    _cross.push_back(x);
    _cross.push_back(y);
}

void WindowCurses::setIsDisp(bool set)
{
    _is_disp = set;
}

bool WindowCurses::getIsDisp() const
{
    return _is_disp;
}

void WindowCurses::setWinPos(WINDOW *win, int x, int y)
{
    mvwin(win, x, y);
}

void WindowCurses::clearCross()
{
    _cross.clear();
}