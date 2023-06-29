#include <iostream>

#include "Netsim.hpp"

int main(int argc, char** argv) {
    Network network("Testnet");

    network.addDevice(Device::create("FA:56:A7:12:04:ED"));
    network.addDevice(Device::create("87:1A:B5:77:3D:33"));

    std::cout << network << std::endl;

    return 0;
}