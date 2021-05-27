cmake_minimum_required(VERSION 3.19)
project(OpenGL_Wrapper)

set(CMAKE_CXX_STANDARD 20)

#LIBRARY
set(SRC
		"src/glw/glw.cpp"
		)
set(HEAD
		"include/glw/glw.h"
		"include/glw/pch.h"
		)

add_subdirectory(deps/glew/build/cmake)
add_subdirectory(deps/glfw)
find_package(OpenGL)

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEAD})

target_link_libraries(${PROJECT_NAME} PUBLIC "glfw" "glew" OpenGL::GL)
include_directories("deps/glfw/include" "deps/glew/include" "include/")

target_precompile_headers(${PROJECT_NAME} PUBLIC include/glw/pch.h)

#TESTS
include(FetchContent)

FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_SRC
		"tests/src/test/main.cpp"
		)

add_executable(${PROJECT_NAME}_Test ${TEST_SRC})

target_link_libraries(${PROJECT_NAME}_Test PUBLIC ${PROJECT_NAME})

include(GoogleTest)
target_link_libraries(${PROJECT_NAME}_Test PUBLIC gtest_main)
target_include_directories(${PROJECT_NAME}_Test PUBLIC "include" "tests/deps/googletest/googletest/include" "tests/src")
target_precompile_headers(${PROJECT_NAME}_Test PUBLIC "tests/src/test/pch.h")

