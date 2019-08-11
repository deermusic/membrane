include_directories(${gtest_SOURCE_DIR}/include)

set(SOURCE_FILES
    membrane/membrane_spec.cpp
)

add_executable(${CMAKE_PROJECT_NAME}_test ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME}_test gtest gtest_main)
target_link_libraries(${CMAKE_PROJECT_NAME}_test ${CMAKE_PROJECT_NAME}_lib)
