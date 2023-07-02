#pragma once

#include <memory>
#include <vector>

class Device;

class Port {
public:
    Port();

    void Connect(std::shared_ptr<Port> port);

    void Send(const std::vector<uint8_t>& data);
    std::vector<uint8_t> Receive();

private:
    std::vector<uint8_t> data;
    std::weak_ptr<Port> connection;
};