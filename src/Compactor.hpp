#ifndef COMPACTOR_HPP
#define COMPACTOR_HPP

#include "string"
#include <unordered_map>
//#include <cstring>

#include <bitset>

template<typename T>
void printBinary(T number) {
    std::bitset<sizeof(T) * 8> binary(number);
    std::cout << binary << std::endl;
}

class Compactor{
public:
    struct NodeHuf  {   short int left, right;  };  //2 bytes
    NodeHuf *tree;
    int num_char;
    long int num_bytes;
public:
    Compactor() : num_bytes(0) {};
    
    //void build_codes(int index, int *code = 0, int h = 0);
    virtual void store(std::string out_file) = 0;
    void printHuf(int i, int space = 0);
    void printHuf();
};


#endif