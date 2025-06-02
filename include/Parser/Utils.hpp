#ifndef PARSER_UTILS_HPP
#define PARSER_UTILS_HPP

#include <fstream>
#include <string>

namespace SlicingParser {
	
	namespace BinaryUtils {
		
		std::ifstream openFile(const std::string& filename){
			return std::ifstream{filename, std::ifstream::in | std::ifstream::binary};
		}
		
		template <typename T>
		void readValue(std::ifstream& input_file_stream, T* data_stream){
			input_file_stream.read(reinterpret_cast<char*>(data_stream), sizeof(T));
		}

		template <typename T>
		void readArray(std::ifstream& input_file_stream, T* data_stream, size_t array_length){
			size_t num_bytes = array_length*sizeof(T);
			input_file_stream.read(reinterpret_cast<char*>(data_stream), num_bytes);
		}
	}
}

#endif
