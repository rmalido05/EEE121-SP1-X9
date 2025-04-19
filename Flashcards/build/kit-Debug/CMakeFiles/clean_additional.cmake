# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Flashcards_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Flashcards_autogen.dir\\ParseCache.txt"
  "Flashcards_autogen"
  )
endif()
