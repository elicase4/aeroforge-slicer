#ifndef FACET_SLICER_HPP
#define FACET_SLICER_HPP

#include "BaseSlicer.hpp"

namespace Slicer {
	
	template <typename T>
	class FacetSlicer: public BaseSlicer<T> {
		
		public:
			FacetSlicer(const std::shared_ptr<Geometry::GeometryModel<T>> geometry_model): BaseSlicer<T>(geometry_model) {};

			~FacetSlicer() = default;

			void sliceGeometry();
	};

}

#endif
