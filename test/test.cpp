#include<iostream>
#include<sstream>
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
        std::cerr << "Could not open test.mxl..\n";
    }
    return 0;
}
