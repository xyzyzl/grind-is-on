# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/xyzyzl/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xyzyzl/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xyzyzl/Documents/cp3/usaco/scodereal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scodereal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scodereal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scodereal.dir/flags.make

CMakeFiles/scodereal.dir/main.cpp.o: CMakeFiles/scodereal.dir/flags.make
CMakeFiles/scodereal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scodereal.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/scodereal.dir/main.cpp.o -c /home/xyzyzl/Documents/cp3/usaco/scodereal/main.cpp

CMakeFiles/scodereal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scodereal.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xyzyzl/Documents/cp3/usaco/scodereal/main.cpp > CMakeFiles/scodereal.dir/main.cpp.i

CMakeFiles/scodereal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scodereal.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xyzyzl/Documents/cp3/usaco/scodereal/main.cpp -o CMakeFiles/scodereal.dir/main.cpp.s

# Object files for target scodereal
scodereal_OBJECTS = \
"CMakeFiles/scodereal.dir/main.cpp.o"

# External object files for target scodereal
scodereal_EXTERNAL_OBJECTS =

scodereal: CMakeFiles/scodereal.dir/main.cpp.o
scodereal: CMakeFiles/scodereal.dir/build.make
scodereal: CMakeFiles/scodereal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable scodereal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scodereal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scodereal.dir/build: scodereal

.PHONY : CMakeFiles/scodereal.dir/build

CMakeFiles/scodereal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scodereal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scodereal.dir/clean

CMakeFiles/scodereal.dir/depend:
	cd /home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xyzyzl/Documents/cp3/usaco/scodereal /home/xyzyzl/Documents/cp3/usaco/scodereal /home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug /home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug /home/xyzyzl/Documents/cp3/usaco/scodereal/cmake-build-debug/CMakeFiles/scodereal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scodereal.dir/depend

