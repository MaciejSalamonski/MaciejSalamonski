# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build

# Include any dependencies generated for this target.
include CMakeFiles/fibonacci-ut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fibonacci-ut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fibonacci-ut.dir/flags.make

CMakeFiles/fibonacci-ut.dir/test.cpp.o: CMakeFiles/fibonacci-ut.dir/flags.make
CMakeFiles/fibonacci-ut.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fibonacci-ut.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fibonacci-ut.dir/test.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/test.cpp

CMakeFiles/fibonacci-ut.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fibonacci-ut.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/test.cpp > CMakeFiles/fibonacci-ut.dir/test.cpp.i

CMakeFiles/fibonacci-ut.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fibonacci-ut.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/test.cpp -o CMakeFiles/fibonacci-ut.dir/test.cpp.s

CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o: CMakeFiles/fibonacci-ut.dir/flags.make
CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o: ../fibonacci.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/fibonacci.cpp

CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/fibonacci.cpp > CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.i

CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/fibonacci.cpp -o CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.s

# Object files for target fibonacci-ut
fibonacci__ut_OBJECTS = \
"CMakeFiles/fibonacci-ut.dir/test.cpp.o" \
"CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o"

# External object files for target fibonacci-ut
fibonacci__ut_EXTERNAL_OBJECTS =

fibonacci-ut: CMakeFiles/fibonacci-ut.dir/test.cpp.o
fibonacci-ut: CMakeFiles/fibonacci-ut.dir/fibonacci.cpp.o
fibonacci-ut: CMakeFiles/fibonacci-ut.dir/build.make
fibonacci-ut: lib/libgtest_main.a
fibonacci-ut: lib/libgtest.a
fibonacci-ut: CMakeFiles/fibonacci-ut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable fibonacci-ut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fibonacci-ut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fibonacci-ut.dir/build: fibonacci-ut

.PHONY : CMakeFiles/fibonacci-ut.dir/build

CMakeFiles/fibonacci-ut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fibonacci-ut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fibonacci-ut.dir/clean

CMakeFiles/fibonacci-ut.dir/depend:
	cd /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build /home/maciej/Documents/MyTasks/MaciejSalamonski/Fibonacci/build/CMakeFiles/fibonacci-ut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fibonacci-ut.dir/depend

