#ifndef PARSER_FACTORY_HPP
#define PARSER_FACTORY_HPP

// standard libraries
#include <memory>
#include <stdexcept>
#include <string>

// boost libraries
#include <boost/endian/conversion.hpp>

// internal libraries
#include "BaseParser.hpp"
#include "STLParser.hpp"
#include "STEPParser.hpp"
#include "ThreeMFParser.hpp"

namespace Parser {

	class Factory {
		public:
			
			static std::unique_ptr<BaseParser> createParser(const std::string& filename, const boost::endian::order file_endian = boost::endian::order::big, const float hash_coord_tol = 1e-5f){
				std::string extension = getFileExtension(filename);
				if (extension == "STL"){
					return std::make_unique<Parser::STLParser>(filename, file_endian, hash_coord_tol);
				}
				if (extension == "STEP"){
					return std::make_unique<Parser::STEPParser>(filename, file_endian, hash_coord_tol);
				}
				if (extension == "3MF"){
					return std::make_unique<Parser::ThreeMFParser>(filename, file_endian, hash_coord_tol);
				}
				
				std::cerr << "Warning: Unsupported file format '" << extension << "' provided.\n";
				
				return nullptr;
			}
		
		private:
			
			static std::string getFileExtension(const std::string& filename){
				size_t dot_position = filename.find_last_of('.');
				std::string file_format;
				if ((dot_position != std::string::npos) && (dot_position + 1 < filename.length())){
					file_format = filename.substr(dot_position + 1);
				} else {
					file_format = "";
				}
				
				return file_format;
			}
	};

}

#endif
