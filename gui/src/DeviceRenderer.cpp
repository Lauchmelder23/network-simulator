#include "DeviceRenderer.hpp"

#include <SDL.h>

DeviceRenderer::DeviceRenderer(std::shared_ptr<Device> device, uint16_t x, uint16_t y) :
    device(device), selected(false), grabbed(false)
{
    bbox.x = x;
    bbox.y = y;
    bbox.w = 50;
    bbox.h = 50;
}

void DeviceRenderer::Deselect() {
    selected = false;
}

bool DeviceRenderer::PropagateEvent(SDL_Event* event) {
    if (event->type == SDL_EVENT_MOUSE_BUTTON_UP) {
        if (event->button.button == SDL_BUTTON_LEFT) {
            grabbed = false;
        }
    }
    else if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        float x, y;
        SDL_GetMouseState(&x, &y);

        if (x >= bbox.x && x <= bbox.x + bbox.w && y >= bbox.y && y <= bbox.y + bbox.h) {
            selected = true;
            grabbed = true;
            return true;
        }

    } else if (grabbed && event->type == SDL_EVENT_MOUSE_MOTION) {
       float x, y;
       SDL_GetMouseState(&x, &y); 

       bbox.x += event->motion.xrel;
       bbox.y += event->motion.yrel;

       return true;
    }

    return false;
}

void DeviceRenderer::Render(SDL_Renderer* renderer) const {
    SDL_SetRenderDrawColor(renderer, 150, 150, 150, 255);
    SDL_RenderFillRect(renderer, &bbox);

    if (selected) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderRect(renderer, &bbox);
    }
}