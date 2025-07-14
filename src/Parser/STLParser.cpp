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

		std::cout << "===============================================================\nv1: [ " << v1[0] << ", " << v1[1] << ", " << v1[2] << " ]" << "\n";
		std::cout << "v2: [ " << v2[0] << ", " << v2[1] << ", " << v2[2] << " ]" << "\n";
		std::cout << "v3: [ " << v3[0] << ", " << v3[1] << ", " << v3[2] << " ]" << "\n";

		reader.readValue<unsigned short int>(&attribute_byte_count);
		
		/*
		_geometry_model->vertices.push_back(v1);
		_geometry_model->vertices.push_back(v2);
		_geometry_model->vertices.push_back(v3);
		_geometry_model->normals.push_back(normal);
		auto vertex_idx = static_cast<std::uint32_t>(i*NUM_SPATIAL_DIMS);
		auto normal_idx = static_cast<std::uint32_t>(i);
		_geometry_model->facets.push_back({normal_idx, vertex_idx, vertex_idx+1, vertex_idx+2});
		*/
		
		uint32_t v1_idx = Geometry::addCoordinate3D<float>(v1, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t v2_idx = Geometry::addCoordinate3D<float>(v2, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t v3_idx = Geometry::addCoordinate3D<float>(v3, _geometry_model->vertices, vertices_map, _hash_coord_tol);
		uint32_t normal_idx = Geometry::addCoordinate3D<float>(normal, _geometry_model->normals, normals_map, _hash_coord_tol);
		
		std::cout << "facet number: " << i << " vertex id\n================\n[v1_idx, v2_idx, v3_idx]: [" << v1_idx << ", " << v2_idx << ", " << v3_idx << "].\n";
		std::cout << "vertices_map:\n";
		for (const auto& pair : vertices_map) {
			std::cout << "======\nvertex idx: " << pair.second << "\n";
			std::cout << "vertex val: [ " << _geometry_model->vertices[pair.second][0] << ", " << _geometry_model->vertices[pair.second][1] << ", " << _geometry_model->vertices[pair.second][2] << " ]" << "\n";
		}

		_geometry_model->facets.push_back({normal_idx, v1_idx, v2_idx, v3_idx});

	}
	
	Geometry::printFacetSummary(_geometry_model);
}
