#ifndef BASE_PARSER_HPP
#define BASE_PARSER_HPP

// standard libraries
#include <iostream>
#include <memory>
#include <string>

// boost libraries
#include <boost/endian/conversion.hpp>

// internal libraries
#include "Utils.hpp"
#include "Geometry/GeometryModel.hpp"

// global constants
const unsigned int NUM_SPATIAL_DIMS = 3;

namespace Parser {

	class BaseParser{
		public:
			BaseParser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::native): _filename(filename), _file_endian(file_endian), _geometry_model(std::make_shared<Geometry::GeometryModel>()) {};
			
			virtual ~BaseParser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;

			auto getGeometryModel() { return _geometry_model; };
		
		protected:
			std::string _filename;
			boost::endian::order _file_endian;
			std::shared_ptr<Geometry::GeometryModel> _geometry_model;
	};

}

#endif
