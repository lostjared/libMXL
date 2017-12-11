#include<iostream>
#include<string>
#include<mxl.hpp>


int main(int argc, char **argv) {
    
    if(argc != 2) {
        std::cerr << "Requires one argument, of the MXL file..\n";
        exit(EXIT_FAILURE);
    }
    
    mxl::MXL parser;
    if(!parser.loadFromFile(argv[1])) {
        std::cerr << "Error loading file: " << argv[1] << "\n";
        exit(EXIT_FAILURE);
    }
    
    for(auto start=parser.begin_mxl(); start != parser.end_mxl(); start++) {
        std::cout << "Tag: " << start->first << "\n";
        for(auto in = parser.begin_sub(start->first); in != parser.end_sub(start->first); in++) {
            std::cout << "\t" << in->first << " := " << in->second << "\n";
        }
    }

    return 0;
}
