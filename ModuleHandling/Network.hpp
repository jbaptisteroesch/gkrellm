/*
** EPITECH PROJECT, 2021
** B-CPP-300-STG-3-1-CPPrush3-loic.deraze
** File description:
** Created by arthur,
*/

#ifndef B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_NETWORK_HPP
#define B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_NETWORK_HPP


class Network {
public:
    Network();
    ~Network();
    void refresh();
    void reset();
    long get_received_packets() const;
    long get_send_packets() const;
private:
    long _receivedPackets;
    long _sendPackets;
};

#endif //B_CPP_300_STG_3_1_CPPRUSH3_LOIC_DERAZE_NETWORK_HPP
