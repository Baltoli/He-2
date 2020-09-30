#include_directories("include")
#include_directories("../../common/include")
#include_directories("C:/Python278/include")

#source_group(main FILES src/main/main.cpp
#tests/src/test_vector.cpp)
#source_group(memory FILES
#src/memory/memanalysis.cpp
#src/memory/memdump.cpp
#src/memory/meminstrace.cpp
#src/memory/memregions.cpp
#../../common/src/meminfo.cpp)
#source_group(utility FILES
#src/utility/fileparser.cpp
#src/utility/print_helper.cpp
#src/utility/sympy.cpp
#../../common/src/utilities.cpp
#../../common/src/imageinfo.cpp)
#source_group(trees FILES
#src/trees/node.cpp
#src/trees/tree.cpp
#src/trees/conc_node.cpp
#src/trees/conc_tree.cpp
#src/trees/abs_node.cpp
#src/trees/abs_tree.cpp
#src/trees/comp_abs_node.cpp
#src/trees/comp_abs_tree.cpp)
#source_group(halide FILES
#src/halide/halide.cpp)
#source_group(analysis FILES
#src/analysis/conditional_analysis.cpp
#src/analysis/preprocess.cpp
#src/analysis/tree_analysis.cpp
#src/analysis/x86_analysis.cpp
#src/analysis/staticinfo.cpp
#src/analysis/indirection_analysis.cpp)

#add_executable(buildex 

#src/main/main.cpp

#src/utility/fileparser.cpp
#src/utility/print_helper.cpp
##src/utility/sympy.cpp

#src/trees/node.cpp
#src/trees/tree.cpp
#src/trees/conc_node.cpp
#src/trees/conc_tree.cpp
#src/trees/abs_node.cpp
#src/trees/abs_tree.cpp
#src/trees/comp_abs_node.cpp
#src/trees/comp_abs_tree.cpp

#src/memory/memanalysis.cpp
#src/memory/memdump.cpp
#src/memory/meminstrace.cpp
#src/memory/memregions.cpp

#src/halide/halide.cpp

#src/analysis/conditional_analysis.cpp
#src/analysis/preprocess.cpp
#src/analysis/tree_analysis.cpp
#src/analysis/x86_analysis.cpp
#src/analysis/staticinfo.cpp
#src/analysis/indirection_analysis.cpp

#../../common/src/imageinfo.cpp
#../../common/src/meminfo.cpp
#../../common/src/utilities.cpp

##header files to be included
##include/memory/memanalysis.h

#)

#add_executable(test_vector 

#tests/src/test_vector.cpp

#src/utility/fileparser.cpp
#src/utility/print_helper.cpp
##src/utility/sympy.cpp

#src/trees/node.cpp
#src/trees/tree.cpp
#src/trees/conc_node.cpp
#src/trees/conc_tree.cpp
#src/trees/abs_node.cpp
#src/trees/abs_tree.cpp
#src/trees/comp_abs_node.cpp
#src/trees/comp_abs_tree.cpp

#src/memory/memanalysis.cpp
#src/memory/memdump.cpp
#src/memory/meminstrace.cpp
#src/memory/memregions.cpp

#src/halide/halide.cpp

#src/analysis/conditional_analysis.cpp
#src/analysis/preprocess.cpp
#src/analysis/tree_analysis.cpp
#src/analysis/x86_analysis.cpp
#src/analysis/staticinfo.cpp
#src/analysis/indirection_analysis.cpp

#../../common/src/imageinfo.cpp
#../../common/src/meminfo.cpp
#../../common/src/utilities.cpp


#)

##src/sympy.cpp

##find_library(PYTHON python27
##		PATHS "C:\Python278\libs")
##message(${PYTHON})
##target_link_libraries(buildex ${PYTHON})

#target_link_libraries(buildex Gdiplus.lib)
#target_link_libraries(test_vector Gdiplus.lib)

#option(BUILDEX_TEST OFF)

#if(BUILDEX_TEST)
	

#	#testing framework establishment

#	set(GTEST_ROOT "C:/Charith/libraries/gtest-1.7.0/gtest-1.7.0")
#	set(GTEST_MSVC_SEARCH "MD")

#	enable_testing()
#	find_package(GTest REQUIRED)
#	set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)

#	include_directories(${GTEST_INCLUDE_DIRS})
#	include_directories(${PROJECT_SOURCE_DIR}/tests)
#	file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/tests/*.cpp)

#	add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

#	target_link_libraries(${PROJECT_TEST_NAME} ${GTEST_BOTH_LIBRARIES})
#	add_test(test-all bin/${PROJECT_TEST_NAME})
	
#endif()


