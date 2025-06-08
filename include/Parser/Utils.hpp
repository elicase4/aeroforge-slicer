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

			void openFile();

			template <typename T>
			void readValue(T* datastream);

			template <typename T>
			void readArray(T* datastream, size_t array_length);

		private:
			bool needsByteswap();
			
			template <typename T>
			char* interpretBytes(T* pointer);

			std::string _filename;
			Endianness _file_endian;
			std::ifstream _file_stream;
	};
}

#endif
