#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "BaseParser.hpp"

const size_t STL_BINARY_HEADER_SIZE = 80;

namespace Parser {

	class STLParser: public BaseParser {
		public:
			
			STLParser(const std::string& filename, const boost::endian::order file_endian, const float hash_coord_tol): BaseParser(filename, file_endian, hash_coord_tol) {};
			
			~STLParser() = default;
			
			void print() const override;

			void readFile() override;

	};

}

#endif
