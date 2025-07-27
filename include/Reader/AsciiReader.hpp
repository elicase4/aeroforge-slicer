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
				string_stream = std::istringstream(line);
			}
			
			void advanceLine(){
				std::getline(file_stream, line);
				string_stream = std::istringstream(line);
			}

			void readDummyLine(){
				std::string dummy_char;
				std::getline(file_stream, dummy_char);
			}
			
			void readString(std::string& string_buffer, size_t num_strings){
				std::string char_data;
				for (int i = 0; i < num_strings; ++i){
					string_stream >> char_data;
					if (i > 0){
						string_buffer.append(" " + char_data);
					} else {
						string_buffer = char_data;
					}
				}
			}

			template <typename T>
			void readArray(T* data_buffer, size_t array_length){
				for (int i = 0; i < array_length; ++i){
					string_stream >> data_buffer[i];
					std::cout << "data value [" << i << "]: " << data_buffer[i] << "\n";
				}
			}
			
			template <typename T>
			void readValue(T* data_buffer){
				string_stream >> *data_buffer;
			}
			
			std::string line;
			std::ifstream file_stream;
			std::istringstream string_stream;
			
		private:

			std::string _filename;
	};
}

#endif
