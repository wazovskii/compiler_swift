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
CMAKE_SOURCE_DIR = /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp

# Utility rule file for GenerateParser.

# Include the progress variables for this target.
include demo/CMakeFiles/GenerateParser.dir/progress.make

demo/CMakeFiles/GenerateParser: demo/generated/TLexer.cpp
demo/CMakeFiles/GenerateParser: demo/generated/TParser.cpp
demo/CMakeFiles/GenerateParser: demo/generated/TParserBaseListener.cpp
demo/CMakeFiles/GenerateParser: demo/generated/TParserBaseVisitor.cpp
demo/CMakeFiles/GenerateParser: demo/generated/TParserListener.cpp
demo/CMakeFiles/GenerateParser: demo/generated/TParserVisitor.cpp


demo/generated/TLexer.cpp: demo/TLexer.g4
demo/generated/TLexer.cpp: demo/TParser.g4
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating generated/TLexer.cpp, generated/TParser.cpp, generated/TParserBaseListener.cpp, generated/TParserBaseVisitor.cpp, generated/TParserListener.cpp, generated/TParserVisitor.cpp"
	/usr/local/Cellar/cmake/3.19.6/bin/cmake -E make_directory /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/generated/
	/Library/Java/JavaVirtualMachines/jdk-15.0.2.jdk/Contents/Home/bin/java -jar /Users/wazovski/Desktop/compiler_swift/src/antlr/antlr-4.9.1-complete.jar -Werror -Dlanguage=Cpp -listener -visitor -o /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/generated/ -package antlrcpptest /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/TLexer.g4 /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/TParser.g4

demo/generated/TParser.cpp: demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate demo/generated/TParser.cpp

demo/generated/TParserBaseListener.cpp: demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate demo/generated/TParserBaseListener.cpp

demo/generated/TParserBaseVisitor.cpp: demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate demo/generated/TParserBaseVisitor.cpp

demo/generated/TParserListener.cpp: demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate demo/generated/TParserListener.cpp

demo/generated/TParserVisitor.cpp: demo/generated/TLexer.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate demo/generated/TParserVisitor.cpp

GenerateParser: demo/CMakeFiles/GenerateParser
GenerateParser: demo/generated/TLexer.cpp
GenerateParser: demo/generated/TParser.cpp
GenerateParser: demo/generated/TParserBaseListener.cpp
GenerateParser: demo/generated/TParserBaseVisitor.cpp
GenerateParser: demo/generated/TParserListener.cpp
GenerateParser: demo/generated/TParserVisitor.cpp
GenerateParser: demo/CMakeFiles/GenerateParser.dir/build.make

.PHONY : GenerateParser

# Rule to build all files generated by this target.
demo/CMakeFiles/GenerateParser.dir/build: GenerateParser

.PHONY : demo/CMakeFiles/GenerateParser.dir/build

demo/CMakeFiles/GenerateParser.dir/clean:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo && $(CMAKE_COMMAND) -P CMakeFiles/GenerateParser.dir/cmake_clean.cmake
.PHONY : demo/CMakeFiles/GenerateParser.dir/clean

demo/CMakeFiles/GenerateParser.dir/depend:
	cd /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo /Users/wazovski/Desktop/compiler_swift/antlr4/runtime/Cpp/demo/CMakeFiles/GenerateParser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : demo/CMakeFiles/GenerateParser.dir/depend

