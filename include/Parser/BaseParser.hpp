#ifndef BASE_PARSER_HPP
#define BASE_PARSER_HPP

#include <boost/endian/conversion.hpp>
#include <iostream>
#include <string>
#include "Utils.hpp"

namespace Parser {

	class BaseParser{
		public:
			BaseParser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::native): _filename(filename), _file_endian(file_endian) {};
			
			virtual ~BaseParser() = default;
			
			virtual void print() const = 0;
			
			virtual void readFile() = 0;
		
		protected:
			std::string _filename;
			boost::endian::order _file_endian;
	};

}

#endif
