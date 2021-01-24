/*
** EPITECH PROJECT, 2021
** B_CPP_300_STG_3_1_CPPrush3_loic_deraze
** File description:
** Created by dmitry,
*/

#include <fstream>
#include "Swap.hpp"

ModuleSwap::ModuleSwap() {
    _swapFree = 0;
    _swapTotal = 0;
    _swapUsed = 0;
}

ModuleSwap::~ModuleSwap() {
}

void ModuleSwap::refresh() {
    std::string line;
    std::fstream my_file("/proc/meminfo", std::ios::in);

    if (!my_file)
        return;
    while (getline(my_file, line)) {
        if (line.compare(0, 10, "SwapTotal:") == 0) {
            line = line.substr(line.find(":") + 1, line.size());
            line = line.substr(0, line.size() - 2);
            _swapTotal = std::stoi(line);
        } else if (line.compare(0, 9, "SwapFree:") == 0) {
            line = line.substr(line.find(":") + 1, line.size());
            line = line.substr(0, line.size() - 2);
            _swapFree = std::stoi(line);
        }
    }
    _swapUsed = _swapTotal - _swapFree;
}

int ModuleSwap::getSwapTotal() const {
    return _swapTotal;
}

int ModuleSwap::getSwapFree() const {
    return _swapFree;
}

int ModuleSwap::getSwapUsed() const {
    return _swapUsed;
}
