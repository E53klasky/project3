# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adios/project3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adios/project3/build

# Include any dependencies generated for this target.
include CMakeFiles/image-processor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/image-processor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/image-processor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/image-processor.dir/flags.make

CMakeFiles/image-processor.dir/main.cpp.o: CMakeFiles/image-processor.dir/flags.make
CMakeFiles/image-processor.dir/main.cpp.o: /home/adios/project3/main.cpp
CMakeFiles/image-processor.dir/main.cpp.o: CMakeFiles/image-processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adios/project3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/image-processor.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image-processor.dir/main.cpp.o -MF CMakeFiles/image-processor.dir/main.cpp.o.d -o CMakeFiles/image-processor.dir/main.cpp.o -c /home/adios/project3/main.cpp

CMakeFiles/image-processor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image-processor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adios/project3/main.cpp > CMakeFiles/image-processor.dir/main.cpp.i

CMakeFiles/image-processor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image-processor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adios/project3/main.cpp -o CMakeFiles/image-processor.dir/main.cpp.s

CMakeFiles/image-processor.dir/image.cpp.o: CMakeFiles/image-processor.dir/flags.make
CMakeFiles/image-processor.dir/image.cpp.o: /home/adios/project3/image.cpp
CMakeFiles/image-processor.dir/image.cpp.o: CMakeFiles/image-processor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/adios/project3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/image-processor.dir/image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/image-processor.dir/image.cpp.o -MF CMakeFiles/image-processor.dir/image.cpp.o.d -o CMakeFiles/image-processor.dir/image.cpp.o -c /home/adios/project3/image.cpp

CMakeFiles/image-processor.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/image-processor.dir/image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adios/project3/image.cpp > CMakeFiles/image-processor.dir/image.cpp.i

CMakeFiles/image-processor.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/image-processor.dir/image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adios/project3/image.cpp -o CMakeFiles/image-processor.dir/image.cpp.s

# Object files for target image-processor
image__processor_OBJECTS = \
"CMakeFiles/image-processor.dir/main.cpp.o" \
"CMakeFiles/image-processor.dir/image.cpp.o"

# External object files for target image-processor
image__processor_EXTERNAL_OBJECTS =

image-processor: CMakeFiles/image-processor.dir/main.cpp.o
image-processor: CMakeFiles/image-processor.dir/image.cpp.o
image-processor: CMakeFiles/image-processor.dir/build.make
image-processor: CMakeFiles/image-processor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/adios/project3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable image-processor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/image-processor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/image-processor.dir/build: image-processor
.PHONY : CMakeFiles/image-processor.dir/build

CMakeFiles/image-processor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/image-processor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/image-processor.dir/clean

CMakeFiles/image-processor.dir/depend:
	cd /home/adios/project3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adios/project3 /home/adios/project3 /home/adios/project3/build /home/adios/project3/build /home/adios/project3/build/CMakeFiles/image-processor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/image-processor.dir/depend

