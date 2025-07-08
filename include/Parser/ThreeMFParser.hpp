#ifndef THREEMF_PARSER_HPP
#define THREEMF_PARSER_HPP

#include "BaseParser.hpp"

namespace Parser {

	class ThreeMFParser: public BaseParser {
		public:
			
			ThreeMFParser(const std::string& filename, boost::endian::order file_endian): BaseParser(filename, file_endian) {};
			
			~ThreeMFParser() = default;
			
			void print() const override;

			void readFile() override;
	};

}

#endif
