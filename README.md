# file-compress

This project is a file archiver made with the implementation of [Huffman's algorithm](https://en.wikipedia.org/wiki/Huffman_coding).

## Purpose

The intention of this project is understand how file archivers works.

## Results
The directory [instancias_teste](instancias_teste) contains files for testing. Below are the sizes of the files in bytes before and after compressing them: <br>

| Files   | Before | After  |
|---------|--------|--------|
| [file 1](instancias_teste/1_6_chars.txt)  |      4 |      4 |
| [file 2](instancias_teste/2_100_as.txt)  |      4 |      4 |
| [file 3](instancias_teste/3_vazio.txt)  |      0 |      0 |
| [file 4](instancias_teste/4_texto_6_mega.txt)  |   6340 |   3612 |
| [file 5](instancias_teste/5.pdf)  |    172 |    172 |
| [file 6](instancias_teste/6.bmp)  |  26784 |  26432 |
| [file 7](instancias_teste/7_linha_aleatoria_1_milhao.txt)  |    980 |    584 |
| [file 8](instancias_teste/8_linha_exponencial_ate_t.txt)  |   1024 |    260 |

## How to run?

### Dependencies
- GNU C++ Compiler ( g++ )
- GNU Make installed

On debian-based linux distributions, run `sudo apt install g++ make`

## Run
1. Clone the repository:
    `git clone https://github.com/WandersonSoares00/file-compress`
2. Change the directory:
    `cd file-compress`
3. Compile:
    `make all`
4. run in mode compressor or decompress
    The program can be executed using the following format: <br>
    *./comp [mode] FILE NAME_FILE_OUT* <br>
    where [mode] can be -c (for compressor) or -d (for decompressor).

## Licence information
This project is licensed under the GNU General Public License v3.0.

