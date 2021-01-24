/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by arthur,
*/

#ifndef B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_CPU_HPP
#define B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_CPU_HPP

#include "IMonitorModule.hpp"
#include <vector>
#include <string>

class CPU: public IMonitorModule {
public:
    CPU();
    ~CPU();
    void reset();
    void refresh();
    const std::vector<float> &getUsages() const;
    const std::string &getModelName() const;
    const std::vector<std::string> &getFrequency() const;
    void setNameFrequency();
    void setCPUActivity();
private:
    std::vector<float> _usages;
    std::vector<std::string> _frequency;
    std::string _modelName;
};

#endif //B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_CPU_HPP
