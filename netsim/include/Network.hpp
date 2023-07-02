#pragma once

#include <vector>
#include <memory>
#include <string>

#include "Device.hpp"

class Network {
public:
    friend std::ostream& operator<<(std::ostream& os, const Network& network);

public:
    Network(const std::string& name);

    void AddDevice(std::shared_ptr<Device> device);

    void SendCycle();
    void ReceiveCycle();
    void Cycle();

private:
    std::vector<std::shared_ptr<Device>> devices;
    std::string name;
};