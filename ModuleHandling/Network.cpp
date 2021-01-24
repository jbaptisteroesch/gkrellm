/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by arthur,
*/

#include <fstream>
#include <iostream>
#include "Network.hpp"

Network::Network()
{
    _receivedPackets = 0;
    _sendPackets = 0;
}

Network::~Network()
{
}

void Network::reset()
{
    _receivedPackets = 0;
    _sendPackets = 0;
}

long Network::get_received_packets() const
{
    return _receivedPackets;
}

long Network::get_send_packets() const
{
    return _sendPackets;
}

void Network::refresh()
{
    std::ifstream file("/proc/net/dev");
    std::string line;
    size_t start;
    long send = 0;
    long received = 0;

    this->reset();
    if (file.is_open()) {
        while (!file.eof()) {
            line.clear();
            std::getline(file, line);
            start = line.find(':');
            if (start == std::string::npos)
                continue;
            start = line.find_first_of("123456789", start);
            if (start == std::string::npos)
                continue;
            for (; start < line.size() && isdigit(line[start]); start++);

            start = line.find_first_of("123456789", start);
            for (; start < line.size() &&  isdigit(line[start]); ++start)
                received = received * 10 + (line[start] - 48);

            start = line.find_first_of("123456789", start);
            for (; start < line.size() && isdigit(line[start]); start++);

            start = line.find_first_of("123456789", start);
            for (; start < line.size() && isdigit(line[start]); ++start)
                send = send * 10 + (line[start] - 48);
            _sendPackets += send;
            _receivedPackets += received;
            send = 0;
            received = 0;
        }
    }
}