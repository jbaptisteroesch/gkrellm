/*
 * File: ncurses.hpp
 * File Created: Friday, 22nd January 2021 11:30:05 pm
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Sunday, 24th January 2021 2:42:00 am
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#ifndef NCURSES
#define NCURSES

#include "../IMonitorDisplay.hpp"
#include "WindowCurses.hpp"
#include <ncurses.h>
#include <vector>

class DisplayNcurses
{
    public :
    
    DisplayNcurses();
    virtual ~DisplayNcurses();
    void launch();
    void init_window();
    void refresh_win();
    void clear_win();
    void draw_ui();
    void displayData();
    void mouse_event(MEVENT event);
    void analyse_getch(int);
    void create_window(int);
    void setClose();

    private:

    bool _isRunning;
    int _size_x;
    int _size_y;
    int _nbModule;
    int _nbModuleDisp;
    std::vector<WindowCurses*> _sub_win;
    std::vector<Wintype> _init_module;
    std::vector<std::string> _module_name;
};
#endif /* NCURSES */
