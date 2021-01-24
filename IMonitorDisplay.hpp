/*
 * File: IMonitorDisplay.hpp
 * File Created: Friday, 22nd January 2021 8:35:06 pm
 * Author: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Last Modified: Saturday, 23rd January 2021 5:11:03 pm
 * Modified By: Jean-Baptiste Roesch (jean-baptiste.roesch@epitech.eu)
 * -----
 * Copyright - 2021 Jean-Baptiste Roesch
 */

#ifndef IMONITORDISPLAY
#define IMONITORDISPLAY

#include "ModuleHandling/CPU.hpp"
#include "ModuleHandling/Memory.hpp"
#include "ModuleHandling/System.hpp"
#include "ModuleHandling/Network.hpp"
#include "ModuleHandling/Swap.hpp"
#include "ModuleHandling/Date.hpp"

class IMonitorDisplay
{
    public :
    virtual void launch() = 0;
    virtual void refresh_win() = 0;
    virtual CPU const &getCpu() const = 0;
    virtual ModuleMemory const &getRam() const = 0;
    virtual ModuleSystem const &sysInfo() const = 0;
    virtual Network const &getNetwork() const = 0;
    virtual Date const &getDate() const = 0;
    virtual ModuleSwap const &getSwap() const = 0;
};
#endif /* IMONITORDISPLAY */
