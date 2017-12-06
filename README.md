# libMXL

Simple tagging language use it like this:

Cateogry =>

"Key" = "value"

Width = "200"

Height = "400"

User =>

firstname = "Jared"

lastname = "Bruni"

Keys/Values can be accessed by adding project files (except main) and parsing the text with readSource("filename.mxl"); Then use

std::string value=getValue("Category", "Width");

value would hold "200"

Or use the the wrapper class like htis

mxl::MXL *parser = mxl::MXL::parseMXL("code.mxl");

don't forget to delete parser when done or use a smart pointer


