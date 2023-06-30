#include "NetworkRenderer.hpp"

#include "DeviceRenderer.hpp"

NetworkRenderer::NetworkRenderer(Network& network) :
    network(network)
{

}

void NetworkRenderer::AddDevice(std::shared_ptr<Device> device, uint16_t x, uint16_t y) {
    devices.push_back(DeviceRenderer(device, x, y));
}

void NetworkRenderer::Render(SDL_Renderer* renderer) const {
    for (const DeviceRenderer& device : devices) {
        device.Render(renderer);
    }
}