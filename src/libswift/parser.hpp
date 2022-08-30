#include <xmlser.hpp>
#include <hash.hpp>
#include <codegen.hpp>

#include <types.hpp>

#include <builder.hpp>
#include <SwiftLexer.h>
#include <SwiftParser.h>
#include <ast.hpp>
#include <print.h>
#include <hashclass.hpp>
#include "antlr4-runtime.h"

using namespace antlr4;

struct Error {
    size_t line_;
    size_t column_;
    std::string message_;
};

using Errors = std::vector<Error>;

class StreamErrorListener : public antlr4::BaseErrorListener {
public:
    void syntaxError(
                     antlr4::Recognizer* ,
                     antlr4::Token* ,
                     size_t line,
                     size_t column,
                     const std::string& message,
                     std::exception_ptr ) override {
        errors_.emplace_back(Error{line, column, message});
    }
    
    const Errors& errors() const { return errors_; }
    
private:
    Errors errors_;
};

struct ParseResult {
    static ParseResult program(Program program) {
        ParseResult result;
        result.program_ = std::move(program);
        return result;
    }
    
    static ParseResult errors(Errors errors) {
        ParseResult result;
        result.errors_ = std::move(errors);
        return result;
    }
    
    Program program_;
    Errors errors_;
};


ParseResult parse(const std::string& in, int* id) {
    std::ifstream swiftFile (in);
    antlr4::ANTLRInputStream input(swiftFile);
    SwiftLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    SwiftParser parser(&tokens);
    
    StreamErrorListener error_listener;
    parser.removeErrorListeners();
    parser.addErrorListener(&error_listener);
    
    auto* program_parse_tree = parser.program();
    
    const auto& errors = error_listener.errors();
    if (!errors.empty()) {
        *id = 0;
        return ParseResult::errors(errors);
    }
    
    Program program;
    Builder builder(program);
    builder.visit(program_parse_tree);
    
    return ParseResult::program(std::move(program));
}



void dump_ast(Program& program, std::ostream& out) {
    XmlSerializer::exec(program, out);
}

void dump_ll(Program& program, std::ostream& out) {
    CodeGen::run(program, out);
}

void dump_lex(Program& program, std::ostream& out) {
    hash::SymbolTable st;
    Hashvisit hashvisit;
    hashvisit.run(program, out, st);
    TypesVisit::run(program, out);
}

void dump_errors(const Errors& errors, std::ostream& out) {
    for (const auto& error : errors) {
        std::cout <<"<"<< error.line_<<":";
        std::cout << error.column_<<">";
        std::cout << error.message_<<"\n";
    }
}
