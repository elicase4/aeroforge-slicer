#ifndef SLICING_PARSER_HPP
#define SLICING_PARSER_HPP

#include <iostream>
#include <memory>
#include <string>

namespace SlicingParser {

	class Parser{
		public:
			
			virtual ~Parser() = default;
			
			virtual void print() = 0;
	};

}

#endif
