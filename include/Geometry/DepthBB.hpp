#ifndef COORDIANTE_3D_HPP
#define COORDINATE_3D_HPP

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <vector>
#include <unordered_map>

#include "Geometry/Model.hpp"

namespace Geometry{

	struct DepthBB{
		
		double h_min, h_max, rel_tolerance;

		bool is_equal_relative_tolerance(const double a, const double b, const double tol) const {
			if (std::isinf(a) || std::isinf(b) || std::isnan(a) || std::isnan(b)){
				return false;
			}
			return std::fabs(a-b) <= (rel_tolerance * std::max(std::fabs(a), std::fabs(b)));
		}

		bool operator==(const DepthBB& other) const {
			return (is_equal_relative_tolerance(h_min, other.h_min, rel_tolerance) 
					&& is_equal_relative_tolerance(h_max, other.h_max, rel_tolerance));
		}
	
	};
}

namespace std {
	
	template <>
	struct hash<Geometry::DepthBB> {
		size_t operator()(const Geometry::Coordinate3D& coord) const {
			size_t h1 = std::hash<double>()(coord.x);
			size_t h2 = std::hash<double>()(coord.y);
			size_t h3 = std::hash<double>()(coord.z);
			return (h1 ^ (h2 << 1)) ^ (h3 << 2);
		}
	};
}

namespace Geometry{
	
	template <typename T>
	Coordinate3D toCoordinate3D(const T* coord, const T hash_coord_tol = 1e-5f){ 
		Coordinate3D coord3d = {(double) coord[0], (double) coord[1], (double) coord[2], (double) hash_coord_tol};
		return coord3d;
	}
	
	template <typename T>
	uint32_t addCoordinate3D(T* coord, std::vector<std::array<T, NUM_SPATIAL_DIMS>>& model_vector, std::unordered_map<Coordinate3D, uint32_t>& model_map, const T hash_coord_tol = static_cast<T>(1e-5)){
		
		Coordinate3D coord3d = toCoordinate3D<T>(coord, hash_coord_tol);
		
		auto result = model_map.try_emplace(coord3d, model_vector.size());
		
		if (result.second){
			std::array<T, NUM_SPATIAL_DIMS> coord_array = {coord[0], coord[1], coord[2]}; 
			model_vector.push_back(coord_array);
		}
		
		return result.first->second;
	}
}

#endif
