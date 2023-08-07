#ifndef COMPACTOR_HPP
#define COMPACTOR_HPP

#include "string"
#include <fstream>

class Compactor{
public:
    struct NodeHuf  {   short int left, right;  };  //2 bytes
    NodeHuf *tree;
    int num_char;
    long int num_bytes;

    Compactor() : num_bytes(0) {};
    virtual void read_file(std::ifstream& file) = 0;
    virtual void run(std::string in_file, std::string out_file) = 0;
    void printHuf(int i, int space = 0);
};


#endif