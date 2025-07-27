#include "Parser/STLParser.hpp"

void Parser::STLParser::print() const{
	std::cout << "Using the STL Parser.\n";
}

void Parser::STLParser::readFile(){
	if (_reader_format == "binary"){
		Parser::STLParser::readBinaryFile();
	} else if (_reader_format == "ascii"){
		Parser::STLParser::readAsciiFile();
	} else {
		std::cerr << "Error: Cannot open file with format: " << _reader_format << " using the STL Parser.\n";
		exit(1);
	}
}

void Parser::STLParser::readAsciiFile(){
	
	// open the input file in binary format
	auto reader = Reader::AsciiReader(_filename);
	reader.openFile();
	
	// initialize variables used for parsing
	std::string keyword;

	// Read the header
	reader.initializeLine();
	reader.readDummyLine();
	
	// unordered maps for vertices & normals
	std::unordered_map<Geometry::Coordinate3D, uint32_t> vertices_map;
	std::unordered_map<Geometry::Coordinate3D, uint32_t> normals_map;

	// loop over the facs and store them
	while (std::getline(reader.file_stream, reader.line)){

		reader.initializeLine();
		
		reader.readString(keyword, 1);

		//std::cout << "=======================\nkeyword: " << keyword << "\n";
		
		if (keyword == "facet"){
			
			float v1[NUM_SPATIAL_DIMS];
			float v2[NUM_SPATIAL_DIMS];
			float v3[NUM_SPATIAL_DIMS];
			float normal[NUM_SPATIAL_DIMS];
			unsigned int vertex_count = 0;
			
			reader.readString(keyword, 1);

			if (keyword == "normal"){
				reader.readArray<float>(normal, NUM_SPATIAL_DIMS);
			}

			reader.readString(keyword, 2);
			
			if (keyword == "outer loop"){
				
				while (keyword != "endloop"){
					
					reader.readString(keyword, 1);
					
					if (keyword == "vertex"){
						
						switch(vertex_count){
							case 1:
								reader.readArray<float>(v1, NUM_SPATIAL_DIMS);
								break;
							case 2:
								reader.readArray<float>(v2, NUM_SPATIAL_DIMS);
								break;
							case 3:
								reader.readArray<float>(v3, NUM_SPATIAL_DIMS);
								break;
							default:
								break;
						}
						
						vertex_count++;
					}
				
				}
			}
			
			reader.readString(keyword, 1);

			if (keyword == "endfacet"){
				uint32_t v1_idx = Geometry::addCoordinate3D<float>(v1, _geometry_model->vertices, vertices_map, _hash_coord_tol);
				uint32_t v2_idx = Geometry::addCoordinate3D<float>(v2, _geometry_model->vertices, vertices_map, _hash_coord_tol);
				uint32_t v3_idx = Geometry::addCoordinate3D<float>(v3, _geometry_model->vertices, vertices_map, _hash_coord_tol);
				uint32_t normal_idx = Geometry::addCoordinate3D<float>(normal, _geometry_model->normals, normals_map, _hash_coord_tol);
			
				_geometry_model->facets.push_back({normal_idx, v1_idx, v2_idx, v3_idx});
			}
		}
			
	}
	
	Geometry::printFacetSummary(_geometry_model);

}

void Parser::STLParser::readBinaryFile(){

	// open the input file in binary format
	auto reader = Reader::BinaryReader(_filename, _file_endian);
	reader.openFile();

	// initialize varibles used for parsing
	char header[STL_BINARY_HEADER_SIZE + 1];
	unsigned int num_facets;

	// Read the header
	reader.readArray<char>(header, STL_BINARY_HEADER_SIZE);
	header[STL_BINARY_HEADER_SIZE] = '\0';
	
	// Read the number of facets
	reader.readValue<unsigned int>(&num_facets);
	
	// reserve the maximum required space for the geometry model
	_geometry_model->vertices.reserve(num_facets*NUM_SPATIAL_DIMS);
	_geometry_model->normals.reserve(num_facets);
	_geometry_model->facets.reserve(num_facets);

	// unordered maps for vertices & normals
	std::unordered_map<Geometry::Coordinate3D, uint32_t> vertices_map;
	std::unordered_map<Geometry::Coordinate3D, uint32_t> normals_map;

	// dummy variable for attribute byte count
	unsigned short int attribute_byte_count;

	// loop over facets and store them
	for (size_t i = 0; i < num_facets; ++i){
		
		float v1[NUM_SPATIAL_DIMS];
		float v2[NUM_SPATIAL_DIMS];
		float v3[NUM_SPATIAL_DIMS];
		float normal[NUM_SPATIAL_DIMS];

		reader.readArray<float>(normal, NUM_SPATIAL_DIMS);
		reader.readArray<float>(v1, NUM_SPATIAL_DIMS);
		reader.readArray<float>(v2, NUM_SPATIAL_DIMS);
		reader.readArray<float>(v3, NUM_SPATIAL_DIMS);

		reader.readValue<unsigned short int>(&attribute_byte_count);
		
		uint32_t v1_idx = Geometry::addCoordinate3D<float>(v1, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t v2_idx = Geometry::addCoordinate3D<float>(v2, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t v3_idx = Geometry::addCoordinate3D<float>(v3, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t normal_idx = Geometry::addCoordinate3D<float>(normal, _geometry_model->normals, normals_map, _hash_coord_tol);
		
		_geometry_model->facets.push_back({normal_idx, v1_idx, v2_idx, v3_idx});

	}

	Geometry::printFacetSummary(_geometry_model);
}
