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
CMAKE_COMMAND = /home/francis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/francis/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francis/Documents/Projects/Froyo/sht-sensor-lib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sht_sensor_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sht_sensor_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sht_sensor_lib.dir/flags.make

CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o: CMakeFiles/sht_sensor_lib.dir/flags.make
CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o: ../sht21.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o -c /home/francis/Documents/Projects/Froyo/sht-sensor-lib/sht21.cpp

CMakeFiles/sht_sensor_lib.dir/sht21.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sht_sensor_lib.dir/sht21.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francis/Documents/Projects/Froyo/sht-sensor-lib/sht21.cpp > CMakeFiles/sht_sensor_lib.dir/sht21.cpp.i

CMakeFiles/sht_sensor_lib.dir/sht21.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sht_sensor_lib.dir/sht21.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francis/Documents/Projects/Froyo/sht-sensor-lib/sht21.cpp -o CMakeFiles/sht_sensor_lib.dir/sht21.cpp.s

# Object files for target sht_sensor_lib
sht_sensor_lib_OBJECTS = \
"CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o"

# External object files for target sht_sensor_lib
sht_sensor_lib_EXTERNAL_OBJECTS =

sht_sensor_lib: CMakeFiles/sht_sensor_lib.dir/sht21.cpp.o
sht_sensor_lib: CMakeFiles/sht_sensor_lib.dir/build.make
sht_sensor_lib: CMakeFiles/sht_sensor_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sht_sensor_lib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sht_sensor_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sht_sensor_lib.dir/build: sht_sensor_lib

.PHONY : CMakeFiles/sht_sensor_lib.dir/build

CMakeFiles/sht_sensor_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sht_sensor_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sht_sensor_lib.dir/clean

CMakeFiles/sht_sensor_lib.dir/depend:
	cd /home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francis/Documents/Projects/Froyo/sht-sensor-lib /home/francis/Documents/Projects/Froyo/sht-sensor-lib /home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug /home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug /home/francis/Documents/Projects/Froyo/sht-sensor-lib/cmake-build-debug/CMakeFiles/sht_sensor_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sht_sensor_lib.dir/depend
