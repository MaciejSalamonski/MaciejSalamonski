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
CMAKE_SOURCE_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build

# Include any dependencies generated for this target.
include CMakeFiles/NwdNww.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NwdNww.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NwdNww.dir/flags.make

CMakeFiles/NwdNww.dir/main.cpp.o: CMakeFiles/NwdNww.dir/flags.make
CMakeFiles/NwdNww.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NwdNww.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NwdNww.dir/main.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/main.cpp

CMakeFiles/NwdNww.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NwdNww.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/main.cpp > CMakeFiles/NwdNww.dir/main.cpp.i

CMakeFiles/NwdNww.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NwdNww.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/main.cpp -o CMakeFiles/NwdNww.dir/main.cpp.s

CMakeFiles/NwdNww.dir/nwdNww.cpp.o: CMakeFiles/NwdNww.dir/flags.make
CMakeFiles/NwdNww.dir/nwdNww.cpp.o: ../nwdNww.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NwdNww.dir/nwdNww.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NwdNww.dir/nwdNww.cpp.o -c /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/nwdNww.cpp

CMakeFiles/NwdNww.dir/nwdNww.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NwdNww.dir/nwdNww.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/nwdNww.cpp > CMakeFiles/NwdNww.dir/nwdNww.cpp.i

CMakeFiles/NwdNww.dir/nwdNww.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NwdNww.dir/nwdNww.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/nwdNww.cpp -o CMakeFiles/NwdNww.dir/nwdNww.cpp.s

# Object files for target NwdNww
NwdNww_OBJECTS = \
"CMakeFiles/NwdNww.dir/main.cpp.o" \
"CMakeFiles/NwdNww.dir/nwdNww.cpp.o"

# External object files for target NwdNww
NwdNww_EXTERNAL_OBJECTS =

NwdNww: CMakeFiles/NwdNww.dir/main.cpp.o
NwdNww: CMakeFiles/NwdNww.dir/nwdNww.cpp.o
NwdNww: CMakeFiles/NwdNww.dir/build.make
NwdNww: CMakeFiles/NwdNww.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable NwdNww"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NwdNww.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NwdNww.dir/build: NwdNww

.PHONY : CMakeFiles/NwdNww.dir/build

CMakeFiles/NwdNww.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NwdNww.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NwdNww.dir/clean

CMakeFiles/NwdNww.dir/depend:
	cd /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build /home/maciej/Documents/MyTasks/MaciejSalamonski/NwdNww/build/CMakeFiles/NwdNww.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NwdNww.dir/depend
