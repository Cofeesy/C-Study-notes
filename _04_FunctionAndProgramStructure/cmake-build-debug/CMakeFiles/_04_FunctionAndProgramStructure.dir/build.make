# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = E:\CMake\bin\cmake.exe

# The command to remove a file.
RM = E:\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\C Projects\_04_FunctionAndProgramStructure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/_04_FunctionAndProgramStructure.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_04_FunctionAndProgramStructure.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_04_FunctionAndProgramStructure.dir/flags.make

CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.obj: CMakeFiles/_04_FunctionAndProgramStructure.dir/flags.make
CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.obj"
	E:\GCC\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\_04_FunctionAndProgramStructure.dir\main.c.obj   -c "E:\C Projects\_04_FunctionAndProgramStructure\main.c"

CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.i"
	E:\GCC\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\C Projects\_04_FunctionAndProgramStructure\main.c" > CMakeFiles\_04_FunctionAndProgramStructure.dir\main.c.i

CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.s"
	E:\GCC\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\C Projects\_04_FunctionAndProgramStructure\main.c" -o CMakeFiles\_04_FunctionAndProgramStructure.dir\main.c.s

# Object files for target _04_FunctionAndProgramStructure
_04_FunctionAndProgramStructure_OBJECTS = \
"CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.obj"

# External object files for target _04_FunctionAndProgramStructure
_04_FunctionAndProgramStructure_EXTERNAL_OBJECTS =

_04_FunctionAndProgramStructure.exe: CMakeFiles/_04_FunctionAndProgramStructure.dir/main.c.obj
_04_FunctionAndProgramStructure.exe: CMakeFiles/_04_FunctionAndProgramStructure.dir/build.make
_04_FunctionAndProgramStructure.exe: CMakeFiles/_04_FunctionAndProgramStructure.dir/linklibs.rsp
_04_FunctionAndProgramStructure.exe: CMakeFiles/_04_FunctionAndProgramStructure.dir/objects1.rsp
_04_FunctionAndProgramStructure.exe: CMakeFiles/_04_FunctionAndProgramStructure.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable _04_FunctionAndProgramStructure.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\_04_FunctionAndProgramStructure.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_04_FunctionAndProgramStructure.dir/build: _04_FunctionAndProgramStructure.exe

.PHONY : CMakeFiles/_04_FunctionAndProgramStructure.dir/build

CMakeFiles/_04_FunctionAndProgramStructure.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\_04_FunctionAndProgramStructure.dir\cmake_clean.cmake
.PHONY : CMakeFiles/_04_FunctionAndProgramStructure.dir/clean

CMakeFiles/_04_FunctionAndProgramStructure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\C Projects\_04_FunctionAndProgramStructure" "E:\C Projects\_04_FunctionAndProgramStructure" "E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug" "E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug" "E:\C Projects\_04_FunctionAndProgramStructure\cmake-build-debug\CMakeFiles\_04_FunctionAndProgramStructure.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/_04_FunctionAndProgramStructure.dir/depend

