/*
** EPITECH PROJECT, 2021
** B_CPP_300_STG_3_1_CPPrush3_loic_deraze
** File description:
** Created by dmitry,
*/

#include <fstream>
#include "Date.hpp"

Date::Date() {
}

Date::~Date() {
}

const std::string &Date::getDate() const {
    return _date;
}

const std::string &Date::getTime() const {
    return _time;
}

const std::string &Date::getUptime() const {
    return _uptime;
}

void Date::setUpTime() {
    std::string line;
    std::string res;
    std::fstream my_file("/proc/uptime", std::ios::in);
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    if (!my_file)
        return;
    while (getline(my_file, line)) {
        line = line.substr(0, line.size());
        res = line.substr(0, line.find('.'));
    }
    seconds = std::stoi(res);
    minutes = seconds / 60;
    hours = minutes / 60;
    minutes %= 60;
    seconds %= 60;
    if (hours / 10 < 1)
        _uptime = "0" + std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
    else
        _uptime = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
}

void Date::getTimeDate() {
    time_t now = time(0);
    std::string tmp;
    std::string info = ctime(&now);

    tmp = info;
    _date = info.substr(0, 10);
    _date += info.substr(19, info.size());
    _time = info.substr(11, info.size());
    _time = _time.substr(0, _time.size() - 5);
}

void Date::refresh() {
    this->getTimeDate();
    this->setUpTime();
}

