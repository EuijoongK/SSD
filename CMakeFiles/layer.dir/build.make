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
CMAKE_SOURCE_DIR = /mnt/c/Users/MICS/Desktop/Mobilenet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/MICS/Desktop/Mobilenet

# Include any dependencies generated for this target.
include CMakeFiles/layer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/layer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/layer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/layer.dir/flags.make

CMakeFiles/layer.dir/src/core/core.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/core/core.cpp.o: src/core/core.cpp
CMakeFiles/layer.dir/src/core/core.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/layer.dir/src/core/core.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/core/core.cpp.o -MF CMakeFiles/layer.dir/src/core/core.cpp.o.d -o CMakeFiles/layer.dir/src/core/core.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/core/core.cpp

CMakeFiles/layer.dir/src/core/core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/core/core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/core/core.cpp > CMakeFiles/layer.dir/src/core/core.cpp.i

CMakeFiles/layer.dir/src/core/core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/core/core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/core/core.cpp -o CMakeFiles/layer.dir/src/core/core.cpp.s

CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o: src/layer/zeropadding.cpp
CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o -MF CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o.d -o CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/zeropadding.cpp

CMakeFiles/layer.dir/src/layer/zeropadding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/zeropadding.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/zeropadding.cpp > CMakeFiles/layer.dir/src/layer/zeropadding.cpp.i

CMakeFiles/layer.dir/src/layer/zeropadding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/zeropadding.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/zeropadding.cpp -o CMakeFiles/layer.dir/src/layer/zeropadding.cpp.s

CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o: src/layer/maxpooling.cpp
CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o -MF CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o.d -o CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/maxpooling.cpp

CMakeFiles/layer.dir/src/layer/maxpooling.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/maxpooling.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/maxpooling.cpp > CMakeFiles/layer.dir/src/layer/maxpooling.cpp.i

CMakeFiles/layer.dir/src/layer/maxpooling.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/maxpooling.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/maxpooling.cpp -o CMakeFiles/layer.dir/src/layer/maxpooling.cpp.s

CMakeFiles/layer.dir/src/layer/convolution.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/convolution.cpp.o: src/layer/convolution.cpp
CMakeFiles/layer.dir/src/layer/convolution.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/layer.dir/src/layer/convolution.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/convolution.cpp.o -MF CMakeFiles/layer.dir/src/layer/convolution.cpp.o.d -o CMakeFiles/layer.dir/src/layer/convolution.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/convolution.cpp

CMakeFiles/layer.dir/src/layer/convolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/convolution.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/convolution.cpp > CMakeFiles/layer.dir/src/layer/convolution.cpp.i

CMakeFiles/layer.dir/src/layer/convolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/convolution.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/convolution.cpp -o CMakeFiles/layer.dir/src/layer/convolution.cpp.s

CMakeFiles/layer.dir/src/layer/relu.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/relu.cpp.o: src/layer/relu.cpp
CMakeFiles/layer.dir/src/layer/relu.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/layer.dir/src/layer/relu.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/relu.cpp.o -MF CMakeFiles/layer.dir/src/layer/relu.cpp.o.d -o CMakeFiles/layer.dir/src/layer/relu.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/relu.cpp

CMakeFiles/layer.dir/src/layer/relu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/relu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/relu.cpp > CMakeFiles/layer.dir/src/layer/relu.cpp.i

CMakeFiles/layer.dir/src/layer/relu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/relu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/relu.cpp -o CMakeFiles/layer.dir/src/layer/relu.cpp.s

CMakeFiles/layer.dir/src/layer/fc.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/fc.cpp.o: src/layer/fc.cpp
CMakeFiles/layer.dir/src/layer/fc.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/layer.dir/src/layer/fc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/fc.cpp.o -MF CMakeFiles/layer.dir/src/layer/fc.cpp.o.d -o CMakeFiles/layer.dir/src/layer/fc.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/fc.cpp

CMakeFiles/layer.dir/src/layer/fc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/fc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/fc.cpp > CMakeFiles/layer.dir/src/layer/fc.cpp.i

CMakeFiles/layer.dir/src/layer/fc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/fc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/fc.cpp -o CMakeFiles/layer.dir/src/layer/fc.cpp.s

CMakeFiles/layer.dir/src/layer/softmax.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/layer/softmax.cpp.o: src/layer/softmax.cpp
CMakeFiles/layer.dir/src/layer/softmax.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/layer.dir/src/layer/softmax.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/layer/softmax.cpp.o -MF CMakeFiles/layer.dir/src/layer/softmax.cpp.o.d -o CMakeFiles/layer.dir/src/layer/softmax.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/softmax.cpp

CMakeFiles/layer.dir/src/layer/softmax.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/layer/softmax.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/softmax.cpp > CMakeFiles/layer.dir/src/layer/softmax.cpp.i

CMakeFiles/layer.dir/src/layer/softmax.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/layer/softmax.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/layer/softmax.cpp -o CMakeFiles/layer.dir/src/layer/softmax.cpp.s

CMakeFiles/layer.dir/src/network/model.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/network/model.cpp.o: src/network/model.cpp
CMakeFiles/layer.dir/src/network/model.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/layer.dir/src/network/model.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/network/model.cpp.o -MF CMakeFiles/layer.dir/src/network/model.cpp.o.d -o CMakeFiles/layer.dir/src/network/model.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/network/model.cpp

CMakeFiles/layer.dir/src/network/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/network/model.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/network/model.cpp > CMakeFiles/layer.dir/src/network/model.cpp.i

CMakeFiles/layer.dir/src/network/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/network/model.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/network/model.cpp -o CMakeFiles/layer.dir/src/network/model.cpp.s

CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o: CMakeFiles/layer.dir/flags.make
CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o: src/datahandler/datahandler.cpp
CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o: CMakeFiles/layer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o -MF CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o.d -o CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o -c /mnt/c/Users/MICS/Desktop/Mobilenet/src/datahandler/datahandler.cpp

CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/MICS/Desktop/Mobilenet/src/datahandler/datahandler.cpp > CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.i

CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/MICS/Desktop/Mobilenet/src/datahandler/datahandler.cpp -o CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.s

# Object files for target layer
layer_OBJECTS = \
"CMakeFiles/layer.dir/src/core/core.cpp.o" \
"CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o" \
"CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o" \
"CMakeFiles/layer.dir/src/layer/convolution.cpp.o" \
"CMakeFiles/layer.dir/src/layer/relu.cpp.o" \
"CMakeFiles/layer.dir/src/layer/fc.cpp.o" \
"CMakeFiles/layer.dir/src/layer/softmax.cpp.o" \
"CMakeFiles/layer.dir/src/network/model.cpp.o" \
"CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o"

# External object files for target layer
layer_EXTERNAL_OBJECTS =

liblayer.a: CMakeFiles/layer.dir/src/core/core.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/zeropadding.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/maxpooling.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/convolution.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/relu.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/fc.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/layer/softmax.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/network/model.cpp.o
liblayer.a: CMakeFiles/layer.dir/src/datahandler/datahandler.cpp.o
liblayer.a: CMakeFiles/layer.dir/build.make
liblayer.a: CMakeFiles/layer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library liblayer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/layer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/layer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/layer.dir/build: liblayer.a
.PHONY : CMakeFiles/layer.dir/build

CMakeFiles/layer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/layer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/layer.dir/clean

CMakeFiles/layer.dir/depend:
	cd /mnt/c/Users/MICS/Desktop/Mobilenet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/MICS/Desktop/Mobilenet /mnt/c/Users/MICS/Desktop/Mobilenet /mnt/c/Users/MICS/Desktop/Mobilenet /mnt/c/Users/MICS/Desktop/Mobilenet /mnt/c/Users/MICS/Desktop/Mobilenet/CMakeFiles/layer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/layer.dir/depend

