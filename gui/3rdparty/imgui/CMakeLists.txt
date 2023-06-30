set(IMGUI_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_demo.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_draw.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_impl_sdl3.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_impl_sdlrenderer3.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_tables.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui_widgets.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/imgui.cpp"
    PARENT_SCOPE
)

set(IMGUI_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include PARENT_SCOPE)