# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.1.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ADTJam.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ADTJam.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ADTJam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ADTJam.dir/flags.make

CMakeFiles/ADTJam.dir/main.c.obj: CMakeFiles/ADTJam.dir/flags.make
CMakeFiles/ADTJam.dir/main.c.obj: C:/Users/aibnu/OneDrive/Documents/Tugas-pemrograman/YasirNoval/strukturData/pertemuan1/ADTJam/main.c
CMakeFiles/ADTJam.dir/main.c.obj: CMakeFiles/ADTJam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ADTJam.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ADTJam.dir/main.c.obj -MF CMakeFiles\ADTJam.dir\main.c.obj.d -o CMakeFiles\ADTJam.dir\main.c.obj -c C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\main.c

CMakeFiles/ADTJam.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ADTJam.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\main.c > CMakeFiles\ADTJam.dir\main.c.i

CMakeFiles/ADTJam.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ADTJam.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.2\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\main.c -o CMakeFiles\ADTJam.dir\main.c.s

# Object files for target ADTJam
ADTJam_OBJECTS = \
"CMakeFiles/ADTJam.dir/main.c.obj"

# External object files for target ADTJam
ADTJam_EXTERNAL_OBJECTS =

ADTJam.exe: CMakeFiles/ADTJam.dir/main.c.obj
ADTJam.exe: CMakeFiles/ADTJam.dir/build.make
ADTJam.exe: CMakeFiles/ADTJam.dir/linkLibs.rsp
ADTJam.exe: CMakeFiles/ADTJam.dir/objects1.rsp
ADTJam.exe: CMakeFiles/ADTJam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ADTJam.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ADTJam.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ADTJam.dir/build: ADTJam.exe
.PHONY : CMakeFiles/ADTJam.dir/build

CMakeFiles/ADTJam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ADTJam.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ADTJam.dir/clean

CMakeFiles/ADTJam.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug C:\Users\aibnu\OneDrive\Documents\Tugas-pemrograman\YasirNoval\strukturData\pertemuan1\ADTJam\cmake-build-debug\CMakeFiles\ADTJam.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ADTJam.dir/depend
