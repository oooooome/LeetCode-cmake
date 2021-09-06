# CMakeList.txt : CMake project for LeetCode-cmake, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("LeetCode-cmake")

# TODO: Add tests and install targets if needed.

# Find all main*.cpp files and store in list mains
file(GLOB_RECURSE mains RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/solution*.cpp")
foreach(mainfile IN LISTS mains)
    # Get file name without directory
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
endforeach()