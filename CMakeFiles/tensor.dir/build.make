# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/MICS/Desktop/proj/SSD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/MICS/Desktop/proj/SSD

# Include any dependencies generated for this target.
include CMakeFiles/tensor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tensor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tensor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tensor.dir/flags.make

CMakeFiles/tensor.dir/src/tensor/tensor.c.o: CMakeFiles/tensor.dir/flags.make
CMakeFiles/tensor.dir/src/tensor/tensor.c.o: src/tensor/tensor.c
CMakeFiles/tensor.dir/src/tensor/tensor.c.o: CMakeFiles/tensor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tensor.dir/src/tensor/tensor.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/tensor.dir/src/tensor/tensor.c.o -MF CMakeFiles/tensor.dir/src/tensor/tensor.c.o.d -o CMakeFiles/tensor.dir/src/tensor/tensor.c.o -c /mnt/c/Users/MICS/Desktop/proj/SSD/src/tensor/tensor.c

CMakeFiles/tensor.dir/src/tensor/tensor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tensor.dir/src/tensor/tensor.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/MICS/Desktop/proj/SSD/src/tensor/tensor.c > CMakeFiles/tensor.dir/src/tensor/tensor.c.i

CMakeFiles/tensor.dir/src/tensor/tensor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tensor.dir/src/tensor/tensor.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/MICS/Desktop/proj/SSD/src/tensor/tensor.c -o CMakeFiles/tensor.dir/src/tensor/tensor.c.s

# Object files for target tensor
tensor_OBJECTS = \
"CMakeFiles/tensor.dir/src/tensor/tensor.c.o"

# External object files for target tensor
tensor_EXTERNAL_OBJECTS =

lib/libtensor.a: CMakeFiles/tensor.dir/src/tensor/tensor.c.o
lib/libtensor.a: CMakeFiles/tensor.dir/build.make
lib/libtensor.a: CMakeFiles/tensor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library lib/libtensor.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tensor.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tensor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tensor.dir/build: lib/libtensor.a
.PHONY : CMakeFiles/tensor.dir/build

CMakeFiles/tensor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tensor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tensor.dir/clean

CMakeFiles/tensor.dir/depend:
	cd /mnt/c/Users/MICS/Desktop/proj/SSD && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles/tensor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tensor.dir/depend

