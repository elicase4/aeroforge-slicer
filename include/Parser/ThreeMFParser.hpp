#ifndef THREEMF_PARSER_HPP
#define THREEMF_PARSER_HPP

#include "Parser.hpp"

namespace SlicingParser {

	class ThreeMFParser: public Parser {
		public:
			
			ThreeMFParser(const std::string& filename, Endianness file_endian): Parser(filename, file_endian) {};
			
			~ThreeMFParser() = default;
			
			void print() const override;

			void readFile() override;
	};

}

#endif
