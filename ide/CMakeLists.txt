if (MSVC)
    message(STATUS "Configuring IDE settings")
    file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/resharper.DotSettings ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.sln.DotSettings)
endif()