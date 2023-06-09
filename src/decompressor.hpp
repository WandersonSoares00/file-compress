#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H
#include <unordered_map>
#include <iostream>

class Decompressor{
    std::unordered_map <char, unsigned char> map_bytes;

public:
    Decompressor();
    ~Decompressor();
    
    void run();
    void decod(std::string out_file);
private:
    void getCodes();
};


#endif