project(${CMAKE_PROJECT_NAME}_test)

# clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/test/lib/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    message("Cloning Google Test library")
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif()

add_subdirectory(lib/googletest)
add_subdirectory(src)
