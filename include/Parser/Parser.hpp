#ifndef SLICING_PARSER_HPP
#define SLICING_PARSER_HPP

#include <boost/endian/conversion.hpp>
#include <iostream>
#include <string>
#include "Utils.hpp"

namespace SlicingParser {

	class Parser{
		public:
			Parser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::native): _filename(filename), _file_endian(file_endian) {};
			
			virtual ~Parser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;
		
		protected:
			std::string _filename;
			boost::endian::order _file_endian;
	};

}

#endif
