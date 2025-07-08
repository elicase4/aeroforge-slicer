// standard libraries
#include <cstdint>
#include <iostream>
#include <vector>

namespace Geometry{
	
	// Complex structures
	struct Facet { std::uint32_t normal, v1, v2, v3; };
	struct NURBSPatch {}; // fill later for STEP

	// Main container
	struct GeometryModel{
		
		// primitive vector containers
		std::vector<float*> vertices;
		std::vector<float*> normals;
		
		// complex vector id containers
		std::vector<Facet> facets;
		std::vector<NURBSPatch> nurbsPatches;
		
		// size functions
		std::size_t vertexCount() const {return vertices.size(); }
		std::size_t normalsCount() const {return normals.size(); }
		std::size_t facetsCount() const {return facets.size(); }
		std::size_t nurbsPatchesCount() const {return nurbsPatches.size(); }
	};

	// debug print functions
	void printFacet(const GeometryModel& model);

}
