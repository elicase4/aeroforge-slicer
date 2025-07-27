#ifndef ASCII_READER_HPP
#define ASCII_READER_HPP

#include <boost/endian/conversion.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace Reader {
	
	class AsciiReader{
		public:
			AsciiReader(const std::string& filename): _filename(filename) {};

			~AsciiReader() = default;

			void openFile(){
				file_stream = std::ifstream(_filename);
				if (!file_stream.is_open()){
					std::cerr << "Error: Could not open " << _filename << " in ascii STL format.\n";
					exit(1);
				}
			}

			void initializeLine(){
				std::istringstream string_stream(line);
			}

			void readDummyLine(){
				std::string dummy_char;
				std::getline(string_stream, dummy_char);
				std::cout << "dummy char: " << dummy_char << "\n";
			}
			
			void readString(std::string& string_input, size_t num_strings){
				std::string char_data;
				for (int i = 0; i < num_strings; i++){
					string_stream >> char_data;
					if (i > 0){
						string_input.append(" " + char_data);
					} else{
						string_input = char_data;
					}
				}
			}

			template <typename T>
			void readArray(T* data_stream, size_t array_length){
				
				std::string char_data;

				for (int i = 0; i < array_length; i++){
					string_stream >> char_data;
					data_stream[i] = std::stof(char_data);
				}
			}
			
			template <typename T>
			void readValue(T* data_stream){
				
				std::string char_data;
				
				data_stream = std::stof(char_data);
			}
			
			std::string line;
			std::ifstream file_stream;
			std::istringstream string_stream;
			
		private:

			std::string _filename;
	};
}

#endif
