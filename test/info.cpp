#include<iostream>
#include<string>
#include<memory>
#include<mxl.hpp>

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "Requires one argumnet of mxl file..\n";
        exit(EXIT_FAILURE);
    }
    std::unique_ptr<mxl::MXL> parser(mxl::MXL::parseMXL(argv[1]));
    if(parser) {
        while(1) {
            std::cout << "Enter Option: (1 Update (2 Display (3 Quit&Save: ";
            std::string input_val;
            std::cin >> input_val;
            if(input_val == "1") {
                std::string first,last;
                std::cout << "Enter name: ";
                std::cin >> first >> last;
                parser->table("User", "First") = first;
                parser->table("User", "Last") = last;
            } else if(input_val == "2") {
                std::cout << "Info: " << parser->table("User", "First") << " " << parser->table("User", "Last") << "\n";
            } else if(input_val == "3") {
                std::cout << "Quiting...\n";
                break;
            }
            else {
                std::cerr << "Incorrect option...\n";
            }
        }
        parser->sortedWriteToFile(argv[1]);
    } else {
        std::cout << "Could not open: " << argv[1] << " ...\n";
    }
    return EXIT_SUCCESS;
}
