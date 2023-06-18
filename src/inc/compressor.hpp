#ifndef COMPRESSOR_HPP
#define COMPRESSOR_HPP
#include <fstream>
#include <string>
#include <unordered_map>

#include "heap.hpp"
#include "Compactor.hpp"

class Compressor : private Compactor {       // Deixar privado
    struct NodeHeap{
        short int index;
        int weight;
        
        NodeHeap(){}
        NodeHeap(short int index, int weight){
            this -> index = index;
            this -> weight = weight;
        }

        bool operator < ( NodeHeap &node) {
            return weight < node.weight;
        }
    };

    MinHeap <NodeHeap> *heap;
    int occur[256];
    std::string in_file;
    std::unordered_map<unsigned char, std::string> codes;

public:
    Compressor();
    void run(std::string in_file, std::string out_file) override;
private:
    void read_file(std::ifstream& file) override;
    void build_codes(int index, std::string code, int h = 0);
    void Huffman();
};

#endif
