add_library(libnetsim STATIC 
    "src/Device.cpp"
    "src/Network.cpp"
)

target_include_directories(libnetsim PUBLIC
    include
)