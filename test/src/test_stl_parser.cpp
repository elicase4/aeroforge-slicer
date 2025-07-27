#include "Parser/Factory.hpp"
#include "Parser/BaseParser.hpp"

int main(int argc, char** argv){
	
	// use boost and a dedicated module for input argument parsing later
	if (argc != 3){
		std::cerr << "Usage: " << argv[0] << "<filename_binary>" << argv[1] << "<filename_ascii>" << argv[2] << "\n.";
		return 1;
	}

	std::string filename_binary = argv[1];
	std::string filename_ascii = argv[2];

	std::cout << "binary filename: " << filename_binary << " ascii filename: " << filename_ascii << " \n.";
	
	auto parserFactory = std::make_unique<Parser::Factory>();
	
	// test binary stl
	auto binary_parser = parserFactory->createParser(filename_binary, "binary");
	if (binary_parser){
		binary_parser->print();
		binary_parser->readFile();
	}
	
	// test ascii stl
	auto ascii_parser = parserFactory->createParser(filename_ascii, "ascii");
	if (ascii_parser){
		ascii_parser->print();
		ascii_parser->readFile();
	}

	return 0;
}
