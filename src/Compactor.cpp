#include <iostream>
#include "Compactor.hpp"

/*
void Compactor :: build_codes(int index, int *codes, int h) {
    if ( index < num_char ){
        //char key[8];
        //code[h+1] = '\0';
        //strcpy(key, code);
        //unsigned char mask = (1 << (h + 1)) - 1;
        
        // bit 1 mais à direita servindo como um delimitador do código
        code |= (1 << h);
        codes[tree[index].left] = code;
        return;
    }

    if (index >= num_char){
        //code |= (0 << index);
        code <<= 1;
        build_codes(tree[index].left, code, h+1);
        //code |= (1 << index);
        code |= 1;
        build_codes(tree[index].right, code, h+1);
    }
}*/

void Compactor :: printHuf(int i, int space){

    if (i >= num_char)
        printHuf(tree[i].right, space+1);
    
    std::cout << '\n';
    for (int i = 0; i < space; ++i)
        std::cout << "     ";
    if (i < num_char){
        if (tree[i].left == '\n')
            std::cout << "\\n" << '\n';
        else
            std::cout << (unsigned char) tree[i].left << '\n';
    }
    else
        std::cout << "*\n";

    if (i >= num_char)
        printHuf(tree[i].left, space+1);
}

void Compactor :: printHuf(){
    for(int i = 0; i < 2*num_char - 1; ++i){
        std::cout << tree[i].left << "|" << tree[i].right << " ";
    }
    std::cout << "\n";
}
