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
CMAKE_SOURCE_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build

# Include any dependencies generated for this target.
include CMakeFiles/LengthSort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LengthSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LengthSort.dir/flags.make

CMakeFiles/LengthSort.dir/main.cpp.o: CMakeFiles/LengthSort.dir/flags.make
CMakeFiles/LengthSort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LengthSort.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LengthSort.dir/main.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/main.cpp

CMakeFiles/LengthSort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LengthSort.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/main.cpp > CMakeFiles/LengthSort.dir/main.cpp.i

CMakeFiles/LengthSort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LengthSort.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/main.cpp -o CMakeFiles/LengthSort.dir/main.cpp.s

CMakeFiles/LengthSort.dir/sort.cpp.o: CMakeFiles/LengthSort.dir/flags.make
CMakeFiles/LengthSort.dir/sort.cpp.o: ../sort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LengthSort.dir/sort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LengthSort.dir/sort.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/sort.cpp

CMakeFiles/LengthSort.dir/sort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LengthSort.dir/sort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/sort.cpp > CMakeFiles/LengthSort.dir/sort.cpp.i

CMakeFiles/LengthSort.dir/sort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LengthSort.dir/sort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/sort.cpp -o CMakeFiles/LengthSort.dir/sort.cpp.s

# Object files for target LengthSort
LengthSort_OBJECTS = \
"CMakeFiles/LengthSort.dir/main.cpp.o" \
"CMakeFiles/LengthSort.dir/sort.cpp.o"

# External object files for target LengthSort
LengthSort_EXTERNAL_OBJECTS =

LengthSort: CMakeFiles/LengthSort.dir/main.cpp.o
LengthSort: CMakeFiles/LengthSort.dir/sort.cpp.o
LengthSort: CMakeFiles/LengthSort.dir/build.make
LengthSort: CMakeFiles/LengthSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable LengthSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LengthSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LengthSort.dir/build: LengthSort

.PHONY : CMakeFiles/LengthSort.dir/build

CMakeFiles/LengthSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LengthSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LengthSort.dir/clean

CMakeFiles/LengthSort.dir/depend:
	cd /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build /home/maciej/Documents/MyTasks/MaciejSalamonski/LengthSort/build/CMakeFiles/LengthSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LengthSort.dir/depend

