# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/sam/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/sam/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sam/Desktop/Sharare/Othello/Othello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Othello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Othello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Othello.dir/flags.make

CMakeFiles/Othello.dir/main.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Othello.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/main.cpp.o -c /home/sam/Desktop/Sharare/Othello/Othello/main.cpp

CMakeFiles/Othello.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/Desktop/Sharare/Othello/Othello/main.cpp > CMakeFiles/Othello.dir/main.cpp.i

CMakeFiles/Othello.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/Desktop/Sharare/Othello/Othello/main.cpp -o CMakeFiles/Othello.dir/main.cpp.s

CMakeFiles/Othello.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/main.cpp.o.requires

CMakeFiles/Othello.dir/main.cpp.o.provides: CMakeFiles/Othello.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/main.cpp.o.provides

CMakeFiles/Othello.dir/main.cpp.o.provides.build: CMakeFiles/Othello.dir/main.cpp.o


CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o: ../Sources/SetWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o -c /home/sam/Desktop/Sharare/Othello/Othello/Sources/SetWindow.cpp

CMakeFiles/Othello.dir/Sources/SetWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/Sources/SetWindow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/Desktop/Sharare/Othello/Othello/Sources/SetWindow.cpp > CMakeFiles/Othello.dir/Sources/SetWindow.cpp.i

CMakeFiles/Othello.dir/Sources/SetWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/Sources/SetWindow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/Desktop/Sharare/Othello/Othello/Sources/SetWindow.cpp -o CMakeFiles/Othello.dir/Sources/SetWindow.cpp.s

CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.requires

CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.provides: CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.provides

CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.provides.build: CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o


CMakeFiles/Othello.dir/Othello_automoc.cpp.o: CMakeFiles/Othello.dir/flags.make
CMakeFiles/Othello.dir/Othello_automoc.cpp.o: Othello_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Othello.dir/Othello_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Othello.dir/Othello_automoc.cpp.o -c /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/Othello_automoc.cpp

CMakeFiles/Othello.dir/Othello_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Othello.dir/Othello_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/Othello_automoc.cpp > CMakeFiles/Othello.dir/Othello_automoc.cpp.i

CMakeFiles/Othello.dir/Othello_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Othello.dir/Othello_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/Othello_automoc.cpp -o CMakeFiles/Othello.dir/Othello_automoc.cpp.s

CMakeFiles/Othello.dir/Othello_automoc.cpp.o.requires:

.PHONY : CMakeFiles/Othello.dir/Othello_automoc.cpp.o.requires

CMakeFiles/Othello.dir/Othello_automoc.cpp.o.provides: CMakeFiles/Othello.dir/Othello_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/Othello.dir/build.make CMakeFiles/Othello.dir/Othello_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/Othello.dir/Othello_automoc.cpp.o.provides

CMakeFiles/Othello.dir/Othello_automoc.cpp.o.provides.build: CMakeFiles/Othello.dir/Othello_automoc.cpp.o


# Object files for target Othello
Othello_OBJECTS = \
"CMakeFiles/Othello.dir/main.cpp.o" \
"CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o" \
"CMakeFiles/Othello.dir/Othello_automoc.cpp.o"

# External object files for target Othello
Othello_EXTERNAL_OBJECTS =

Othello: CMakeFiles/Othello.dir/main.cpp.o
Othello: CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o
Othello: CMakeFiles/Othello.dir/Othello_automoc.cpp.o
Othello: CMakeFiles/Othello.dir/build.make
Othello: /home/sam/Qt/5.8/gcc_64/lib/libQt5Widgets.so.5.8.0
Othello: /home/sam/Qt/5.8/gcc_64/lib/libQt5Multimedia.so.5.8.0
Othello: /home/sam/Qt/5.8/gcc_64/lib/libQt5Gui.so.5.8.0
Othello: /home/sam/Qt/5.8/gcc_64/lib/libQt5Network.so.5.8.0
Othello: /home/sam/Qt/5.8/gcc_64/lib/libQt5Core.so.5.8.0
Othello: CMakeFiles/Othello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Othello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Othello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Othello.dir/build: Othello

.PHONY : CMakeFiles/Othello.dir/build

CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/main.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/Sources/SetWindow.cpp.o.requires
CMakeFiles/Othello.dir/requires: CMakeFiles/Othello.dir/Othello_automoc.cpp.o.requires

.PHONY : CMakeFiles/Othello.dir/requires

CMakeFiles/Othello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Othello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Othello.dir/clean

CMakeFiles/Othello.dir/depend:
	cd /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sam/Desktop/Sharare/Othello/Othello /home/sam/Desktop/Sharare/Othello/Othello /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug /home/sam/Desktop/Sharare/Othello/Othello/cmake-build-debug/CMakeFiles/Othello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Othello.dir/depend
