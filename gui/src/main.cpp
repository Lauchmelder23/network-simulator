#include <iostream>
#include <random>

#include <SDL.h>
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

#include "Netsim.hpp"
#include "NetworkRenderer.hpp"

int main(int argc, char** argv) {
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(1000, 1000, NULL, &window, &renderer);
    SDL_SetWindowTitle(window, "netsim");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImGui::StyleColorsDark();

    Network network("Testnet");
    NetworkRenderer networkRenderer(network);

    bool shouldClose = false;
    SDL_Event event;

    while (!shouldClose) {
        while (SDL_PollEvent(&event)) {
            ImGui_ImplSDL3_ProcessEvent(&event);

            if (ImGui::GetIO().WantCaptureMouse) {
                continue;
            }

            networkRenderer.PropagateEvent(&event);

            switch (event.type) {
                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                case SDL_EVENT_QUIT:
                    shouldClose = true;
                    break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        networkRenderer.Render(renderer);

        ImGui_ImplSDL3_NewFrame();
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui::NewFrame();

        if (ImGui::BeginMainMenuBar()) {

            if (ImGui::BeginMenu("New...")) {
                if (ImGui::MenuItem("Host")) {
                    auto device = Device::create();

                    network.addDevice(device);
                    networkRenderer.AddDevice(device, 400, 400);
                };

                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

        networkRenderer.RenderImGui();

        ImGui::Render();
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData());

        SDL_RenderPresent(renderer);
    }

    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}