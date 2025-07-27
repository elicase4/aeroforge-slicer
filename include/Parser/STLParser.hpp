#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "BaseParser.hpp"
#include "Reader/BinaryReader.hpp"
#include "Reader/AsciiReader.hpp"

const size_t STL_BINARY_HEADER_SIZE = 80;

namespace Parser {

	class STLParser: public BaseParser {
		public:
			
			STLParser(const std::string& filename, const boost::endian::order file_endian, const float hash_coord_tol, const std::string reader_format = "binary"): BaseParser(filename, file_endian, hash_coord_tol), _reader_format(reader_format) {};
			
			~STLParser() = default;
			
			void print() const override;

			void readFile() override;

		private:
			
			std::string _reader_format;
			
			void readBinaryFile();
			
			void readAsciiFile();
	};

}

#endif
