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
include CMakeFiles/model.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/model.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/model.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/model.dir/flags.make

CMakeFiles/model.dir/src/model/vgg.c.o: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/src/model/vgg.c.o: src/model/vgg.c
CMakeFiles/model.dir/src/model/vgg.c.o: CMakeFiles/model.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/model.dir/src/model/vgg.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/model.dir/src/model/vgg.c.o -MF CMakeFiles/model.dir/src/model/vgg.c.o.d -o CMakeFiles/model.dir/src/model/vgg.c.o -c /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/vgg.c

CMakeFiles/model.dir/src/model/vgg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/src/model/vgg.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/vgg.c > CMakeFiles/model.dir/src/model/vgg.c.i

CMakeFiles/model.dir/src/model/vgg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/src/model/vgg.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/vgg.c -o CMakeFiles/model.dir/src/model/vgg.c.s

CMakeFiles/model.dir/src/model/auxiliary.c.o: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/src/model/auxiliary.c.o: src/model/auxiliary.c
CMakeFiles/model.dir/src/model/auxiliary.c.o: CMakeFiles/model.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/model.dir/src/model/auxiliary.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/model.dir/src/model/auxiliary.c.o -MF CMakeFiles/model.dir/src/model/auxiliary.c.o.d -o CMakeFiles/model.dir/src/model/auxiliary.c.o -c /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/auxiliary.c

CMakeFiles/model.dir/src/model/auxiliary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/src/model/auxiliary.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/auxiliary.c > CMakeFiles/model.dir/src/model/auxiliary.c.i

CMakeFiles/model.dir/src/model/auxiliary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/src/model/auxiliary.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/auxiliary.c -o CMakeFiles/model.dir/src/model/auxiliary.c.s

CMakeFiles/model.dir/src/model/predict.c.o: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/src/model/predict.c.o: src/model/predict.c
CMakeFiles/model.dir/src/model/predict.c.o: CMakeFiles/model.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/model.dir/src/model/predict.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/model.dir/src/model/predict.c.o -MF CMakeFiles/model.dir/src/model/predict.c.o.d -o CMakeFiles/model.dir/src/model/predict.c.o -c /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/predict.c

CMakeFiles/model.dir/src/model/predict.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/src/model/predict.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/predict.c > CMakeFiles/model.dir/src/model/predict.c.i

CMakeFiles/model.dir/src/model/predict.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/src/model/predict.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/predict.c -o CMakeFiles/model.dir/src/model/predict.c.s

CMakeFiles/model.dir/src/model/ssd.c.o: CMakeFiles/model.dir/flags.make
CMakeFiles/model.dir/src/model/ssd.c.o: src/model/ssd.c
CMakeFiles/model.dir/src/model/ssd.c.o: CMakeFiles/model.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/model.dir/src/model/ssd.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/model.dir/src/model/ssd.c.o -MF CMakeFiles/model.dir/src/model/ssd.c.o.d -o CMakeFiles/model.dir/src/model/ssd.c.o -c /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/ssd.c

CMakeFiles/model.dir/src/model/ssd.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/model.dir/src/model/ssd.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/ssd.c > CMakeFiles/model.dir/src/model/ssd.c.i

CMakeFiles/model.dir/src/model/ssd.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/model.dir/src/model/ssd.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/MICS/Desktop/proj/SSD/src/model/ssd.c -o CMakeFiles/model.dir/src/model/ssd.c.s

# Object files for target model
model_OBJECTS = \
"CMakeFiles/model.dir/src/model/vgg.c.o" \
"CMakeFiles/model.dir/src/model/auxiliary.c.o" \
"CMakeFiles/model.dir/src/model/predict.c.o" \
"CMakeFiles/model.dir/src/model/ssd.c.o"

# External object files for target model
model_EXTERNAL_OBJECTS =

lib/libmodel.a: CMakeFiles/model.dir/src/model/vgg.c.o
lib/libmodel.a: CMakeFiles/model.dir/src/model/auxiliary.c.o
lib/libmodel.a: CMakeFiles/model.dir/src/model/predict.c.o
lib/libmodel.a: CMakeFiles/model.dir/src/model/ssd.c.o
lib/libmodel.a: CMakeFiles/model.dir/build.make
lib/libmodel.a: CMakeFiles/model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library lib/libmodel.a"
	$(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/model.dir/build: lib/libmodel.a
.PHONY : CMakeFiles/model.dir/build

CMakeFiles/model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/model.dir/clean

CMakeFiles/model.dir/depend:
	cd /mnt/c/Users/MICS/Desktop/proj/SSD && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD /mnt/c/Users/MICS/Desktop/proj/SSD/CMakeFiles/model.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/model.dir/depend
