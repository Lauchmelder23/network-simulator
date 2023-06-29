#include "Device.hpp"

#include <sstream>
#include <iostream>

Device::Device(const std::string& macAddress) {
    parseAndSetMac(macAddress);
}

std::shared_ptr<Device> Device::create(const std::string& macAddress) {
    return std::make_shared<Device>(macAddress);
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