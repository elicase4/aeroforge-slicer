#ifndef STEP_PARSER_HPP
#define STEP_PARSER_HPP

#include "Parser.hpp"

#include <iostream>

namespace SlicingParser {

	class STEPParser: public Parser {
		public:
			
			STEPParser() = default;
			
			~STEPParser() = default;
			
			void print();
	};

}

#endif
