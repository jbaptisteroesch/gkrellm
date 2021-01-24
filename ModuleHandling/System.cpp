/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by dmitry,
*/

#include <fstream>
#include <iostream>
#include <sys/utsname.h>
#include <unistd.h>
#include <limits.h>
#include "System.hpp"

ModuleSystem::ModuleSystem() {
}

ModuleSystem::~ModuleSystem() {
}

void ModuleSystem::setUsername() {
    char username[LOGIN_NAME_MAX];
    getlogin_r(username, LOGIN_NAME_MAX);
    _username = username;
}

void ModuleSystem::setHostname() {
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    _hostname = hostname;
}

void ModuleSystem::setPrettyName() {
    std::string line;
    std::fstream my_file("/etc/os-release", std::ios::in);
    if (!my_file)
        return;
    while (getline(my_file, line)) {
        if (line.compare(0, 12, "PRETTY_NAME=") == 0) {
            line = line.substr(13, line.size());
            _prettyName = line.substr(0, line.size() - 1);
        }
    }
}



const std::string &ModuleSystem::getHostname() const {
    return _hostname;
}

const std::string &ModuleSystem::getUsername() const {
    return _username;
}

const std::string &ModuleSystem::getPrettyName() const {
    return _prettyName;
}

const std::string &ModuleSystem::getRelease() const {
    return _release;
}

const std::string &ModuleSystem::getSysname() const {
    return _sysname;
}

const std::string &ModuleSystem::getVersion() const {
    return _version;
}

const std::string &ModuleSystem::getMachine() const {
    return _machine;
}

void ModuleSystem::setBattery() {
    std::string line;
    std::ifstream actual("/sys/class/power_supply/BAT0/energy_now");
    std::ifstream full("/sys/class/power_supply/BAT0/energy_full");
    int pourcentage = 0;
    float now = 0;
    float max = 0;
    if (!actual.is_open() || !full.is_open()) {
        std::ifstream actual2("/sys/class/power_supply/BAT0/charge_now");
        actual = dynamic_cast<std::basic_ifstream<char> &&>(actual2);
        std::ifstream full2("/sys/class/power_supply/BAT0/charge_full");
        full = dynamic_cast<std::basic_ifstream<char> &&>(full2);
    }

    if (!actual || !full)
        return;
    getline(actual, line);
    now = std::stof(line);
    getline(full, line);
    max = std::stof(line);

    pourcentage = (int)(( now / max ) * 100);
    _pourcentage = std::to_string(pourcentage);
}

std::string ModuleSystem::getPourcentage() const {
    return _pourcentage;
}

void ModuleSystem::refresh()
{
    this->setPrettyName();
    this->setUsername();
    this->setHostname();
    this->setBattery();
    this->setRelease();
}

void ModuleSystem::setRelease() {
    struct utsname unameData;

    uname(&unameData);
    _release = unameData.release;
    _version = unameData.version;
    _sysname = unameData.sysname;
    _machine =  unameData.machine;
}
