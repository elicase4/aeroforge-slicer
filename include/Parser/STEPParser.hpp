#ifndef STEP_PARSER_HPP
#define STEP_PARSER_HPP

#include "Parser.hpp"

namespace SlicingParser {

	class STEPParser: public Parser {
		public:
			STEPParser(const std::string& filename): Parser(filename) {};
			
			~STEPParser() = default;
			
			void print() const override;
			
			void readFile() override;
	};

}

#endif
