# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build"

# Include any dependencies generated for this target.
include tests/CMakeFiles/icon.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/icon.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/icon.dir/flags.make

tests/CMakeFiles/icon.dir/icon.c.o: tests/CMakeFiles/icon.dir/flags.make
tests/CMakeFiles/icon.dir/icon.c.o: ../tests/icon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/icon.dir/icon.c.o"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/icon.dir/icon.c.o -c "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/tests/icon.c"

tests/CMakeFiles/icon.dir/icon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/icon.dir/icon.c.i"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/tests/icon.c" > CMakeFiles/icon.dir/icon.c.i

tests/CMakeFiles/icon.dir/icon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/icon.dir/icon.c.s"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/tests/icon.c" -o CMakeFiles/icon.dir/icon.c.s

tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/icon.dir/flags.make
tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.o: ../deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.o"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/icon.dir/__/deps/glad_gl.c.o -c "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/deps/glad_gl.c"

tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/icon.dir/__/deps/glad_gl.c.i"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/deps/glad_gl.c" > CMakeFiles/icon.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/icon.dir/__/deps/glad_gl.c.s"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/deps/glad_gl.c" -o CMakeFiles/icon.dir/__/deps/glad_gl.c.s

# Object files for target icon
icon_OBJECTS = \
"CMakeFiles/icon.dir/icon.c.o" \
"CMakeFiles/icon.dir/__/deps/glad_gl.c.o"

# External object files for target icon
icon_EXTERNAL_OBJECTS =

tests/icon.app/Contents/MacOS/icon: tests/CMakeFiles/icon.dir/icon.c.o
tests/icon.app/Contents/MacOS/icon: tests/CMakeFiles/icon.dir/__/deps/glad_gl.c.o
tests/icon.app/Contents/MacOS/icon: tests/CMakeFiles/icon.dir/build.make
tests/icon.app/Contents/MacOS/icon: src/libglfw3.a
tests/icon.app/Contents/MacOS/icon: tests/CMakeFiles/icon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable icon.app/Contents/MacOS/icon"
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/icon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/icon.dir/build: tests/icon.app/Contents/MacOS/icon

.PHONY : tests/CMakeFiles/icon.dir/build

tests/CMakeFiles/icon.dir/clean:
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" && $(CMAKE_COMMAND) -P CMakeFiles/icon.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/icon.dir/clean

tests/CMakeFiles/icon.dir/depend:
	cd "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4" "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/tests" "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build" "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests" "/Users/gianlaager/Documents/code/C++/CLionProjects/OpenGL Wrapper/deps/glfw-3.3.4/build/tests/CMakeFiles/icon.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/icon.dir/depend

