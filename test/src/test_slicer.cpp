#include "SlicingParser.hpp"

int main(int argc, char** argv){
	
	auto parserFactory = std::make_unique<SlicingParser::Factory>();
	std::unique_ptr<SlicingParser::Parser> stlParser = parserFactory->create("STL");
	stlParser->print();

	return 0;
}
