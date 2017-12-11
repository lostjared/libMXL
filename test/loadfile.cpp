#include<iostream>
#include<string>
#include<mxl.hpp>


int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "Error requires one argument.\n";
        exit(EXIT_FAILURE);
    }
    mxl::MXL parser;
    if(!parser.loadFromFile(argv[1])) {
        std::cerr << "Error loading file: " << argv[1] << "\n";
        exit(EXIT_FAILURE);
    }
    parser.echoTokens();
    return 0;
}
