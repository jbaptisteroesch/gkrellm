/*
** EPITECH PROJECT, 2021
** test
** File description:
** Created by dmitry,
*/

#include <fstream>
#include <iostream>
#include "Memory.hpp"

ModuleMemory::ModuleMemory() {
}

ModuleMemory::~ModuleMemory() {
}

void ModuleMemory::getMemory()
{
    int i = 0;
    std::string line;
    std::fstream my_file("/proc/meminfo", std::ios::in);
    if (!my_file)
        return;
    while (getline(my_file, line)) {
        if (i == 0) {
            line = line.substr(line.find(":") + 1, line.size());
            line = line.substr(0, line.size() - 2);
            _memoryMax = std::stoi(line);
        }
        else if (i == 2) {
            line = line.substr(line.find(":") + 1, line.size());
            line = line.substr(0, line.size() - 2);
            _memoryFree = std::stoi(line);
        }
        ++i;
    }
    _memoryUsed = _memoryMax - _memoryFree;
}

int ModuleMemory::getMemoryMax() const {
    return _memoryMax;
}

int ModuleMemory::getMemoryFree() const {
    return _memoryFree;
}

int ModuleMemory::getMemoryUsed() const {
    return _memoryUsed;
}