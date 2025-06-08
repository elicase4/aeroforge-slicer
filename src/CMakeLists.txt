# Create library from source files
add_library(parser 
			Parser/STLParser.cpp
			Parser/STEPParser.cpp
			Parser/ThreeMFParser.cpp
)

# Add public include path
target_include_directories(parser PUBLIC 
		${PROJECT_SOURCE_DIR}/include)
target_include_directories(parser PRIVATE 
		${BOOST_INCLUDE_DIRS})
