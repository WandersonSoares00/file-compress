#include <iostream>
#include "inc/compactor.hpp"

void Compactor :: printHuf(int i, int space){

    if (i >= num_char)
        printHuf(tree[i].right, space+1);
    
    std::cout << '\n';
    for (int i = 0; i < space; ++i)
        std::cout << "     ";
    if (i < num_char){
        if (tree[i].left == '\n')
            std::cout << "\\n\n";
        else
            std::cout << (unsigned char) tree[i].left << '\n';
    }
    else
        std::cout << "*\n";

    if (i >= num_char)
        printHuf(tree[i].left, space+1);
}

/*
void Compactor :: printHuf(){
    for(int i = 0; i < 2*num_char - 1; ++i){
        std::cout << tree[i].left << "|" << tree[i].right << " ";
    }
    std::cout << "\n";
}
*/
