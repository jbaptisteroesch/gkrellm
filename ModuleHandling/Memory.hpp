/*
** EPITECH PROJECT, 2021
** test
** File description:
** Created by dmitry,
*/

#ifndef TEST_TESTE_HPP
#define TEST_TESTE_HPP

#include <string>
#include <list>
#include "IMonitorModule.hpp"

class ModuleMemory: public IMonitorModule {
public:
    ModuleMemory();
    void getMemory();
    virtual ~ModuleMemory();
    int getMemoryMax() const;
    int getMemoryFree() const;
    int getMemoryUsed() const;

private:
    int _memoryMax;
    int _memoryFree;
    int _memoryUsed;

};

#endif //TEST_TESTE_HPP
