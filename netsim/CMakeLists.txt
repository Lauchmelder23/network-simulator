add_library(libnetsim STATIC 
    "src/Device.cpp"
    "src/Network.cpp"
    "src/Port.cpp"
)

target_include_directories(libnetsim PUBLIC
    include
)