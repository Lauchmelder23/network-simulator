#pragma once

#include <memory>
#include <SDL.h>
#include "Device.hpp"

struct SDL_Renderer;

class DeviceRenderer {
public:
    DeviceRenderer(std::shared_ptr<Device> device, uint16_t x, uint16_t y);

    void Render(SDL_Renderer* renderer) const;
    void Deselect();

private:
    SDL_FRect bbox;
    bool selected;
    std::shared_ptr<Device> device;
};