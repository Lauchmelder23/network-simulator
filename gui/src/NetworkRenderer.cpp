#include "NetworkRenderer.hpp"

#include "DeviceRenderer.hpp"

NetworkRenderer::NetworkRenderer(Network& network) :
    network(network)
{

}

void NetworkRenderer::AddDevice(std::shared_ptr<Device> device, uint16_t x, uint16_t y) {
    devices.push_back(DeviceRenderer(device, x, y));
}

void NetworkRenderer::PropagateEvent(SDL_Event* event) {
    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT) {
        for (DeviceRenderer& device : devices) {
            device.Deselect();
        }
    }

    for (auto it = devices.rbegin(); it != devices.rend(); it++) {
        if (it->PropagateEvent(event)) {
            break;
        }
    }
}

void NetworkRenderer::Render(SDL_Renderer* renderer) const {
    for (const DeviceRenderer& device : devices) {
        device.Render(renderer);
    }
}

void NetworkRenderer::RenderImGui() const {
    for (const DeviceRenderer& device : devices) {
        if (device.Selected()) {
            device.RenderImGui();
        }
    }
}