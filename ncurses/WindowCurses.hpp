/*
 * File: window.hpp
 * File Created: Saturday, 23rd January 2021 1:13:04 pm
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Sunday, 24th January 2021 2:42:08 am
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#ifndef WINDOWCURSES
#define WINDOWCURSES

#include "../IMonitorDisplay.hpp"
#include "Wintype.hpp"
#include "ncurses.h"
class WindowCurses : public IMonitorDisplay
{
    public :
    
    WindowCurses(int);
    virtual ~WindowCurses();
    void launch();
    void refresh_win();
    int getSizeX() const;
    void setSizeX(int);
    void setSizeY(int);
    void setWinType(Wintype);
    int getSizeY() const;
    Wintype getWinType()const;
    void setWin(int, int, int, int);
    WINDOW *getWin() const;
    void setName(const std::string &name);
    std::string getName() const;
    CPU &getCpu() const;
    ModuleMemory &getRam() const; 
    ModuleSystem &sysInfo() const;
    Network &getNetwork() const;
    Date &getDate() const;
    ModuleSwap &getSwap() const;
    std::vector<int> getCross() const;
    void setCross(int, int);
    void setIsDisp(bool);
    bool getIsDisp() const;
    void setWinPos(WINDOW* , int, int);
    void clearCross();

    private:

    int _size_x;
    int _size_y;
    bool _is_disp;
    std::string _name;
    std::vector<int> _cross;
    Wintype _type;
    WINDOW *_win;
    CPU *_cpu;
    ModuleMemory *_ram;
    ModuleSystem *_sysInfo;
    Network *_network;
    ModuleSwap *_swap;
    Date *_date;
};

#endif /* WINDOWCURSES */
