#ifndef STL_PARSER_HPP
#define STL_PARSER_HPP

#include "Parser.hpp"

struct Facet{
	float normal_vector[3];
	float vertex1[3];
	float vertex2[3];
	float vertex3[3];
};

namespace SlicingParser {

	class STLParser: public Parser {
		public:
			
			STLParser(const std::string& filename): Parser(filename) {};
			
			~STLParser() = default;
			
			void print() const override;

			void readFile() override;
		
		private:
			
			std::ifstream open_binary_file(){
				return std::ifstream{_filename, std::ifstream::in | std::ifstream::binary};
			}
			
			template <typename T>
			void read_binary_value(std::ifstream& input_file_stream, T* data_stream){
				input_file_stream.read(as_char_ptr(data_stream), sizeof(T));
			}

			template <typename T>
			char* as_char_ptr(T* pointer){
				return reinterpret_cast<char*>(pointer);
			}

			template <typename T>
			void read_binary_array(std::ifstream& input_file_stream, T* data_stream, size_t array_length){
				size_t num_bytes = array_length*sizeof(T);
				input_file_stream.read(as_char_ptr(data_stream), num_bytes);
			}
			
			std::vector<Facet> _facet_list;
	};

}

#endif
