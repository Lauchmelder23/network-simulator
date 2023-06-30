add_subdirectory(3rdparty/sdl)
add_subdirectory(3rdparty/imgui)

add_executable(netsim 
    "src/main.cpp"
)

target_sources(netsim PRIVATE ${IMGUI_SOURCES})
target_include_directories(netsim PRIVATE ${IMGUI_INCLUDE_DIR})

target_link_libraries(netsim PRIVATE 
    libnetsim
    SDL3::SDL3
)