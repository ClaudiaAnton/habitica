# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/triedit_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/triedit_autogen.dir/ParseCache.txt"
  "triedit_autogen"
  )
endif()
