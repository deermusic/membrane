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

# main executable
# set(SOURCE_FILES main.cpp)
# add_executable(${CMAKE_PROJECT_NAME}_main ${SOURCE_FILES})

include_directories(src)

# sub builds
add_subdirectory(src)
add_subdirectory(test)

# target_link_libraries(${CMAKE_PROJECT_NAME}_main ${CMAKE_PROJECT_NAME}_lib)

# linting
set(CPPLINT_SCRIPT ${CMAKE_CURRENT_BINARY_DIR}/cpplint.py)
if(NOT EXISTS ${CPPLINT_SCRIPT})
message("Downloading cpplint.py")
file(DOWNLOAD "https://raw.githubusercontent.com/cpplint/cpplint/master/cpplint.py" ${CPPLINT_SCRIPT})
endif()
find_package(Python REQUIRED)
add_custom_target(lint ALL
        COMMAND ${PYTHON_EXECUTABLE} ${CPPLINT_SCRIPT} --recursive --quiet --root=src --linelength=120 src
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Linting src with cpplint.py"
        VERBATIM)
# TODO: move tests to src (don't keep them separated)
add_custom_target(lint_test ALL
        COMMAND ${PYTHON_EXECUTABLE} ${CPPLINT_SCRIPT} --recursive --quiet --root=test/src --linelength=120 test/src
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Linting test/src with cpplint.py"
        VERBATIM)

# docs
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # prepare config file
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.in)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    add_custom_target(docs ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else()
    message("Doxygen needs to be installed to generate the documentation.")
endif()
