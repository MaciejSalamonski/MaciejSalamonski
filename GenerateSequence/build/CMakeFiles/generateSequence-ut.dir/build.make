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
CMAKE_SOURCE_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build

# Include any dependencies generated for this target.
include CMakeFiles/generateSequence-ut.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/generateSequence-ut.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/generateSequence-ut.dir/flags.make

CMakeFiles/generateSequence-ut.dir/test.cpp.o: CMakeFiles/generateSequence-ut.dir/flags.make
CMakeFiles/generateSequence-ut.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/generateSequence-ut.dir/test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generateSequence-ut.dir/test.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/test.cpp

CMakeFiles/generateSequence-ut.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generateSequence-ut.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/test.cpp > CMakeFiles/generateSequence-ut.dir/test.cpp.i

CMakeFiles/generateSequence-ut.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generateSequence-ut.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/test.cpp -o CMakeFiles/generateSequence-ut.dir/test.cpp.s

CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o: CMakeFiles/generateSequence-ut.dir/flags.make
CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o: ../generateSequence.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/generateSequence.cpp

CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/generateSequence.cpp > CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.i

CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/generateSequence.cpp -o CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.s

# Object files for target generateSequence-ut
generateSequence__ut_OBJECTS = \
"CMakeFiles/generateSequence-ut.dir/test.cpp.o" \
"CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o"

# External object files for target generateSequence-ut
generateSequence__ut_EXTERNAL_OBJECTS =

generateSequence-ut: CMakeFiles/generateSequence-ut.dir/test.cpp.o
generateSequence-ut: CMakeFiles/generateSequence-ut.dir/generateSequence.cpp.o
generateSequence-ut: CMakeFiles/generateSequence-ut.dir/build.make
generateSequence-ut: lib/libgtest_main.a
generateSequence-ut: lib/libgtest.a
generateSequence-ut: CMakeFiles/generateSequence-ut.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable generateSequence-ut"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/generateSequence-ut.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/generateSequence-ut.dir/build: generateSequence-ut

.PHONY : CMakeFiles/generateSequence-ut.dir/build

CMakeFiles/generateSequence-ut.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/generateSequence-ut.dir/cmake_clean.cmake
.PHONY : CMakeFiles/generateSequence-ut.dir/clean

CMakeFiles/generateSequence-ut.dir/depend:
	cd /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build /home/maciej/Documents/MyTasks/MaciejSalamonski/GenerateSequence/build/CMakeFiles/generateSequence-ut.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/generateSequence-ut.dir/depend

