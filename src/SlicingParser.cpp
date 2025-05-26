#include "SlicingParser.hpp"

void SlicingParser::STLParser::print(){
	std::cout << "Using the STL Parser.\n";
}

void SlicingParser::STEPParser::print(){
	std::cout << "Using the STEP Parser.\n";
}

void SlicingParser::ThreeMFParser::print(){
	std::cout << "Using the 3MF Parser.\n";
}

std::unique_ptr<SlicingParser::Parser> SlicingParser::Factory::create(){
	
	//std::cout << "file format is: " << _file_format << ".\n";

	if (_file_format == "STL"){
		return std::make_unique<SlicingParser::STLParser>();
	}
	
	if (_file_format == "STEP"){
		return std::make_unique<SlicingParser::STEPParser>();
	}
	
	if (_file_format == "3MF"){
		return std::make_unique<SlicingParser::ThreeMFParser>();
	}

	return nullptr;
}

void SlicingParser::Factory::readFile(){
	
	size_t dot_position = _input_file.find_last_of('.');
	if ((dot_position != std::string::npos) && (dot_position + 1 < _input_file.length())){
		_file_format = _input_file.substr(dot_position + 1);
	} else {
		_file_format = "";
	}

}
