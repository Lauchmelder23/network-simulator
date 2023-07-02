#pragma once

#include <cstdint>
#include <array>
#include <string>
#include <memory>

class Port;

class Device {
public:
    friend std::ostream& operator<<(std::ostream& os, const Device& device);

public:
    Device(const std::string& macAddress);
    Device(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f);

    inline static std::shared_ptr<Device> Create(const std::string& macAddress) {
        return std::make_shared<Device>(macAddress);
    }

    inline static std::shared_ptr<Device> Create() {
        return std::make_shared<Device>(rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    }

    void Connect(std::shared_ptr<Device> other);

    void Send();
    void Receive();

private:
    void parseAndSetMac(const std::string& macAddress);

private:
    std::shared_ptr<Port> port;

public:
    uint8_t macAddress[6];
};