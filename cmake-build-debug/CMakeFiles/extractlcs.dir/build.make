# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /home/cleopinoli/Desktop/clion-2021.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/cleopinoli/Desktop/clion-2021.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/extractlcs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/extractlcs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/extractlcs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/extractlcs.dir/flags.make

CMakeFiles/extractlcs.dir/extractlcs.c.o: CMakeFiles/extractlcs.dir/flags.make
CMakeFiles/extractlcs.dir/extractlcs.c.o: ../extractlcs.c
CMakeFiles/extractlcs.dir/extractlcs.c.o: CMakeFiles/extractlcs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/extractlcs.dir/extractlcs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/extractlcs.dir/extractlcs.c.o -MF CMakeFiles/extractlcs.dir/extractlcs.c.o.d -o CMakeFiles/extractlcs.dir/extractlcs.c.o -c /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/extractlcs.c

CMakeFiles/extractlcs.dir/extractlcs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extractlcs.dir/extractlcs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/extractlcs.c > CMakeFiles/extractlcs.dir/extractlcs.c.i

CMakeFiles/extractlcs.dir/extractlcs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extractlcs.dir/extractlcs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/extractlcs.c -o CMakeFiles/extractlcs.dir/extractlcs.c.s

CMakeFiles/extractlcs.dir/main.c.o: CMakeFiles/extractlcs.dir/flags.make
CMakeFiles/extractlcs.dir/main.c.o: ../main.c
CMakeFiles/extractlcs.dir/main.c.o: CMakeFiles/extractlcs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/extractlcs.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/extractlcs.dir/main.c.o -MF CMakeFiles/extractlcs.dir/main.c.o.d -o CMakeFiles/extractlcs.dir/main.c.o -c /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/main.c

CMakeFiles/extractlcs.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extractlcs.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/main.c > CMakeFiles/extractlcs.dir/main.c.i

CMakeFiles/extractlcs.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extractlcs.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/main.c -o CMakeFiles/extractlcs.dir/main.c.s

CMakeFiles/extractlcs.dir/io_mgmt.c.o: CMakeFiles/extractlcs.dir/flags.make
CMakeFiles/extractlcs.dir/io_mgmt.c.o: ../io_mgmt.c
CMakeFiles/extractlcs.dir/io_mgmt.c.o: CMakeFiles/extractlcs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/extractlcs.dir/io_mgmt.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/extractlcs.dir/io_mgmt.c.o -MF CMakeFiles/extractlcs.dir/io_mgmt.c.o.d -o CMakeFiles/extractlcs.dir/io_mgmt.c.o -c /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/io_mgmt.c

CMakeFiles/extractlcs.dir/io_mgmt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/extractlcs.dir/io_mgmt.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/io_mgmt.c > CMakeFiles/extractlcs.dir/io_mgmt.c.i

CMakeFiles/extractlcs.dir/io_mgmt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/extractlcs.dir/io_mgmt.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/io_mgmt.c -o CMakeFiles/extractlcs.dir/io_mgmt.c.s

# Object files for target extractlcs
extractlcs_OBJECTS = \
"CMakeFiles/extractlcs.dir/extractlcs.c.o" \
"CMakeFiles/extractlcs.dir/main.c.o" \
"CMakeFiles/extractlcs.dir/io_mgmt.c.o"

# External object files for target extractlcs
extractlcs_EXTERNAL_OBJECTS =

../extractlcs: CMakeFiles/extractlcs.dir/extractlcs.c.o
../extractlcs: CMakeFiles/extractlcs.dir/main.c.o
../extractlcs: CMakeFiles/extractlcs.dir/io_mgmt.c.o
../extractlcs: CMakeFiles/extractlcs.dir/build.make
../extractlcs: CMakeFiles/extractlcs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable ../extractlcs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/extractlcs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/extractlcs.dir/build: ../extractlcs
.PHONY : CMakeFiles/extractlcs.dir/build

CMakeFiles/extractlcs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/extractlcs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/extractlcs.dir/clean

CMakeFiles/extractlcs.dir/depend:
	cd /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368 /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368 /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug /home/cleopinoli/Documents/GitHub/ClaudiaRaffaelli105368/cmake-build-debug/CMakeFiles/extractlcs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/extractlcs.dir/depend

