message(STATUS "Configuring tests")

file(GLOB TESTS *.cpp)

foreach(TEST ${TESTS})
    get_filename_component(EXENAME ${TEST} NAME_WE)
    add_executable(${EXENAME} ${TEST})
    target_link_libraries(${EXENAME} PRIVATE ${PROJECT_NAME})
    add_test(${EXENAME} ${EXENAME})
endforeach()