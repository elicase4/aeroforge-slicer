#ifndef SLICING_FACTORY_HPP
#define SLICING_FACTORY_HPP

#include "Parser.hpp"
#include "STLParser.hpp"
#include "STEPParser.hpp"
#include "ThreeMFParser.hpp"

#include <memory>
#include <stdexcept>
#include <string>

namespace SlicingParser {

	class Factory {
		public:
			
			static std::unique_ptr<Parser> createParser(const std::string& filename, const Endianness file_endian){
				std::string extension = getFileExtension(filename);
				if (extension == "STL"){
					return std::make_unique<SlicingParser::STLParser>(filename, file_endian);
				}
				if (extension == "STEP"){
					return std::make_unique<SlicingParser::STEPParser>(filename, file_endian);
				}
				if (extension == "3MF"){
					return std::make_unique<SlicingParser::ThreeMFParser>(filename, file_endian);
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
