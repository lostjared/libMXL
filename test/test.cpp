#include<iostream>
#include<sstream>
#include<fstream>
#include<memory>
#include<string>
#include<mxl.hpp>

int main() {
    std::unique_ptr<mxl::MXL> parser(mxl::MXL::parseMXL("test.mxl"));
    if(parser) {
        int value = atoi(parser->table("Counter", "Ran").c_str());
        ++value;
        std::cout << "Program ran: " << value << " times..\n";
        std::ostringstream stream;
        stream << value;
        parser->table("Counter", "Ran") = stream.str();
        parser->sortedWriteToFile("test.mxl");
    } else {
        std::cerr << "Could not open test.mxl is it in this directory?...\n Creating file..\n";
        std::fstream file;
        file.open("test.mxl", std::ios::out);
        if(!file.is_open()) {
            std::cerr << "Could not open file..\n";
            exit(EXIT_FAILURE);
        }
        file << "Counter =>\nRan = \"0\"\n\n";
        file.close();
    }
    return 0;
}
