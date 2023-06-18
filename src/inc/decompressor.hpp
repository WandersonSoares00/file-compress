#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <iostream>
#include "Compactor.hpp"

class Decompressor : private Compactor{
public:

    Decompressor();
    void run(std::string in_file, std::string out_file) override;

private:
    void read_file(std::ifstream& file) override;
};


#endif