#include "write_file.hpp"

int main() {

    std::vector<size_t> shape = {3, 3, 1};
    std::vector<uint64_t> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    write_data("example", shape, data);
    write_data("example11", {9}, data.data());

}