# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/pengyao/CppProjects/py_leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pengyao/CppProjects/py_leetcode/build

# Include any dependencies generated for this target.
include CMakeFiles/dfs_79.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dfs_79.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dfs_79.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dfs_79.dir/flags.make

CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o: CMakeFiles/dfs_79.dir/flags.make
CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o: /home/pengyao/CppProjects/py_leetcode/src/dfs/79.cpp
CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o: CMakeFiles/dfs_79.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pengyao/CppProjects/py_leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o -MF CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o.d -o CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o -c /home/pengyao/CppProjects/py_leetcode/src/dfs/79.cpp

CMakeFiles/dfs_79.dir/src/dfs/79.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dfs_79.dir/src/dfs/79.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pengyao/CppProjects/py_leetcode/src/dfs/79.cpp > CMakeFiles/dfs_79.dir/src/dfs/79.cpp.i

CMakeFiles/dfs_79.dir/src/dfs/79.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dfs_79.dir/src/dfs/79.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pengyao/CppProjects/py_leetcode/src/dfs/79.cpp -o CMakeFiles/dfs_79.dir/src/dfs/79.cpp.s

# Object files for target dfs_79
dfs_79_OBJECTS = \
"CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o"

# External object files for target dfs_79
dfs_79_EXTERNAL_OBJECTS =

dfs/dfs_79: CMakeFiles/dfs_79.dir/src/dfs/79.cpp.o
dfs/dfs_79: CMakeFiles/dfs_79.dir/build.make
dfs/dfs_79: CMakeFiles/dfs_79.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/pengyao/CppProjects/py_leetcode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dfs/dfs_79"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dfs_79.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dfs_79.dir/build: dfs/dfs_79
.PHONY : CMakeFiles/dfs_79.dir/build

CMakeFiles/dfs_79.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dfs_79.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dfs_79.dir/clean

CMakeFiles/dfs_79.dir/depend:
	cd /home/pengyao/CppProjects/py_leetcode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pengyao/CppProjects/py_leetcode /home/pengyao/CppProjects/py_leetcode /home/pengyao/CppProjects/py_leetcode/build /home/pengyao/CppProjects/py_leetcode/build /home/pengyao/CppProjects/py_leetcode/build/CMakeFiles/dfs_79.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dfs_79.dir/depend

