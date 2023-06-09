#include "compressor.hpp"

Compressor :: Compressor() : num_bytes(0) {
    for (int *i = occur, *end = occur + 256; i != end; ++i)
        *i = 0;        
}

Compressor :: ~Compressor() {}

void Compressor:: read_file(std::string in_file){
    std::ifstream file(in_file.data(), std::ios_base::binary);

    if(!file){
        throw std::ifstream::failure("Erro ao abrir arquivo.");
    }

    unsigned char byte;
    
    while (true){
        byte = file.get();

        if (file.eof())     break;
        
        ++occur[byte];
        ++num_bytes;
    }

    for (int *i = occur, *end = occur + 256; i != end; ++i)
        if (*i != 0)
            ++num_char;
    
    heap = new MinHeap <NodeHeap>(num_char);
    tree = new NodeHuf[2*num_char - 1];
}

void Compressor :: Huffman(){
    int ind = num_char;
    while ((*heap).number_elements() > 1){
        NodeHeap n1 = (*heap).extractMin();
        NodeHeap n2 = (*heap).extractMin();
        
        tree[ind].left  = n1.index;
        tree[ind].right = n2.index;
        (*heap).insertElement((NodeHeap){ind, n1.weight + n2.weight});
        ++ind;
    }
}

void Compressor :: run(){
    for (short int i = 0, j = 0; i < 256; ++i){
        if (occur[i] != 0){
            tree[j].left = i;
            (*heap).setElement(j, (NodeHeap){j, occur[i]});
            ++j;
        }
    }

    for (int i = (*heap).number_elements() / 2 - 1; i >= 0; ++i )
        (*heap).heapify(i);
    
    Huffman();
}

void Compressor :: store(std::string out_file){
    std::ofstream file(out_file.data(), std::ios_base::binary);

    if(!file){
        throw std::ifstream::failure("Erro ao abrir arquivo.");
    }

    file << num_char;
    file.write((char *) tree, 2*num_char-1 * sizeof(NodeHuf));
    file << num_bytes;
    
}

