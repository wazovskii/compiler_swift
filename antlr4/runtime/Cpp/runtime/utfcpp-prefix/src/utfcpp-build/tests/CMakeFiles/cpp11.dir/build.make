# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.6/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build

# Include any dependencies generated for this target.
include tests/CMakeFiles/cpp11.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/cpp11.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/cpp11.dir/flags.make

tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.o: tests/CMakeFiles/cpp11.dir/flags.make
tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.o: /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/tests/test_cpp11.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.o"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp11.dir/test_cpp11.cpp.o -c /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/tests/test_cpp11.cpp

tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp11.dir/test_cpp11.cpp.i"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/tests/test_cpp11.cpp > CMakeFiles/cpp11.dir/test_cpp11.cpp.i

tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp11.dir/test_cpp11.cpp.s"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/tests/test_cpp11.cpp -o CMakeFiles/cpp11.dir/test_cpp11.cpp.s

# Object files for target cpp11
cpp11_OBJECTS = \
"CMakeFiles/cpp11.dir/test_cpp11.cpp.o"

# External object files for target cpp11
cpp11_EXTERNAL_OBJECTS =

tests/cpp11: tests/CMakeFiles/cpp11.dir/test_cpp11.cpp.o
tests/cpp11: tests/CMakeFiles/cpp11.dir/build.make
tests/cpp11: extern/gtest/googlemock/gtest/libgtest_main.a
tests/cpp11: extern/gtest/googlemock/gtest/libgtest.a
tests/cpp11: tests/CMakeFiles/cpp11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpp11"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/cpp11.dir/build: tests/cpp11

.PHONY : tests/CMakeFiles/cpp11.dir/build

tests/CMakeFiles/cpp11.dir/clean:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests && $(CMAKE_COMMAND) -P CMakeFiles/cpp11.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/cpp11.dir/clean

tests/CMakeFiles/cpp11.dir/depend:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/tests /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests/CMakeFiles/cpp11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/cpp11.dir/depend
