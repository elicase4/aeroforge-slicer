#include "Parser/STLParser.hpp"

void SlicingParser::STLParser::print() const{
	std::cout << "Using the STL Parser.\n";
}

void SlicingParser::STLParser::readFile(){

	// open the input file assuming it is in binary format
	auto reader = SlicingParser::BinaryReader(_filename, _file_endian);
	reader.openFile();

	// initialize varibles used for parsing
	char header[STL_BINARY_HEADER_SIZE + 1];
	unsigned int num_facets;
	
	// Read the header
	reader.readArray<char>(header, STL_BINARY_HEADER_SIZE);
	header[STL_BINARY_HEADER_SIZE] = '\0';
	
	// Read the number of facets
	reader.readValue<unsigned int>(&num_facets);
	_facet_list.reserve(num_facets);

	// loop over facets and store them
	for (size_t i = 0; i < num_facets; ++i){
		Facet f{};

		reader.readArray<float>(f.normal_vector, 3);
		reader.readArray<float>(f.vertex1, 3);
		reader.readArray<float>(f.vertex2, 3);
		reader.readArray<float>(f.vertex3, 3);
		
		_facet_list.emplace_back(f);
		
		printFacet(f, i);
	}
}

void SlicingParser::STLParser::printFacet(Facet f, int facet_num){
	std::cout << "\n--------------------------------------------------\n";
	std::cout << "                  Facet " << facet_num << " \n";
	for (int j = 0; j < 3; ++j){
		std::cout << "--------------------------------------------------\n";
		std::cout << "normal_vector[" << j << "] : " << f.normal_vector[j] << "\n";
		std::cout << "vertex1[" << j << "] : " << f.vertex1[j] << "\n";
		std::cout << "vertex2[" << j << "] : " << f.vertex2[j] << "\n";
		std::cout << "vertex3[" << j << "] : " << f.vertex3[j] << "\n";
	}
}
