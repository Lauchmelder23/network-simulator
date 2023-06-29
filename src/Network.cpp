#include "Network.hpp"

#include <iostream>

Network::Network(const std::string& name) :
    name(name)
{
}

void Network::addDevice(std::shared_ptr<Device> device) {
    devices.push_back(device);
}

std::ostream& operator<<(std::ostream& os, const Network& network) {
    os << "Network '" << network.name << "'" << std::endl << std::endl;

    os << "Devices:" << std::endl;
    for (const auto& dev : network.devices) {
        os << "\t" << *dev << std::endl;
    }

    return os;
}