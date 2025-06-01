#ifndef SLICING_PARSER_HPP
#define SLICING_PARSER_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace SlicingParser {

	class Parser{
		public:
			Parser(const std::string& filename): _filename(filename) {};
			
			virtual ~Parser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;
		
		protected:
			std::string _filename;
	};

}

#endif
