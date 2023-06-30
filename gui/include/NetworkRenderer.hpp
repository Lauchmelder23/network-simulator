#pragma once

#include <vector>
#include "Network.hpp"
#include "DeviceRenderer.hpp"

class NetworkRenderer {
public:
    NetworkRenderer(Network& network);

    void AddDevice(std::shared_ptr<Device> device, uint16_t x, uint16_t y);
    void Render(SDL_Renderer* renderer) const;

private:
    Network& network;
    std::vector<DeviceRenderer> devices;
};