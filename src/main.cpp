#include <iostream>
#include <string>
#include "Compactor.hpp"
#include "compressor.hpp"
#include "decompressor.hpp"

using namespace std;

int main(int argc, char **argv){

    if (argc < 3 || argc > 5){
        return EXIT_FAILURE;
    }

    string input_file(argv[2]);
    string out_file("out.ck");
    if (argc >= 5)
        out_file.assign(argv[3]);

    string type(argv[1]);

    try{
        if (type.find("-c") != std::string::npos ){
            Compressor comp;
            comp.read_file(input_file);
            comp.run();
            //comp.printHuf((2 * comp.num_char) - 2);
            comp.store(out_file);
        }
        else if (type.find("-d") != std::string::npos){
            out_file.assign("dec");
            Decompressor dec;
            dec.decod(input_file, out_file);
        }
        else{
            //TODO
            return EXIT_FAILURE;
        }
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    

    return EXIT_SUCCESS;
}



