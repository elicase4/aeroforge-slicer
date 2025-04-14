#include "SlicingParser.hpp"

void SlicingParser::STLParser::print(){
	std::cout << "Using the STL Parser.\n";
}

std::unique_ptr<SlicingParser::Parser> SlicingParser::Factory::create(std::string format){
	if (format == "STL"){
		return std::make_unique<SlicingParser::STLParser>();
	}

	return nullptr;
}
