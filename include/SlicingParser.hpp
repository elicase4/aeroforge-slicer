#ifndef SLICING_PARSER_HPP
#define SLICING_PARSER_HPP

#include <iostream>
#include <memory>
#include <string>

namespace SlicingParser {

	class Parser{
		public:
			
			virtual ~Parser() = default;
			
			virtual void print() = 0;
	};

	class STEPParser: public Parser {
		public:
			
			STEPParser() = default;
			
			~STEPParser() = default;
			
			void print();
	};

	class ThreeMFParser: public Parser {
		public:
			
			ThreeMFParser() = default;
			
			~ThreeMFParser() = default;
			
			void print();
	};

	class STLParser: public Parser {
		public:
			
			STLParser() = default;
			
			~STLParser() = default;
			
			void print();
	};

	class Factory {
		public:
			
			Factory(const std::string& input_file): _input_file(input_file) {};
			
			~Factory() = default;
			
			void readFile();

			std::unique_ptr<Parser> create();
		
		private:
			
			std::string _input_file;
			std::string _file_format;
	};

}

#endif
