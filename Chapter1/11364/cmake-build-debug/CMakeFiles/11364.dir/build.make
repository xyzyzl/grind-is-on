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
CMAKE_SOURCE_DIR = /home/xyzyzl/Documents/cp3/Chapter1/11364

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/11364.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/11364.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11364.dir/flags.make

CMakeFiles/11364.dir/main.cpp.o: CMakeFiles/11364.dir/flags.make
CMakeFiles/11364.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11364.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11364.dir/main.cpp.o -c /home/xyzyzl/Documents/cp3/Chapter1/11364/main.cpp

CMakeFiles/11364.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11364.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xyzyzl/Documents/cp3/Chapter1/11364/main.cpp > CMakeFiles/11364.dir/main.cpp.i

CMakeFiles/11364.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11364.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xyzyzl/Documents/cp3/Chapter1/11364/main.cpp -o CMakeFiles/11364.dir/main.cpp.s

# Object files for target 11364
11364_OBJECTS = \
"CMakeFiles/11364.dir/main.cpp.o"

# External object files for target 11364
11364_EXTERNAL_OBJECTS =

11364: CMakeFiles/11364.dir/main.cpp.o
11364: CMakeFiles/11364.dir/build.make
11364: CMakeFiles/11364.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11364"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11364.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11364.dir/build: 11364

.PHONY : CMakeFiles/11364.dir/build

CMakeFiles/11364.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11364.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11364.dir/clean

CMakeFiles/11364.dir/depend:
	cd /home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xyzyzl/Documents/cp3/Chapter1/11364 /home/xyzyzl/Documents/cp3/Chapter1/11364 /home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug /home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug /home/xyzyzl/Documents/cp3/Chapter1/11364/cmake-build-debug/CMakeFiles/11364.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11364.dir/depend
