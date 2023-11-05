
# Create a library
add_library(bruteForce)
# Add the module file to the library
target_sources(bruteForce
  PUBLIC
    FILE_SET CXX_MODULES FILES
      bfSAT.cpp
)
