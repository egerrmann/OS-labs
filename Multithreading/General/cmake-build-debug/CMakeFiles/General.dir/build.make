# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/General.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/General.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/General.dir/flags.make

CMakeFiles/General.dir/main.cpp.obj: CMakeFiles/General.dir/flags.make
CMakeFiles/General.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/General.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\General.dir\main.cpp.obj -c "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\main.cpp"

CMakeFiles/General.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/General.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\main.cpp" > CMakeFiles\General.dir\main.cpp.i

CMakeFiles/General.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/General.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\main.cpp" -o CMakeFiles\General.dir\main.cpp.s

# Object files for target General
General_OBJECTS = \
"CMakeFiles/General.dir/main.cpp.obj"

# External object files for target General
General_EXTERNAL_OBJECTS =

General.exe: CMakeFiles/General.dir/main.cpp.obj
General.exe: CMakeFiles/General.dir/build.make
General.exe: CMakeFiles/General.dir/linklibs.rsp
General.exe: CMakeFiles/General.dir/objects1.rsp
General.exe: CMakeFiles/General.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable General.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\General.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/General.dir/build: General.exe
.PHONY : CMakeFiles/General.dir/build

CMakeFiles/General.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\General.dir\cmake_clean.cmake
.PHONY : CMakeFiles/General.dir/clean

CMakeFiles/General.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\General\cmake-build-debug\CMakeFiles\General.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/General.dir/depend
