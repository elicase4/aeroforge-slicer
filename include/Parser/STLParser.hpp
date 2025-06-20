#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "Parser.hpp"
#include <vector>

const size_t STL_BINARY_HEADER_SIZE = 80;

struct Facet{
	float normal_vector[3];
	float vertex1[3];
	float vertex2[3];
	float vertex3[3];
};

namespace SlicingParser {

	class STLParser: public Parser {
		public:
			
			STLParser(const std::string& filename, boost::endian::order file_endian): Parser(filename, file_endian) {};
			
			~STLParser() = default;
			
			void print() const override;

			void readFile() override;
		
		private:
			void printFacet(Facet f, int facet_num);
		
			std::vector<Facet> _facet_list;
	};

}

#endif
