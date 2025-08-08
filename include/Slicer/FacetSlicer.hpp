#ifndef FACET_SLICER_HPP
#define FACET_SLICER_HPP

#include "BaseSlicer.hpp"

namespace Slicer {

	class FacetSlicer: public BaseSlicer{
		
		public:
			FacetSlicer(const std::shared_ptr<Geometry::GeometryModel> geometry_model): BaseSlicer(geometry_model) {};

			~FacetSlicer() = default;
	};

}

#endif
