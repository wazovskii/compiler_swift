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
include extern/gtest/googlemock/CMakeFiles/gmock.dir/depend.make

# Include the progress variables for this target.
include extern/gtest/googlemock/CMakeFiles/gmock.dir/progress.make

# Include the compile flags for this target's objects.
include extern/gtest/googlemock/CMakeFiles/gmock.dir/flags.make

extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: extern/gtest/googlemock/CMakeFiles/gmock.dir/flags.make
extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o: /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/extern/gtest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock.dir/src/gmock-all.cc.o -c /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/extern/gtest/googlemock/src/gmock-all.cc

extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock.dir/src/gmock-all.cc.i"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/extern/gtest/googlemock/src/gmock-all.cc > CMakeFiles/gmock.dir/src/gmock-all.cc.i

extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock.dir/src/gmock-all.cc.s"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/extern/gtest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock.dir/src/gmock-all.cc.s

# Object files for target gmock
gmock_OBJECTS = \
"CMakeFiles/gmock.dir/src/gmock-all.cc.o"

# External object files for target gmock
gmock_EXTERNAL_OBJECTS =

extern/gtest/googlemock/libgmock.a: extern/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
extern/gtest/googlemock/libgmock.a: extern/gtest/googlemock/CMakeFiles/gmock.dir/build.make
extern/gtest/googlemock/libgmock.a: extern/gtest/googlemock/CMakeFiles/gmock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgmock.a"
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean_target.cmake
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
extern/gtest/googlemock/CMakeFiles/gmock.dir/build: extern/gtest/googlemock/libgmock.a

.PHONY : extern/gtest/googlemock/CMakeFiles/gmock.dir/build

extern/gtest/googlemock/CMakeFiles/gmock.dir/clean:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock.dir/cmake_clean.cmake
.PHONY : extern/gtest/googlemock/CMakeFiles/gmock.dir/clean

extern/gtest/googlemock/CMakeFiles/gmock.dir/depend:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/thirdparty/utfcpp/extern/gtest/googlemock /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/googlemock/CMakeFiles/gmock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : extern/gtest/googlemock/CMakeFiles/gmock.dir/depend

