#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <unordered_map>
#include <iostream>
#include "Compactor.hpp"

class Decompressor : private Compactor{
public:
    Decompressor();
    //~Decompressor();
    
    //void run();
    void decod(std::string in_file, std::string out_file);
    void store(std::string out_file) override;
};


#endif