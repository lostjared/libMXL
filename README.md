# libMXL

Simple tagging language use it like this:

Cateogry =>

Key = "value"

Width = "200"

Height = "400"

User =>

firstname = "Jared"

lastname = "Bruni"

Use the the wrapper class like htis

mxl::MXL *parser = mxl::MXL::parseMXL("code.mxl");

don't forget to delete parser when done or use a smart pointer
See the example in test folder  to see how to use the MXL class.

Or use it like this:

mxl::MXL parser;

if(!parser.loadFromFile("test.mxl")) {

std::cout << "Failed to load!\n";

}

parser.echoTokens();

