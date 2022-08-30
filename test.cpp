#include "antlr4-runtime.h"
#include "SwiftLexer.h"
#include "print.h"
#include "parser.hpp"
#include <SwiftParser.h>

using namespace antlr4;

class lexerTests{
public:
    void compare(std::stringstream& supposedToBe, std::stringstream& out){
        if (out.str() != supposedToBe.str()) {
            std::cout << "Лексер работает неправильно\n";
        } else { std::cout << "Лексер работает правильно";}
    }
    
    void identificatorReturn(){
        
        std::stringstream supposedToBe;
        std::stringstream out;
        std::string in = "testinput/testidentificator.txt";
        supposedToBe<<"Loc=< 1; 0> IDENTIFICATOR '_sd'\n";
        supposedToBe<<"Loc=< 2; 0> IDENTIFICATOR 'v7k'\n";
        supposedToBe<<"Loc=< 2; 3> EOF '<EOF>'\n";
        
        print_tokens(in,out);
        
        compare(supposedToBe,out);
        std::cout << " c идентификаторами\n";
    }
    
    void floatReturn(){
        
        std::stringstream supposedToBe;
        std::stringstream out;
        std::string in = "testinput/testfloat.txt";
        supposedToBe<<"Loc=< 1; 0> FLOAT '3.356'\n";
        supposedToBe<<"Loc=< 2; 0> FLOAT '0.235235'\n";
        supposedToBe<<"Loc=< 2; 8> EOF '<EOF>'\n";
        
        print_tokens(in,out);
        
        compare(supposedToBe,out);
        std::cout << " c числами с плавающей точкой\n";
    }
};

class parserTests{
public:
    void compare(std::stringstream& supposedToBe, std::stringstream& out){
        if (out.str() != supposedToBe.str()) {
            std::cout << "Парсер работает неправильно\n";
        } else { std::cout << "Парсер работает правильно\n";}
    }
    
    void iReturn(){
        
        std::stringstream supposedToBe;
        std::stringstream out;
        std::string in = "testinput/hello.swift";
        supposedToBe<<"<?xml version=\"1.0\"?>\n<swift>\n  <program>\n    <import>import UIKit</import>\n  </program>\n</swift>\n";
        int id=1;
        auto parser_result = parse(in,&id);
        dump_ast(parser_result.program_, out);
        
        compare(supposedToBe,out);
    }
};

int main(int argc, char *argv[]) {
    //    lexerTests test;
    parserTests test;
    test.iReturn();
    //    test.identificatorReturn();
    //    test.floatReturn();
    return 0;
}

