#include <parser.hpp>
#include <print.h>
#include "antlr4-runtime.h"

std::string error_("");
std::ostringstream stream;


using namespace antlr4;

int main(int argc, char *argv[]){
    const std::string in = "hello.swift";
    int id = 1;
    auto parser_result = parse(in,&id);
        if (id == 0) {
            dump_errors(parser_result.errors_,std::cout);
        } else {
            dump_lex(parser_result.program_,stream);
            error_.append(stream.str());
            if (error_==""){
                if(argc>1) {
                if (strncmp(argv[1], "--dump-ast",10)==0)
                    dump_ast(parser_result.program_, std::cout);
                else if (strncmp(argv[1],"--dump-tokens",13)==0) {
                    print_tokens(in,std::cout);
                    dump_lex(parser_result.program_,std::cout);
                } else if (strncmp(argv[1],"--dump-asm",10)==0) {
                    dump_ll(parser_result.program_,std::cout);
                }
                } else {
                    dump_ll(parser_result.program_,stream);
                }
            } else {
                std::cout<<"errors ocurred\n";
                std::cout<<error_;
            }
        }
    return 0;
}
