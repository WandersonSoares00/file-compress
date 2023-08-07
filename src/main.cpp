#include <iostream>
#include <string>
#include "inc/compressor.hpp"
#include "inc/decompressor.hpp"

#define PROGRAM_NAME "comp"

using namespace std;

void usage(int status){
    if (status != EXIT_SUCCESS){
        cerr << PROGRAM_NAME << ": Entrada inválida\n";
        cerr << "Tente \"" << PROGRAM_NAME << " --help\" para mais informações\n";
    }
    else{
        
         
        cout << "Uso: " << PROGRAM_NAME << " [OPÇÃO] [ARQUIVO]...\n";
        cout << "Compacta ou descompacta(se o arquivo for do tipo .dah) um ARQUIVO de acordo com OPÇÃO\n\n";
        cout << "-c, --compress\t   executa o programa em modo de compressão\n";
        cout << "-d, --decompress\t executa o programa em modo de descompressão\n";
        cout << "Exemplos de uso:\n";
        cout << "./" << PROGRAM_NAME << " -c arq1 arq2\t #comprime o arquivo arq1 no arquivo arq2\n";
        cout << "./" << PROGRAM_NAME << " -c arq1     \t #comprime o arquivo arq1 em um arquivo chamado out.dah\n";
    }

    exit(status);
}

int main(int argc, char **argv){

    if (argc < 2 || argc > 5)   usage(EXIT_FAILURE);
    
    string type(argv[1]);
    
    if (argc == 2 && type.find("-h") != std::string::npos)
        usage(EXIT_SUCCESS);
    
    string input_file(argv[2]);
    string out_file("out.dah");
    if (argc >= 5)
        out_file.assign(argv[3]);

    try{
        if (type.find("-c") != std::string::npos){
            Compressor comp;
            comp.run(input_file, out_file);
        }
        else if (type.find("-d") != std::string::npos){
            if (argc < 5)      out_file.assign("out");
            Decompressor dec;
            dec.run(input_file, out_file);
            //cout << "voltou\n";
        }
        else{
            usage(EXIT_FAILURE);
        }
    }
    catch(const std::exception& e){
        cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    

    return EXIT_SUCCESS;
}


