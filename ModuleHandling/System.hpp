/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by dmitry,
*/

#ifndef B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SYSTEM_HPP
#define B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SYSTEM_HPP

#include <string>
#include "IMonitorModule.hpp"

class ModuleSystem: public IMonitorModule {
public:
    ModuleSystem();
    void setUsername();
    void setHostname();
    void setPrettyName();
    void setBattery();
    void refresh();
    void setRelease();
    virtual ~ModuleSystem();
    const std::string &getHostname() const;
    const std::string &getUsername() const;
    const std::string &getPrettyName() const;
    std::string getPourcentage() const;
    const std::string &getRelease() const;
    const std::string &getSysname() const;
    const std::string &getVersion() const;
    const std::string &getMachine() const;

private:
    std::string _hostname;
    std::string _username;
    std::string _prettyName;
    std::string _pourcentage;
    std::string _release;
    std::string _sysname;
    std::string _version;
    std::string _machine;
};

#endif //B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_SYSTEM_HPP
