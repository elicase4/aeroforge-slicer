# Create library from source files
add_library(slicing_lib 
			SlicingParser.cpp
)

# Add public include path
target_include_directories(slicing_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
