#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <iostream>
#include <fstream>
#include "heap.hpp"

class Compressor{
    struct NodeHuf  {   short int left, right;  };  //2 bytes

    struct NodeHeap{
        short int index;
        int weight;
    
        bool operator < ( NodeHeap &node) {
            return weight < node.weight;
        }
    };

    int occur[256];
    int num_char;
    long int num_bytes;
    NodeHuf *tree;
    MinHeap <NodeHeap> *heap;
public:

    Compressor();
    ~Compressor();
    void read_file(std::string in_file);
    void Huffman();
    void run();
    void store(std::string out_file);
};

#endif