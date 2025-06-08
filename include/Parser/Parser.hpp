#ifndef SLICING_PARSER_HPP
#define SLICING_PARSER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Utils.hpp"

namespace SlicingParser {

	class Parser{
		public:
			Parser(const std::string& filename, const Endianness file_endian): _filename(filename), _file_endian(file_endian) {};
			
			virtual ~Parser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;
		
		protected:
			std::string _filename;
			Endianness _file_endian;
	};

}

#endif
