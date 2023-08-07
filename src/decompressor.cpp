#include "inc/decompressor.hpp"
#include <fstream>

Decompressor :: Decompressor(){}

void Decompressor :: read_file(std::ifstream& file){
    
    file.read((char*) &num_char, sizeof(num_char) );
    
    if (file.eof())
        return;
    
    if (num_char == 0)
        return;
    
    if (num_char >= 2){
        tree = new NodeHuf[2*num_char - 1];
        
        file.read((char *) tree, ((2*num_char) - 1) * sizeof(NodeHuf));
    }

    else if (num_char == 1)
        file.read((char*) &single_char, sizeof(single_char));
    
    file.read((char*) &num_bytes, sizeof(num_bytes));
}


void Decompressor :: run(std::string in_file, std::string out_file){
    std::ifstream ifile (in_file, std::ios_base::binary );
    std::ofstream ofile (out_file, std::ios::out );

    if (!ifile or !ofile)
        throw std::ifstream::failure("Erro ao abrir arquivo");
    
    this -> read_file(ifile);

    if (num_char == 0)      return;
    
    if (num_char == 1){
        while (num_bytes > 0){
            ofile.write((char*) &single_char, sizeof(single_char));
            --num_bytes;
        }
        return;
    }
    
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
            ofile.write((char*) &tree[node].left, sizeof(byte));
            node = 2 * num_char - 2;
            --num_bytes;
        }
    }
    
}
