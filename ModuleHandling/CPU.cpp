/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by arthur,
*/

#include <fstream>
#include <numeric>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <string>
#include "CPU.hpp"

CPU::CPU()
{
    _usages = std::vector<float>();
    _frequency = std::vector<std::string>();
    _modelName = std::string();
}

CPU::~CPU()
{
}

void CPU::reset()
{
    _usages.clear();
    _frequency.clear();
    _modelName.clear();
}

const std::vector<float> &CPU::getUsages() const
{
    return _usages;
}

const std::string &CPU::getModelName() const
{
    return _modelName;
}

const std::vector<std::string> &CPU::getFrequency() const
{
    return _frequency;
}

void CPU::setNameFrequency()
{
    std::string line;
    std::fstream my_file("/proc/cpuinfo", std::ios::in);

    if (!my_file)
        return;
    _frequency.clear();
    while (getline(my_file, line)) {
        if (line.compare(0, 10, "model name") == 0) {
            line = line.substr(line.find(":") + 1, line.size());
            _modelName = line;
        } else if (line.compare(0, 7, "cpu MHz") == 0) {
            line = line.substr(line.find(":") + 1, line.size());
            _frequency.push_back(line);
        }
    }
}

static std::vector<std::vector<size_t>> get_times()
{
    std::vector<std::vector<size_t>> all_times;
    std::vector<size_t> times;
    std::ifstream file("/proc/stat");
    std::stringstream str;
    std::string line;
    if (!file.is_open()) {
        all_times.clear();
        return all_times;
    }
    getline(file, line);
    while (!file.eof() && line.find("cpu") != std::string::npos) {
        str << line;
        str.ignore(4, ' ');
        for (size_t tmp; str >> tmp; times.push_back(tmp));
        all_times.push_back(times);
        times.clear();
        str.clear();
        getline(file, line);
    }
    file.close();
    return all_times;
}

void CPU::setCPUActivity()
{
    std::vector<size_t> average;
    float usage = 0;
    std::vector<float> old_total(8);
    std::vector<float> old_idle(8);
    float delta_idle = 0;
    float delta_total = 0;
    size_t idle_time = 0;
    size_t total_time = 0;
    std::vector<std::vector<size_t>> new_times;
    int count = 0;

    while (count < 2) {
        new_times = get_times();
        this->reset();
        for (unsigned long int i = 0; i < new_times.size(); ++i) {
            total_time = std::accumulate(new_times[i].begin(), new_times[i].end(), 0);
            idle_time = new_times[i][3];
            delta_idle = idle_time - old_idle[i];
            delta_total = total_time - old_total[i];
            usage = 100.0 * (1.0 - delta_idle / delta_total);
            _usages.push_back(usage);
            old_total[i] = total_time;
            old_idle[i] = idle_time;
        }
        count++;
        usleep(500000);
    }
}

void CPU::refresh()
{
    this->setCPUActivity();
    this->setNameFrequency();
}