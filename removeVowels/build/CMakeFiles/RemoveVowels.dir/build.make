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
CMAKE_SOURCE_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build

# Include any dependencies generated for this target.
include CMakeFiles/RemoveVowels.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RemoveVowels.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RemoveVowels.dir/flags.make

CMakeFiles/RemoveVowels.dir/main.cpp.o: CMakeFiles/RemoveVowels.dir/flags.make
CMakeFiles/RemoveVowels.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RemoveVowels.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoveVowels.dir/main.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/main.cpp

CMakeFiles/RemoveVowels.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoveVowels.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/main.cpp > CMakeFiles/RemoveVowels.dir/main.cpp.i

CMakeFiles/RemoveVowels.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoveVowels.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/main.cpp -o CMakeFiles/RemoveVowels.dir/main.cpp.s

CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o: CMakeFiles/RemoveVowels.dir/flags.make
CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o: ../removeVowels.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/removeVowels.cpp

CMakeFiles/RemoveVowels.dir/removeVowels.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoveVowels.dir/removeVowels.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/removeVowels.cpp > CMakeFiles/RemoveVowels.dir/removeVowels.cpp.i

CMakeFiles/RemoveVowels.dir/removeVowels.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoveVowels.dir/removeVowels.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/removeVowels.cpp -o CMakeFiles/RemoveVowels.dir/removeVowels.cpp.s

# Object files for target RemoveVowels
RemoveVowels_OBJECTS = \
"CMakeFiles/RemoveVowels.dir/main.cpp.o" \
"CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o"

# External object files for target RemoveVowels
RemoveVowels_EXTERNAL_OBJECTS =

RemoveVowels: CMakeFiles/RemoveVowels.dir/main.cpp.o
RemoveVowels: CMakeFiles/RemoveVowels.dir/removeVowels.cpp.o
RemoveVowels: CMakeFiles/RemoveVowels.dir/build.make
RemoveVowels: CMakeFiles/RemoveVowels.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable RemoveVowels"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemoveVowels.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RemoveVowels.dir/build: RemoveVowels

.PHONY : CMakeFiles/RemoveVowels.dir/build

CMakeFiles/RemoveVowels.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RemoveVowels.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RemoveVowels.dir/clean

CMakeFiles/RemoveVowels.dir/depend:
	cd /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build /home/maciej/Documents/MyTasks/MaciejSalamonski/removeVowels/build/CMakeFiles/RemoveVowels.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RemoveVowels.dir/depend

