#include "Parser/Utils.hpp"

SlicingParser::BinaryReader::openFile(){
	_file_stream = std::ifstream{_filename, std::ifstream::in | std::ifstream::binary};
}

template typename<T>
SlicingParser::BinaryReader::readFile(T* data_stream){
	_file_stream.read(interpretBytes(data_stream), sizeof(T));
}

template typename<T>
SlicingParser::BinaryReader::readArray(T* data_stream, size_t array_length){
	size_t num_bytes = array_length*sizeof(T);
	_file_stream.read(interpretBytes(data_stream), num_bytes);
}

bool  SlicingParser::BinaryReader::needsByteSwap(){
	return ((_file_endian == SlicingParser::Endianness::Little && boost::endian::order::native == boost::endian::order::big) ||
			(_file_endian == SlicingParser::Endianness::Big && boost::endian::order::native == boost::endian::order::little));
}

template typename<T>
char* interpretBytes(T* pointer){
	char* casted_ptr = reinterpret_cast<char*>(pointer);
	return (needsByteSwap() ? boost::endian::endian_reverse_inplace(casted_ptr) : casted_ptr);
}
