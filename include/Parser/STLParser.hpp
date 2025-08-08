#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "BaseParser.hpp"
#include "Reader/BinaryReader.hpp"
#include "Reader/AsciiReader.hpp"

const size_t STL_BINARY_HEADER_SIZE = 80;

namespace Parser {

	class STLParser: public BaseParser {
		public:
			
			STLParser(const std::string& filename, const boost::endian::order file_endian, const float hash_coord_tol, const std::string reader_format = "binary"): BaseParser(filename, file_endian, hash_coord_tol), _reader_format(reader_format), _geometry_model(std::make_shared<Geometry::GeometryModel<float>>()) {};
			
			~STLParser() = default;
			
			void print() const override;

			void readFile() override;

			auto getGeometryModel() { return _geometry_model; };

		private:
			
			std::string _reader_format;
			std::shared_ptr<Geometry::GeometryModel<float>> _geometry_model;
			
			void readBinaryFile();
			
			void readAsciiFile();
	};

}

#endif
