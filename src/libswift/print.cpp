#include "antlr4-runtime.h"
#include "SwiftLexer.h"
#include <SwiftParser.h>
#include "print.h"

using namespace antlr4;

void print_tokens(const std::string& inputFile, std::ostream& out) {
    std::string line;
    std::ifstream swiftFile (inputFile);
    if (swiftFile.is_open()) {
        ANTLRInputStream input(swiftFile);
        SwiftLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        
        tokens.fill();
        for (auto token : tokens.getTokens()) {
            out <<"Loc=<"<<std::setw(2)<< token->getLine()<<";"<<std::setw(2)<< token->getCharPositionInLine()<<"> "<< lexer.getVocabulary().getSymbolicName(token->getType());
            out <<" '"<< token->getText()<<"'\n";
        }
        swiftFile.close();
    }
    
}
