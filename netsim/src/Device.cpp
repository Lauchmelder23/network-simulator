#include "Device.hpp"

#include <sstream>
#include <iostream>

#include "Port.hpp"

Device::Device(const std::string& macAddress) {
    port = std::make_shared<Port>();
    parseAndSetMac(macAddress);
}

Device::Device(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f) :
    macAddress{a, b, c, d, e, f}
{
    port = std::make_shared<Port>();
}

void Device::parseAndSetMac(const std::string& mac) {
    sscanf(
        mac.c_str(),
        "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
        &(macAddress[0]),
        &(macAddress[1]),
        &(macAddress[2]),
        &(macAddress[3]),
        &(macAddress[4]),
        &(macAddress[5])
    );
}

void Device::Connect(std::shared_ptr<Device> other) {
    port->Connect(other->port);
    other->port->Connect(port);
}

std::ostream& operator<<(std::ostream& os, const Device& device) {
    printf(
        "%02X:%02X:%02X:%02X:%02X:%02X",
        device.macAddress[0],
        device.macAddress[1],
        device.macAddress[2],
        device.macAddress[3],
        device.macAddress[4],
        device.macAddress[5]
    );

    return os;
}