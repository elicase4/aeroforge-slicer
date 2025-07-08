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

namespace Parser {

	class BaseParser{
		public:
			BaseParser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::native): _filename(filename), _file_endian(file_endian) {};
			
			virtual ~BaseParser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;

			auto getGeometryModel() { return std::make_unique<Geometry::GeometryModel>(_geometry_model); };
		
		protected:
			std::string _filename;
			boost::endian::order _file_endian;
			Geometry::GeometryModel _geometry_model;
	};

}

#endif
