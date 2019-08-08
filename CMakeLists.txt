cmake_minimum_required(VERSION 3.7)

# project settings
project(membrane)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_IDENT "-dev")

# code style
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_CLANG_TIDY clang-tidy;
#     -format-style=google;
#     -checks=*;
#     -header-filter=.;
#     -warnings-as-errors=*;
# )
# set(CMAKE_CXX_CPPLINT cpplint
#     --recursive
#     --root='src'
#     --verbose=0
# )

# main executable
set(SOURCE_FILES main.cpp)
add_executable(${CMAKE_PROJECT_NAME}_main ${SOURCE_FILES})

# include_directories()

# sub builds
add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(${CMAKE_PROJECT_NAME}_main ${CMAKE_PROJECT_NAME}_lib)

# docs
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # set(BUILD_DOCS_DIR ${CMAKE_SOURCE_DIR}/build/docs)
    # if(NOT EXISTS ${BUILD_DOCS_DIR})
    #     file(MAKE_DIRECTORY ${BUILD_DOCS_DIR})
    # endif()

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message("Doxygen build started")
    add_custom_target(docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else()
    message("Doxygen needs to be installed to generate the documentation.")
endif()
