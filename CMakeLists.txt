cmake_minimum_required(VERSION 3.19)
project(OpenGL_Wrapper)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

include(FetchContent)

#LIBRARY
set(SRC
		src/glwrp/Buffer.cpp
		src/glwrp/IndexBuffer.cpp
		src/glwrp/Renderer.cpp
		src/glwrp/Shader.cpp
#		src/glwrp/Texture.cpp
		src/glwrp/VertexArray.cpp
		src/glwrp/VertexBuffer.cpp
		src/glwrp/VertexBufferLayout.cpp
		src/glwrp/Window.cpp
		src/glwrp/glwrp.cpp
		)
set(HEAD
		include/glwrp/Buffer.h
		include/glwrp/IndexBuffer.h
		include/glwrp/Renderer.h
		include/glwrp/Shader.h
#		include/glwrp/Texture.h
		include/glwrp/VertexArray.h
		include/glwrp/VertexBuffer.h
		include/glwrp/VertexBufferLayout.h
		include/glwrp/Window.h
		include/glwrp/glwrp.h
		include/glwrp/pch.h
		)

FetchContent_Declare(
		glfw
		URL https://github.com/glfw/glfw/releases/download/3.3.4/glfw-3.3.4.zip
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
		glew
		URL https://sourceforge.net/projects/glew/files/glew/2.1.0/glew-2.1.0.zip/download
)
FetchContent_MakeAvailable(GLEW)
set(GLEW_INCLUDE_DIRECTORIES ${PROJECT_BINARY_DIR}/_deps/glew-src/include)
add_subdirectory(${PROJECT_BINARY_DIR}/_deps/glew-src/build/cmake)

FetchContent_Declare(
		glm
		GIT_REPOSITORY https://github.com/g-truc/glm
		GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

find_package(OpenGL)

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEAD})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX _d)
target_link_libraries(${PROJECT_NAME} PUBLIC "glfw" "glew" "glm" OpenGL::GL)
include_directories(glfw ${GLEW_INCLUDE_DIRECTORIES} "glm" "include/")
target_precompile_headers(${PROJECT_NAME} PUBLIC include/glwrp/pch.h)

#TESTS
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
target_include_directories(${PROJECT_NAME}_Test PRIVATE "include" "tests/deps/googletest/googletest/include" "tests/src")
target_precompile_headers(${PROJECT_NAME}_Test PRIVATE "tests/src/test/pch.h")
set_target_properties(${PROJECT_NAME}_Test PROPERTIES DEBUG_POSTFIX _d)

