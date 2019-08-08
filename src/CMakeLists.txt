project(${CMAKE_PROJECT_NAME}_lib)

set(SOURCE_FILES
    membrane.cpp
    membrane.h
)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCE_FILES})
