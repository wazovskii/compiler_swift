
JAVA=/usr/bin/java
OUTPUT=output
GENERATED=generated
SOURCE=src
GRAMMAR=$(SOURCE)/grammar/Swift.g4
ANTLRFILE=$(SOURCE)/antlr/antlr-4.9.1-complete.jar

GRAMMARLIB=-lib $(SOURCE)/grammar/
CREATEDLIBSLOC=$(SOURCE)/libswift

RUNTIME=antlr4/runtime/Cpp/runtime/src
CPP=antlr4/runtime/Cpp
CC=g++
CCARGS= -g -c -I $(RUNTIME) -I $(GENERATED) -I $(CREATEDLIBSLOC) -std=c++17	
LDARGS=-g

UNAME_S := $(shell uname)
ifeq ($(UNAME_S),Linux)
        LIBS=$(CPP)/dist/libantlr4-runtime.so
endif

ifeq ($(UNAME_S),Darwin)
	LIBS=$(CPP)/dist/libantlr4-runtime.a
endif

.PHONY: antlr4


all: parser

parser: cleano sharedlib dirs antlr4 parser.cpp
	$(CC) $(CCARGS) parser.cpp  -o $(OUTPUT)/parser.o 
	$(CC) $(CCARGS) $(GENERATED)/SwiftLexer.cpp -o $(OUTPUT)/SwiftLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/SwiftParser.cpp -o $(OUTPUT)/SwiftParser.o 

	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/print.cpp -o $(OUTPUT)/print.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/hash.cpp -o $(OUTPUT)/hash.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/types.cpp -o $(OUTPUT)/types.o 
	
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/codegen.cpp -o $(OUTPUT)/codegen.o 



	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/xmlser.cpp -o $(OUTPUT)/xmlser.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/pugixml.cpp -o $(OUTPUT)/pugixml.o
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/builder.cpp -o $(OUTPUT)/builder.o
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/ast.cpp -o $(OUTPUT)/ast.o 

	$(CC) $(LDARGS) -std=c++17 $(OUTPUT)/*.o $(LIBS) -o parser

antlr4:
	$(JAVA) -jar $(ANTLRFILE) -Dlanguage=Cpp $(GRAMMAR) -Xexact-output-dir -o $(GENERATED) -visitor

dirs:
	mkdir -p $(OUTPUT) 
	mkdir -p $(GENERATED)

%.o: %.cpp
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/$< -o $(OUTPUT)/$@

sharedlib:
	cmake -S $(shell pwd)/$(CPP) -B $(shell pwd)/$(CPP)
	$(MAKE) -C $(shell pwd)/$(CPP)

submodule:
	sudo cmake -S $(CPP) -B $(CPP)
	sudo $(MAKE) -C $(CPP)


cleano:
	rm -rf $(OUTPUT)

clean:
	rm -rf $(OUTPUT)
	rm -rf antlr4/runtime/Cpp/CMakeFiles
	rm -rf antlr4/runtime/Cpp/MakeFile
	rm -rf antlr4/runtime/Cpp/CMakeCache.txt
	rm -rf antlr4/runtime/Cpp/runtime/CMakeFiles
	rm -rf antlr4/runtime/Cpp/runtime/MakeFile
	rm -rf antlr4/runtime/Cpp/runtime/CMakeCache.txt
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeCache.txt
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/Makefile
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests/CMakeFiles
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/tests/Makefile
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/Makefile
	rm -rf antlr4/runtime/Cpp/runtime/utfcpp-prefix/src/utfcpp-build/extern/gtest/CMakeFiles


test: cleano submodule dirs antlr4 parser.cpp
	$(CC) $(CCARGS) test.cpp  -o $(OUTPUT)/test.o 
	$(CC) $(CCARGS) $(GENERATED)/SwiftLexer.cpp -o $(OUTPUT)/SwiftLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/SwiftParser.cpp -o $(OUTPUT)/SwiftParser.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/print.cpp -o $(OUTPUT)/print.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/hash.cpp -o $(OUTPUT)/hash.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/codegen.cpp -o $(OUTPUT)/codegen.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/types.cpp -o $(OUTPUT)/types.o 


	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/xmlser.cpp -o $(OUTPUT)/xmlser.o 
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/pugixml.cpp -o $(OUTPUT)/pugixml.o
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/builder.cpp -o $(OUTPUT)/builder.o
	$(CC) $(CCARGS) $(CREATEDLIBSLOC)/ast.cpp -o $(OUTPUT)/ast.o 
	$(CC) $(LDARGS) -std=c++17 $(OUTPUT)/*.o $(LIBS) -o test
