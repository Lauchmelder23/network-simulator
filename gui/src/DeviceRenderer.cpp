#include "DeviceRenderer.hpp"

#include <SDL.h>

DeviceRenderer::DeviceRenderer(std::shared_ptr<Device> device, uint16_t x, uint16_t y) :
    device(device), selected(false)
{
    bbox.x = x;
    bbox.y = y;
    bbox.w = 50;
    bbox.h = 50;
}

void DeviceRenderer::Deselect() {
    selected = false;
}

void DeviceRenderer::Render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    SDL_RenderFillRect(renderer, &bbox);

    if (selected) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &bbox);
    }
}