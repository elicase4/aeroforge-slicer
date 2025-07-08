#include "Geometry/GeometryModel.hpp"

void Geometry::printFacet(Geometry::GeometryModel model){
	
	for (size_t i = 0; i < model.facetsCount(); i++){
		std::cout << "\n--------------------------------------------------\n";
		std::cout << "                  Facet " <<  i << " \n";
		
		auto facet = model.facets[i];
		
		for (int j = 0; j < 3; ++j){
			std::cout << "--------------------------------------------------\n";
			std::cout << "normal_vector[" << j << "] : " << model.normals[facet.normal][j] << "\n";
			std::cout << "vertex1[" << j << "] : " << model.vertices[facet.v1][j] << "\n";
			std::cout << "vertex2[" << j << "] : " << model.vertices[facet.v2][j] << "\n";
			std::cout << "vertex3[" << j << "] : " << model.vertices[facet.v3][j] << "\n";
		}

	}

}
