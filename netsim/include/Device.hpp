#pragma once

#include <cstdint>
#include <string>
#include <memory>

class Device {
public:
    friend std::ostream& operator<<(std::ostream& os, const Device& device);

public:
    Device(const std::string& macAddress);
    static std::shared_ptr<Device> create(const std::string& macAddress);

private:
    void parseAndSetMac(const std::string& macAddress);

public:
    uint8_t macAddress[6];
};