#include "Port.hpp"

Port::Port()
{
   
}

void Port::Connect(std::shared_ptr<Port> port) {
    this->connection = std::weak_ptr<Port>(port);
}

void Port::Send(const std::vector<uint8_t>& data) {
    this->data = data;
}

std::vector<uint8_t> Port::Receive() {
    if (this->connection.expired()) {
        return {};
    }

    std::shared_ptr<Port> other_port = connection.lock();
    return other_port->data;
}