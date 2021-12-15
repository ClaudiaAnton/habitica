# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/habitica_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/habitica_autogen.dir/ParseCache.txt"
  "habitica_autogen"
  )
endif()
