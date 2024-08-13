#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdint>

inline int write_data(std::string name, std::vector<size_t> shape, std::vector<uint64_t> data) {
    //creat a directory to store the data
    std::string dir = "FHE_PARAM";
    std::string command = "mkdir -p " + dir;
    system(command.c_str());
    
    // Create filename with dimensions encoded
    std::stringstream filename;
    filename << dir << "/" << name << "___GPUFHE___";
    for (size_t i = 0; i < shape.size(); i++) {
        filename << shape[i];
        if (i < shape.size() - 1) {
            filename << "x";
        }
    }
    filename << ".bin";
    std::ofstream outfile(filename.str(), std::ios::binary | std::ios::out);

    if (!outfile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    // Write array data
    outfile.write(reinterpret_cast<char*>(data.data()), data.size() * sizeof(uint64_t));

    outfile.close();
    return 0;
}

inline int write_data(std::string name, std::vector<size_t> shape, uint64_t* data) {
    //creat a directory to store the data
    std::string dir = "FHE_PARAM";
    std::string command = "mkdir -p " + dir;
    system(command.c_str());
    
    // Create filename with dimensions encoded
    std::stringstream filename;
    filename << dir << "/" << name << "___GPUFHE___";
    for (size_t i = 0; i < shape.size(); i++) {
        filename << shape[i];
        if (i < shape.size() - 1) {
            filename << "x";
        }
    }
    filename << ".bin";
    std::ofstream outfile(filename.str(), std::ios::binary | std::ios::out);

    if (!outfile.is_open()) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    size_t size = 1;
    for (size_t i = 0; i < shape.size(); i++) {
        size *= shape[i];
    }

    // Write array data
    outfile.write(reinterpret_cast<char*>(data), size * sizeof(uint64_t));

    outfile.close();
    return 0;
}