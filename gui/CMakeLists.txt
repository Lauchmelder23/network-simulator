add_executable(netsim 
    "src/main.cpp"
)

target_link_libraries(netsim PRIVATE 
    libnetsim
)