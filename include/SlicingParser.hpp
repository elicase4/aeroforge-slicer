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

	class STLParser: public Parser {
		public:
			STLParser() = default;
			~STLParser() = default;
			
			void print();
	};

	class Factory {
		public:
			virtual std::unique_ptr<Parser> create(std::string format);
	};

}

#endif
