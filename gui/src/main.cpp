#include <iostream>

#include <SDL.h>
#include "Netsim.hpp"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(1000, 1000, NULL, &window, &renderer);
    SDL_SetWindowTitle(window, "netsim");

    Network network("Testnet");

    network.addDevice(Device::create("FA:56:A7:12:04:ED"));
    network.addDevice(Device::create("87:1A:B5:77:3D:33"));

    std::cout << network << std::endl;

    bool shouldClose = false;
    SDL_Event event;

    while (!shouldClose) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                case SDL_EVENT_QUIT:
                    shouldClose = true;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}