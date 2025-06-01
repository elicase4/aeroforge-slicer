#ifndef THREEMF_PARSER_HPP
#define THREEMF_PARSER_HPP

#include "Parser.hpp"

#include <iostream>

namespace SlicingParser {

	class ThreeMFParser: public Parser {
		public:
			
			ThreeMFParser() = default;
			
			~ThreeMFParser() = default;
			
			void print();
	};

}

#endif
