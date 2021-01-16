cmake_minimum_required(VERSION 3.15)
enable_testing()
set(CMAKE_CXX_STANDARD 17)

project(mmeasureunits)

file(GLOB_RECURSE CPP_INC include/*.hpp)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE include)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${CPP_INC})

# MSVC-only static library to get library header files listed in a seperate project.
if (MSVC)
    set(FAKE_SOURCE_FILE_PATH ${CMAKE_BINARY_DIR}/placeholder.cpp)
    file(WRITE ${FAKE_SOURCE_FILE_PATH} "enum auto_generated { no_need_to_edit };")
    add_library(mmu STATIC ${CPP_INC} ${FAKE_SOURCE_FILE_PATH})
endif()

add_subdirectory(ide)
add_subdirectory(test)
