#ifndef PARSER_UTILS_HPP
#define PARSER_UTILS_HPP

#include <boost/endian/conversion.hpp>
#include <fstream>
#include <string>

namespace Parser {
	
	class BinaryReader{
		public:
			BinaryReader(const std::string& filename, boost::endian::order file_endian): _filename(filename), _file_endian(file_endian) {};

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
				return ((_file_endian == boost::endian::order::little && (boost::endian::order::native == boost::endian::order::big)) ||
						(_file_endian == boost::endian::order::big && (boost::endian::order::native == boost::endian::order::little)));
			}

			template <typename T>
			char* interpretBytes(T* pointer){
				
				auto casted_pointer = reinterpret_cast<char*>(pointer);
				
				if (needsByteSwap()){
					boost::endian::endian_reverse_inplace(*casted_pointer);
				}
				
				return casted_pointer;
			}

			std::string _filename;
			boost::endian::order _file_endian;
			std::ifstream _file_stream;
	};
}

#endif
