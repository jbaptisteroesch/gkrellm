/*
** EPITECH PROJECT, 2021
** B_CPP_300_STG_3_1_CPPrush3_loic_deraze
** File description:
** Created by dmitry,
*/

#ifndef B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SWAP_HPP
#define B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SWAP_HPP

#include "IMonitorModule.hpp"

class ModuleSwap: public IMonitorModule {
public:
    ModuleSwap();
    virtual ~ModuleSwap();
    void refresh();
    int getSwapTotal() const;
    int getSwapFree() const;
    int getSwapUsed() const;

private:
    int _swapTotal;
    int _swapFree;
    int _swapUsed;
};

#endif //B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SWAP_HPP
