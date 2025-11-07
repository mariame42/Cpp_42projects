#include "Serialization.hpp"


int main(void)
{
    Data* data = new Data;
    data->id = 0;
    data->name = "serialized";

    uintptr_t raw = Serialization::serialize(data);
    Data* back = Serialization::deserialize(raw);

    std::cout << "original: " << data << "\n";
    std::cout << "decoded : " << back << "\n";
    std::cout << (back == data ? "OK: pointers equal" : "ERROR: pointers differ") << std::endl;

    delete data;
    return 0;
}