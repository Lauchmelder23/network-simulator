add_executable(netsim 
    "main.cpp"
    "Device.cpp"
    "Network.cpp"
)

target_include_directories(netsim PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)