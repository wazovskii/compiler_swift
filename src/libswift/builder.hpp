#pragma once

#include <ast.hpp>

#include <SwiftBaseVisitor.h>


class Builder final : public SwiftBaseVisitor {
public:
    explicit Builder(Program& program) : program_(program) {}
    antlrcpp::Any visitProgram(SwiftParser::ProgramContext* context) override;
    antlrcpp::Any visitPrint(SwiftParser::PrintContext* context) override;
    antlrcpp::Any visitString(SwiftParser::StringContext* context) override;
    antlrcpp::Any visitNumber(SwiftParser::NumberContext* context) override;
    antlrcpp::Any visitVariable(SwiftParser::VariableContext* context) override;
    antlrcpp::Any visitType(SwiftParser::TypeContext* context) override;
    antlrcpp::Any visitName(SwiftParser::NameContext* context) override;
    antlrcpp::Any visitFuncname(SwiftParser::FuncnameContext* context) override;

    antlrcpp::Any visitR_float(SwiftParser::R_floatContext* context) override;
    antlrcpp::Any visitR_while(SwiftParser::R_whileContext* context) override;
    antlrcpp::Any visitArray(SwiftParser::ArrayContext* context) override;
    antlrcpp::Any visitArithmetic(SwiftParser::ArithmeticContext* context) override;
    antlrcpp::Any visitOpplus(SwiftParser::OpplusContext* context) override;
    antlrcpp::Any visitOpminus(SwiftParser::OpminusContext* context) override;
    antlrcpp::Any visitOpmulti(SwiftParser::OpmultiContext* context) override;
    antlrcpp::Any visitOpdivision(SwiftParser::OpdivisionContext* context) override;
    antlrcpp::Any visitFunction(SwiftParser::FunctionContext* context) override;
    antlrcpp::Any visitArgs(SwiftParser::ArgsContext* context) override;
    antlrcpp::Any visitRet_type(SwiftParser::Ret_typeContext* context) override;

    antlrcpp::Any visitNumbes(SwiftParser::NumbesContext* context) override;
    antlrcpp::Any visitSecname(SwiftParser::SecnameContext* context) override;
    antlrcpp::Any visitComparemembers(SwiftParser::ComparemembersContext* context) override;
    antlrcpp::Any visitIfconstrukt(SwiftParser::IfconstruktContext* context) override;
    antlrcpp::Any visitWholeif(SwiftParser::WholeifContext* context) override;
    antlrcpp::Any visitElseconstrukt(SwiftParser::ElseconstruktContext* context) override;
    
    antlrcpp::Any visitStatement(SwiftParser::StatementContext* context) override;
    antlrcpp::Any visitImportdeclaration(SwiftParser::ImportdeclarationContext* context) override;
    antlrcpp::Any visitArrayelem(SwiftParser::ArrayelemContext* context) override;
    antlrcpp::Any visitReadline(SwiftParser::ReadlineContext* context) override;
    antlrcpp::Any visitFunctioncall(SwiftParser::FunctioncallContext* context) override;


private:
    Program& program_;
};
