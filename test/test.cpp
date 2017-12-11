#include<iostream>
#include<sstream>
#include<fstream>
#include<memory>
#include<string>
#include<mxl.hpp>

int main() {
    std::unique_ptr<mxl::MXL> parser(mxl::MXL::parseMXL("test.mxl"));
    if(parser) {
        long value = parser->getTableInteger("Counter", "Ran");
        ++value;
        std::cout << "Program ran: " << value << " times..\n";
        parser->setTableValue("Counter", "Ran", value);
        parser->sortedWriteToFile("test.mxl");
    } else {
        std::cerr << "Could not open test.mxl is it in this directory?...\n Creating file..\n";
        mxl::MXL obj;
        obj.setTableValue("Counter", "Ran", "0");
        obj.sortedWriteToFile("test.mxl");
    }
    return 0;
}
