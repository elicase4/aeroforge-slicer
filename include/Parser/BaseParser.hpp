#ifndef BASE_PARSER_HPP
#define BASE_PARSER_HPP

// standard libraries
#include <iostream>
#include <memory>
#include <string>

// boost libraries
#include <boost/algorithm/string.hpp>
#include <boost/endian/conversion.hpp>

// internal libraries
#include "Geometry/Model.hpp"
#include "Geometry/ObjectKey.hpp"

namespace Parser {

	class BaseParser{
		public:
			BaseParser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::native, const float hash_coord_tol = 1e-5f): _filename(filename), _file_endian(file_endian), _hash_coord_tol(hash_coord_tol), _geometry_model(std::make_shared<Geometry::GeometryModel>()) {};
			
			virtual ~BaseParser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;

			auto getGeometryModel() { return _geometry_model; };
			
		protected:
			
			std::string _filename;
			boost::endian::order _file_endian;
			float _hash_coord_tol;
			std::shared_ptr<Geometry::GeometryModel> _geometry_model;
	};

}

#endif
