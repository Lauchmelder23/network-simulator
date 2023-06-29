add_subdirectory(3rdparty/sdl)

add_executable(netsim 
    "src/main.cpp"
)

target_link_libraries(netsim PRIVATE 
    libnetsim
    SDL3::SDL3
)