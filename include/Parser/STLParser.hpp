#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "Parser.hpp"

#include <iostream>

namespace SlicingParser {

	class STLParser: public Parser {
		public:
			
			STLParser() = default;
			
			~STLParser() = default;
			
			void print();
	};

}

#endif
