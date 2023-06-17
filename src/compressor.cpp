#include "compressor.hpp"
#include <cstdlib>
#include <sstream>
#include <iomanip>

Compressor :: Compressor(){
    //num_bytes = 0;
    num_char = 0;
    for (int *i = occur, *end = occur + 256; i != end; ++i)
        *i = 0;
}

//Compressor :: ~Compressor() {}

void Compressor:: read_file(std::string file_name){
    in_file.assign(file_name);
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

    tree = new NodeHuf[2*num_char - 1];
}

void Compressor :: Huffman(){
    int ind = num_char;
    while ((*heap).number_elements() > 1){
        NodeHeap n1 = (*heap).extractMin();
        NodeHeap n2 = (*heap).extractMin();
        
        tree[ind].left  = n1.index;
        tree[ind].right = n2.index;
        NodeHeap node(ind, n1.weight + n2.weight);
        (*heap).insertElement(node);
        ++ind;
    }
}

void Compressor :: run(){
    NodeHeap *temp = new NodeHeap[num_char];

    for (short int i = 0, j = 0; i < 256; ++i){
        if (occur[i] != 0){
            tree[j].left = i;
            NodeHeap node(j, occur[i]);
            temp[j] = node;
            ++j;
        }
    }

    heap = new MinHeap(temp, num_char);
    delete[] temp;
    //for (int i = (*heap).number_elements() / 2 - 1; i >= 0; ++i )
    //    (*heap).heapify(i);

    Huffman();


}

void Compressor :: build_codes(int index, std::string code, int h) {
    if ( index < num_char ){
        code[h] = '-';
        codes[tree[index].left] = code;
        return;
    }

    if (index >= num_char){
        code[h] = '0';
        build_codes(tree[index].left, code, h+1);
        code[h] = '1';
        build_codes(tree[index].right, code, h+1);
    }
}

void Compressor :: store(std::string out_file){
    std::ofstream file_out(out_file.data(), std::ios_base::binary);
    std::ifstream file_in  (in_file.data(), std::ios_base::binary);
    
    unsigned char byte;

    if(!file_out or !file_in){
        throw std::ifstream::failure("Erro ao processar arquivo.");
    }

    // raiz na última posição
    std::string code(256, '0');
    build_codes(2 * num_char - 2, code);
    
    /*
    for (const auto& pair : codes) 
        if (pair.first == '\n')
            std::cout << "Chave: \\n, Valor: " << pair.second.substr(0, 5) << std::endl;
        else
            std::cout << "Chave: " << pair.first << ", Valor: " << pair.second.substr(0, 5) << std::endl;
    */

    if (num_char == 0)
        return;
    if (num_char == 1){
        file_out << num_char;
        byte = file_in.get();
        file_out << byte;
        file_out << occur[byte];
        return;
    }


    file_out.write((char*) &num_char, sizeof(num_char));
    file_out.write((char *) tree, ((2*num_char) - 1) * sizeof(NodeHuf));
    file_out.write((char*) &num_bytes, sizeof(num_bytes));
    
    /*
    std::ostringstream oss;
    oss << "cat " << out_file;
    std::string command = oss.str();
    system(command.c_str());
    */
    
    //std::cout << "\n\n";
    unsigned char buff = 0;
    std::string code_byte;
    int bits = 0;
    
    while (true){
        byte = file_in.get();

        if (file_in.eof())     break;
        
        code_byte = codes[byte];
        
        for (int i = 0; code_byte[i] != '-'; ++i){
            buff <<= 1;
            if (code_byte[i] == '1')        buff |= 1;
            //else                            buff &= 0b11111110;
            
            ++bits;
            if (bits == 8){
                file_out.write( (char *) &buff, sizeof(buff));
                bits = 0;
                buff = 0;
            }
        }
    }

    if (bits > 0){
        buff <<= (8 - bits);
        file_out.write( (char *) &buff, sizeof(buff));
    }

}


