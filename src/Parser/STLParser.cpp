#include "Parser/STLParser.hpp"

void SlicingParser::STLParser::print() const{
	std::cout << "Using the STL Parser.\n";
}

void SlicingParser::STLParser::readFile(){

	// open the input file assuming it is in binary format
	auto input = SlicingParser::STLParser::open_binary_file();
	
	// initialize varibles used for parsing
	char header[81];
	unsigned int num_facets;
	
	// Read the header
	read_binary_array<char>(input, header, 80);
	header[80] = '\0';
	
	// Read the number of facets
	read_binary_value<unsigned int>(input, &num_facets);
	_facet_list.reserve(num_facets);

	// loop over facets and store them
	for (size_t i = 0; i < num_facets; ++i){
		Facet f{};

		read_binary_array<float>(input, f.normal_vector, 3);
		read_binary_array<float>(input, f.vertex1, 3);
		read_binary_array<float>(input, f.vertex2, 3);
		read_binary_array<float>(input, f.vertex3, 3);

		_facet_list.emplace_back(f);

	}
}
