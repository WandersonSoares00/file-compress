#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <iostream>
#include "compactor.hpp"

class Decompressor : private Compactor{
    unsigned char single_char;
public:

    Decompressor();
    void run(std::string in_file, std::string out_file) override;

private:
    void read_file(std::ifstream& file) override;
};


#endif