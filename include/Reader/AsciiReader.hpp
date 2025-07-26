#ifndef ASCII_READER_HPP
#define ASCII_READER_HPP

#include <boost/endian/conversion.hpp>
#include <fstream>
#include <string>

namespace Reader {
	
	class AsciiReader{
		public:
			AsciiReader(const std::string& filename): _filename(filename) {};

			~AsciiReader() = default;

			void openFile(){
				_file_stream = std::ifstream{_filename, std::ifstream::in | std::ifstream::binary};
			}
			
		private:

			std::string _filename;
			std::ifstream _file_stream;
	};
}

#endif
