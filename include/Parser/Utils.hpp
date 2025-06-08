#ifndef PARSER_UTILS_HPP
#define PARSER_UTILS_HPP

#include <fstream>
#include <string>
#include <boost/endian/conversion.hpp>

namespace SlicingParser {
	
	enum struct Endianness {
		Little,
		Big
	};
		
	class BinaryReader{
		public:
			BinaryReader(const std::string& filename, Endianness file_endian): _filename(filename), _file_endian(file_endian) {};

			~BinaryReader() = default;

			void openFile(){
				_file_stream = std::ifstream{_filename, std::ifstream::in | std::ifstream::binary};
			}
			
			template <typename T>
			void readValue(T* data_stream){
				_file_stream.read(interpretBytes<T>(data_stream), sizeof(T));
			}

			template <typename T>
			void readArray(T* data_stream, size_t array_length){
				size_t num_bytes = array_length*sizeof(T);
				_file_stream.read(interpretBytes<T>(data_stream), num_bytes);
			}

		private:
			bool needsByteSwap(){
				return ((_file_endian == Endianness::Little && boost::endian::order::native == boost::endian::order::big) ||
						(_file_endian == Endianness::Big && boost::endian::order::native == boost::endian::order::little));
			}

			template <typename T>
			char* interpretBytes(T* pointer){
				char* casted_ptr = reinterpret_cast<char*>(pointer);
				if (needsByteSwap()){
					boost::endian::endian_reverse_inplace(*casted_ptr);
				}
				
				return casted_ptr;
			}

			std::string _filename;
			Endianness _file_endian;
			std::ifstream _file_stream;
	};
}

#endif
