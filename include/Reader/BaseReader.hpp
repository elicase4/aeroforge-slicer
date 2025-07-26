#ifndef BASE_READER_HPP
#define BASE_READER_HPP

#include <string>
#include <fstream>

namespace Reader {

	class BaseReader{
		public:
			BaseReader(const std::string& filename): _filename(filename) {};
			
			~BaseReader() = default;
			
			void openFile(){};

		private:
			
			std::string _filename;
	}

}

#endif
