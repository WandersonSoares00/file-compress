#include "inc/decompressor.hpp"
#include <fstream>

Decompressor :: Decompressor(){}

void Decompressor :: read_file(std::ifstream& file){
    
    file.read((char*) &num_char, sizeof(num_char) );
    
    if (file.eof())
        return;
    
    if (num_char == 1)
        return; //TODO

    tree = new NodeHuf[2*num_char - 1];
    
    file.read((char *) tree, ((2*num_char) - 1) * sizeof(NodeHuf));    

    file.read((char*) &num_bytes, sizeof(num_bytes));
}

/*
void Decompressor :: decod(std::string in_file, std::string out_file){
    std::ifstream ifile (in_file, std::ios_base::binary );
    std::ofstream ofile (out_file, std::ios::out );

    if (!ifile or !ofile)
        throw std::ifstream::failure("Erro ao abrir arquivo.");
    
    //printHuf((2*num_char)-2);
    
    unsigned char byte;
    int bits = 0;
    short int node = 2 * num_char - 2;

    while (num_bytes > 0){
        if (bits == 0){
            byte = ifile.get();
            bits = 8;
        }

        if (byte & 0b10000000)
            node = tree[node].right;
        else
            node = tree[node].left;
        
        byte <<= 1;
        --bits;

        if (node < num_char){
            //std::cout << (unsigned char)tree[node].left;
            ofile.write((char*) &tree[node].left, sizeof(byte));
            node = 2 * num_char - 2;
            --num_bytes;
        }
    }
    
}
*/

void Decompressor :: run(std::string in_file, std::string out_file){
    std::ifstream ifile (in_file, std::ios_base::binary );
    std::ofstream ofile (out_file, std::ios::out );

    if (!ifile or !ofile)
        throw std::ifstream::failure("Erro ao abrir arquivo.");
    
    this -> read_file(ifile);

    //printHuf((2*num_char)-2);
    
    unsigned char byte;
    int bits = 0;
    short int node = 2 * num_char - 2;

    while (num_bytes > 0){
        if (bits == 0){
            byte = ifile.get();
            bits = 8;
        }

        if (byte & 0b10000000)
            node = tree[node].right;
        else
            node = tree[node].left;
        
        byte <<= 1;
        --bits;

        if (node < num_char){
            //std::cout << (unsigned char)tree[node].left;
            ofile.write((char*) &tree[node].left, sizeof(byte));
            node = 2 * num_char - 2;
            --num_bytes;
        }
    }
    
}
