#ifndef MODEL_HPP
#define MODEL_HPP

// standard libraries
#include <array>
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

const unsigned int NUM_SPATIAL_DIMS = 3;

namespace Geometry{
	
	// Complex structures
	struct Facet { std::uint32_t normal, v1, v2, v3; };
	struct NURBSPatch {}; // fill later for STEP

	// Main container
	template <typename T>
	struct GeometryModel{
		
		// primitive vector containers
		std::vector<std::array<T, NUM_SPATIAL_DIMS>> vertices;
		std::vector<std::array<T, NUM_SPATIAL_DIMS>> normals;
		
		// complex vector id containers
		std::vector<Facet> facets;
		std::vector<NURBSPatch> nurbsPatches;
		
		// size functions
		std::size_t vertexCount() const {return vertices.size(); }
		std::size_t normalsCount() const {return normals.size(); }
		std::size_t facetsCount() const {return facets.size(); }
		std::size_t nurbsPatchesCount() const {return nurbsPatches.size(); }
	};

	// print functions
	template <typename T>
	void printFacetSummary(const std::shared_ptr<GeometryModel<T>> model){
		
		for (size_t i = 0; i < model->facetsCount(); i++){
			std::cout << "\n--------------------------------------------------\n";
			std::cout << "                  Facet " <<  i << " \n";

			auto facet = model->facets[i];

			for (int j = 0; j < 3; ++j){
				std::cout << "--------------------------------------------------\n";
				std::cout << "normal_vector[" << j << "] : " << model->normals[facet.normal][j] << "\n";
				std::cout << "vertex1[" << j << "] : " << model->vertices[facet.v1][j] << "\n";
				std::cout << "vertex2[" << j << "] : " << model->vertices[facet.v2][j] << "\n";
				std::cout << "vertex3[" << j << "] : " << model->vertices[facet.v3][j] << "\n";
			}

		}

		std::cout << "\nFacet created using " << model->vertexCount() << " vertices and " << model->normalsCount() << " normals.\n";

	};

}

#endif
