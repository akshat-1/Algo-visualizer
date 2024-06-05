#OBJS specifies which files to compile as part of the project
cmake_minimum_required(VERSION 3.16)
project(Sandbox VERSION 1.0.0   )

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(OSBitness 64)
endif()
set (FullOutputDir "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}${OSBitness}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

include_directories(.)

#packages block start
add_executable(Sandbox main.cpp)
add_subdirectory(external/SDL-release-2.30.3)
target_link_libraries(Sandbox PRIVATE SDL2)
if(WIN32)
    target_link_libraries(Sandbox PRIVATE SDL2main)
endif()

# include_directories((${SDL2_INCLUDE_DIRS}))
#packages block ends

