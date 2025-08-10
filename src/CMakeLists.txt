# Create library from source files
add_library(aeroforge_slicer STATIC
			Parser/STLParser.cpp
			Parser/STEPParser.cpp
			Parser/ThreeMFParser.cpp
			Geometry/Model.cpp
			Slicer/FacetSlicer.cpp
)

# Add public include path
target_include_directories(aeroforge_slicer PUBLIC 
		${PROJECT_SOURCE_DIR}/include)
target_include_directories(aeroforge_slicer PRIVATE 
		${BOOST_INCLUDE_DIRS})
