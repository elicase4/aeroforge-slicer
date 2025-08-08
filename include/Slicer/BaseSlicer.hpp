#ifndef BASE_SLICER_HPP
#define BASE_SLICER_HPP

// standard libraries
#include <iostream>
#include <memory>
#include <vector>

// internal libraries
#include "Geometry/Model.hpp"

namespace Slicer {

	// complex structures
	template <typename T>
	struct SlicingPlane {std::vector<T> contour; };
	
	template <typename T>
	class BaseSlicer{

		public:

			BaseSlicer(const std::shared_ptr<Geometry::GeometryModel<T>> geometry_model): _geometry_model(geometry_model) {};

			virtual ~BaseSlicer() = default;
			
			virtual void sliceGeometry() = 0;
	
		protected:
			
			std::shared_ptr<Geometry::GeometryModel<T>> _geometry_model;
			std::vector<SlicingPlane<T>> slicing_contours;
	};

}

#endif
