cmake_minimum_required(VERSION 3.28)
project(std_module_example CXX)

# Turning off extensions avoids and issue with the clang 16 compiler
# clang 17 and greater can avoid this setting
set(CMAKE_CXX_EXTENSIONS OFF)
# Set the version of C++ for the project
set(CMAKE_CXX_STANDARD 20)

# cmake modules
include(cmake/list_dirs.cmake)
include(cmake/upd_tar_list.cmake)
include(cmake/CPM.cmake)
include(cmake/comp_flags.cmake)

# add dir with libraries
add_subdirectory(src)
# Create an executable
add_executable(hello main.cxx)
# Link to the library foo
target_link_libraries(hello ${LIBLIST})

# gtests
enable_testing()
add_subdirectory(tests)
