cmake_minimum_required(VERSION 3.10)
project(iris LANGUAGES CXX)

set(TARGET_SRC src/main.cpp)
file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/iris/*.cpp")
# file(GLOB HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/iris/*.h")

set(TARGET test)
set(LIB_TARGET iris)
set(LIBS raylib)
option(BUILD_TEST "Whether to build executable test or not" ON)

add_library(${LIB_TARGET} STATIC ${SOURCES})
target_link_libraries(${LIB_TARGET} PRIVATE raylib)

if(BUILD_TEST)
    add_executable(${TARGET} ${TARGET_SRC})
    target_link_libraries(${TARGET} ${LIB_TARGET} ${LIBS})
endif()