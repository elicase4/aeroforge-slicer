#ifndef STEP_PARSER_HPP
#define STEP_PARSER_HPP

#include "BaseParser.hpp"

namespace Parser {

	class STEPParser: public BaseParser {
		public:
			STEPParser(const std::string& filename, const boost::endian::order file_endian, const float hash_coord_tol): BaseParser(filename, file_endian, hash_coord_tol) {};
			
			~STEPParser() = default;
			
			void print() const override;
			
			void readFile() override;
	};

}

#endif
