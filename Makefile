# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/damian_koper/Documents/GitHub/gkLab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/damian_koper/Documents/GitHub/gkLab

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/damian_koper/Documents/GitHub/gkLab/CMakeFiles /home/damian_koper/Documents/GitHub/gkLab/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/damian_koper/Documents/GitHub/gkLab/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

src/DrawingUtils.o: src/DrawingUtils.cpp.o

.PHONY : src/DrawingUtils.o

# target to build an object file
src/DrawingUtils.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/DrawingUtils.cpp.o
.PHONY : src/DrawingUtils.cpp.o

src/DrawingUtils.i: src/DrawingUtils.cpp.i

.PHONY : src/DrawingUtils.i

# target to preprocess a source file
src/DrawingUtils.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/DrawingUtils.cpp.i
.PHONY : src/DrawingUtils.cpp.i

src/DrawingUtils.s: src/DrawingUtils.cpp.s

.PHONY : src/DrawingUtils.s

# target to generate assembly for a file
src/DrawingUtils.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/DrawingUtils.cpp.s
.PHONY : src/DrawingUtils.cpp.s

src/NumericUtils.o: src/NumericUtils.cpp.o

.PHONY : src/NumericUtils.o

# target to build an object file
src/NumericUtils.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/NumericUtils.cpp.o
.PHONY : src/NumericUtils.cpp.o

src/NumericUtils.i: src/NumericUtils.cpp.i

.PHONY : src/NumericUtils.i

# target to preprocess a source file
src/NumericUtils.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/NumericUtils.cpp.i
.PHONY : src/NumericUtils.cpp.i

src/NumericUtils.s: src/NumericUtils.cpp.s

.PHONY : src/NumericUtils.s

# target to generate assembly for a file
src/NumericUtils.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/NumericUtils.cpp.s
.PHONY : src/NumericUtils.cpp.s

src/Point.o: src/Point.cpp.o

.PHONY : src/Point.o

# target to build an object file
src/Point.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Point.cpp.o
.PHONY : src/Point.cpp.o

src/Point.i: src/Point.cpp.i

.PHONY : src/Point.i

# target to preprocess a source file
src/Point.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Point.cpp.i
.PHONY : src/Point.cpp.i

src/Point.s: src/Point.cpp.s

.PHONY : src/Point.s

# target to generate assembly for a file
src/Point.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Point.cpp.s
.PHONY : src/Point.cpp.s

src/ViewEngine/ViewEngine.o: src/ViewEngine/ViewEngine.cpp.o

.PHONY : src/ViewEngine/ViewEngine.o

# target to build an object file
src/ViewEngine/ViewEngine.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ViewEngine/ViewEngine.cpp.o
.PHONY : src/ViewEngine/ViewEngine.cpp.o

src/ViewEngine/ViewEngine.i: src/ViewEngine/ViewEngine.cpp.i

.PHONY : src/ViewEngine/ViewEngine.i

# target to preprocess a source file
src/ViewEngine/ViewEngine.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ViewEngine/ViewEngine.cpp.i
.PHONY : src/ViewEngine/ViewEngine.cpp.i

src/ViewEngine/ViewEngine.s: src/ViewEngine/ViewEngine.cpp.s

.PHONY : src/ViewEngine/ViewEngine.s

# target to generate assembly for a file
src/ViewEngine/ViewEngine.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/ViewEngine/ViewEngine.cpp.s
.PHONY : src/ViewEngine/ViewEngine.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/models/Egg.o: src/models/Egg.cpp.o

.PHONY : src/models/Egg.o

# target to build an object file
src/models/Egg.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/models/Egg.cpp.o
.PHONY : src/models/Egg.cpp.o

src/models/Egg.i: src/models/Egg.cpp.i

.PHONY : src/models/Egg.i

# target to preprocess a source file
src/models/Egg.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/models/Egg.cpp.i
.PHONY : src/models/Egg.cpp.i

src/models/Egg.s: src/models/Egg.cpp.s

.PHONY : src/models/Egg.s

# target to generate assembly for a file
src/models/Egg.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/models/Egg.cpp.s
.PHONY : src/models/Egg.cpp.s

src/views/DotEggView.o: src/views/DotEggView.cpp.o

.PHONY : src/views/DotEggView.o

# target to build an object file
src/views/DotEggView.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/DotEggView.cpp.o
.PHONY : src/views/DotEggView.cpp.o

src/views/DotEggView.i: src/views/DotEggView.cpp.i

.PHONY : src/views/DotEggView.i

# target to preprocess a source file
src/views/DotEggView.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/DotEggView.cpp.i
.PHONY : src/views/DotEggView.cpp.i

src/views/DotEggView.s: src/views/DotEggView.cpp.s

.PHONY : src/views/DotEggView.s

# target to generate assembly for a file
src/views/DotEggView.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/DotEggView.cpp.s
.PHONY : src/views/DotEggView.cpp.s

src/views/MeshEggView.o: src/views/MeshEggView.cpp.o

.PHONY : src/views/MeshEggView.o

# target to build an object file
src/views/MeshEggView.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/MeshEggView.cpp.o
.PHONY : src/views/MeshEggView.cpp.o

src/views/MeshEggView.i: src/views/MeshEggView.cpp.i

.PHONY : src/views/MeshEggView.i

# target to preprocess a source file
src/views/MeshEggView.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/MeshEggView.cpp.i
.PHONY : src/views/MeshEggView.cpp.i

src/views/MeshEggView.s: src/views/MeshEggView.cpp.s

.PHONY : src/views/MeshEggView.s

# target to generate assembly for a file
src/views/MeshEggView.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/MeshEggView.cpp.s
.PHONY : src/views/MeshEggView.cpp.s

src/views/TeapotView.o: src/views/TeapotView.cpp.o

.PHONY : src/views/TeapotView.o

# target to build an object file
src/views/TeapotView.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TeapotView.cpp.o
.PHONY : src/views/TeapotView.cpp.o

src/views/TeapotView.i: src/views/TeapotView.cpp.i

.PHONY : src/views/TeapotView.i

# target to preprocess a source file
src/views/TeapotView.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TeapotView.cpp.i
.PHONY : src/views/TeapotView.cpp.i

src/views/TeapotView.s: src/views/TeapotView.cpp.s

.PHONY : src/views/TeapotView.s

# target to generate assembly for a file
src/views/TeapotView.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TeapotView.cpp.s
.PHONY : src/views/TeapotView.cpp.s

src/views/TrianglesEggView.o: src/views/TrianglesEggView.cpp.o

.PHONY : src/views/TrianglesEggView.o

# target to build an object file
src/views/TrianglesEggView.cpp.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TrianglesEggView.cpp.o
.PHONY : src/views/TrianglesEggView.cpp.o

src/views/TrianglesEggView.i: src/views/TrianglesEggView.cpp.i

.PHONY : src/views/TrianglesEggView.i

# target to preprocess a source file
src/views/TrianglesEggView.cpp.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TrianglesEggView.cpp.i
.PHONY : src/views/TrianglesEggView.cpp.i

src/views/TrianglesEggView.s: src/views/TrianglesEggView.cpp.s

.PHONY : src/views/TrianglesEggView.s

# target to generate assembly for a file
src/views/TrianglesEggView.cpp.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/views/TrianglesEggView.cpp.s
.PHONY : src/views/TrianglesEggView.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... main"
	@echo "... edit_cache"
	@echo "... src/DrawingUtils.o"
	@echo "... src/DrawingUtils.i"
	@echo "... src/DrawingUtils.s"
	@echo "... src/NumericUtils.o"
	@echo "... src/NumericUtils.i"
	@echo "... src/NumericUtils.s"
	@echo "... src/Point.o"
	@echo "... src/Point.i"
	@echo "... src/Point.s"
	@echo "... src/ViewEngine/ViewEngine.o"
	@echo "... src/ViewEngine/ViewEngine.i"
	@echo "... src/ViewEngine/ViewEngine.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/models/Egg.o"
	@echo "... src/models/Egg.i"
	@echo "... src/models/Egg.s"
	@echo "... src/views/DotEggView.o"
	@echo "... src/views/DotEggView.i"
	@echo "... src/views/DotEggView.s"
	@echo "... src/views/MeshEggView.o"
	@echo "... src/views/MeshEggView.i"
	@echo "... src/views/MeshEggView.s"
	@echo "... src/views/TeapotView.o"
	@echo "... src/views/TeapotView.i"
	@echo "... src/views/TeapotView.s"
	@echo "... src/views/TrianglesEggView.o"
	@echo "... src/views/TrianglesEggView.i"
	@echo "... src/views/TrianglesEggView.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

