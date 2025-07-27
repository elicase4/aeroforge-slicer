#ifndef THREEMF_PARSER_HPP
#define THREEMF_PARSER_HPP

#include "BaseParser.hpp"

namespace Parser {

	class ThreeMFParser: public BaseParser {
		public:
			
			ThreeMFParser(const std::string& filename, const boost::endian::order file_endian, const float hash_coord_tol): BaseParser(filename, file_endian, hash_coord_tol) {};
			
			~ThreeMFParser() = default;
			
			void print() const override;

			void readFile() override;
	};

}

#endif
