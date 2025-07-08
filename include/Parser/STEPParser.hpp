#ifndef STEP_PARSER_HPP
#define STEP_PARSER_HPP

#include "BaseParser.hpp"

namespace Parser {

	class STEPParser: public BaseParser {
		public:
			STEPParser(const std::string& filename, boost::endian::order file_endian): BaseParser(filename, file_endian) {};
			
			~STEPParser() = default;
			
			void print() const override;
			
			void readFile() override;
	};

}

#endif
