#include "Parser/STLParser.hpp"

void Parser::STLParser::print() const{
	std::cout << "Using the STL Parser.\n";
}

void Parser::STLParser::readFile(){

	// open the input file assuming it is in binary format, add ascii later if wanted
	auto reader = Parser::BinaryReader(_filename, _file_endian);
	reader.openFile();

	// initialize varibles used for parsing
	char header[STL_BINARY_HEADER_SIZE + 1];
	unsigned int num_facets;

	// Read the header
	reader.readArray<char>(header, STL_BINARY_HEADER_SIZE);
	header[STL_BINARY_HEADER_SIZE] = '\0';
	
	// Read the number of facets
	reader.readValue<unsigned int>(&num_facets);
	
	// reserve space for the geometry model
	_geometry_model->vertices.reserve(num_facets*3);
	_geometry_model->normals.reserve(num_facets);
	_geometry_model->facets.reserve(num_facets);

	// dummy variable for attribute byte count
	unsigned short int attribute_byte_count;

	// loop over facets and store them
	for (size_t i = 0; i < num_facets; ++i){
		
		float v1[3];
		float v2[3];
		float v3[3];
		float normal[3];

		reader.readArray<float>(normal, 3);
		reader.readArray<float>(v1, 3);
		reader.readArray<float>(v2, 3);
		reader.readArray<float>(v3, 3);

		reader.readValue<unsigned short int>(&attribute_byte_count);
		
		// implement non-duplicated vertices
		_geometry_model->vertices.push_back(v1);
		_geometry_model->vertices.push_back(v2);
		_geometry_model->vertices.push_back(v3);
		_geometry_model->normals.push_back(normal);
		
		auto vertex_idx = static_cast<std::uint32_t>(i)*3;
		auto normal_idx = static_cast<std::uint32_t>(i);
		_geometry_model->facets.push_back({normal_idx, vertex_idx, vertex_idx+1, vertex_idx+2});
		
		Geometry::printFacet(_geometry_model);
	}
}
