#include "Parser/Parser.hpp"
#include "Parser/Factory.hpp"

int main(int argc, char** argv){
	
	// use boost and a dedicated module for input argument parsing later
	if (argc != 2){
		std::cerr << "Usage: " << argv[0] << "<filename>\n";
		return 1;
	}

	std::string filename = argv[1];

	auto parserFactory = std::make_unique<SlicingParser::Factory>();
	auto stlParser = parserFactory->createParser(filename);
	if (stlParser){
		stlParser->print();
		stlParser->readFile();
	}

	return 0;
}
