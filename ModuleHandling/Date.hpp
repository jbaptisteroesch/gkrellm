/*
** EPITECH PROJECT, 2021
** B_CPP_300_STG_3_1_CPPrush3_loic_deraze
** File description:
** Created by dmitry,
*/

#ifndef B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_DATE_HPP
#define B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_DATE_HPP

#include <string>
#include "IMonitorModule.hpp"

class Date: public IMonitorModule {
public:
    Date();
    void setUpTime();
    void getTimeDate();
    void refresh();
    virtual ~Date();
    const std::string &getDate() const;
    const std::string &getTime() const;
    const std::string &getUptime() const;
private:
    std::string _date;
    std::string _time;
    std::string _uptime;
};

#endif //B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_DATE_HPP
