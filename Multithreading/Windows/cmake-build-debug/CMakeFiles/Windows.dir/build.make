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
CMAKE_SOURCE_DIR = "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Windows.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Windows.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Windows.dir/flags.make

CMakeFiles/Windows.dir/main.cpp.obj: CMakeFiles/Windows.dir/flags.make
CMakeFiles/Windows.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Windows.dir/main.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Windows.dir\main.cpp.obj -c "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\main.cpp"

CMakeFiles/Windows.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Windows.dir/main.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\main.cpp" > CMakeFiles\Windows.dir\main.cpp.i

CMakeFiles/Windows.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Windows.dir/main.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\main.cpp" -o CMakeFiles\Windows.dir\main.cpp.s

# Object files for target Windows
Windows_OBJECTS = \
"CMakeFiles/Windows.dir/main.cpp.obj"

# External object files for target Windows
Windows_EXTERNAL_OBJECTS =

Windows.exe: CMakeFiles/Windows.dir/main.cpp.obj
Windows.exe: CMakeFiles/Windows.dir/build.make
Windows.exe: CMakeFiles/Windows.dir/linklibs.rsp
Windows.exe: CMakeFiles/Windows.dir/objects1.rsp
Windows.exe: CMakeFiles/Windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Windows.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Windows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Windows.dir/build: Windows.exe
.PHONY : CMakeFiles/Windows.dir/build

CMakeFiles/Windows.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Windows.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Windows.dir/clean

CMakeFiles/Windows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug" "C:\Studying\Programming\C++\Derevyago\2nd course\OS labs\Multithreading\Windows\cmake-build-debug\CMakeFiles\Windows.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Windows.dir/depend

