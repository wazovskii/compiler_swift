#include <builder.hpp>


antlrcpp::Any Builder::visitProgram(SwiftParser::ProgramContext* context) {
    auto* node = visitChildren(context).as<Node*>();
    program_.set_node(node);
    return node;
}

static std::string trim_quotes(const std::string& str) {
    assert(str[0] == '"' && str[str.size() - 1] == '"');
    return str.substr(1, str.size() - 2);
}

antlrcpp::Any Builder::visitPrint(SwiftParser::PrintContext* context) {
    Print::Object objects;
    for (auto object_ : context->object()) {
        objects.push_back(visit(object_));
    }
    return static_cast<Node*>(program_.create_node<Print>(objects));
}

antlrcpp::Any Builder::visitNumbes(SwiftParser::NumbesContext* context) {
    
    Numbes::Elements elements;
    for (auto element_ : context->types()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<Numbes>(elements));
}


antlrcpp::Any Builder::visitStatement(SwiftParser::StatementContext* context) {
    Statement::Elements elements;
    elements.push_back(visit(context->importdeclaration()));
    for (auto element_ : context->element()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<Statement>(elements));
}

antlrcpp::Any Builder::visitArithmetic(SwiftParser::ArithmeticContext* context) {
    Arithmetic::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->avalibforplus()));
    for (auto element_ : context->operations()) {
        elements.push_back(visit(element_));
    }
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Arithmetic>(Arithmetic(elements,token)));
}


antlrcpp::Any Builder::visitNumber(SwiftParser::NumberContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<Number>(text));
}

antlrcpp::Any Builder::visitR_float(SwiftParser::R_floatContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<R_float>(text));
}

antlrcpp::Any Builder::visitString(SwiftParser::StringContext* context) {
    auto const text = trim_quotes(context->getText());
    return static_cast<Node*>(program_.create_node<String>(text));
}

antlrcpp::Any Builder::visitType(SwiftParser::TypeContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<Type>(text));
}

antlrcpp::Any Builder::visitImportdeclaration(SwiftParser::ImportdeclarationContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<Importdeclaration>(text));
}

antlrcpp::Any Builder::visitVariable(SwiftParser::VariableContext* context) {
    Variable::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->type()));
    elements.push_back(visit(context->types()));
    return static_cast<Node*>(program_.create_node<Variable>(elements));
}

antlrcpp::Any Builder::visitArray(SwiftParser::ArrayContext* context) {
    Variable::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->type()));
    elements.push_back(visit(context->numbes()));
    return static_cast<Node*>(program_.create_node<Array>(elements));
}

antlrcpp::Any Builder::visitWholeif(SwiftParser::WholeifContext* context) {
    Wholeif::Elements elements;
    elements.push_back(visit(context->ifconstrukt()));
    elements.push_back(visit(context->elseconstrukt()));
    return static_cast<Node*>(program_.create_node<Wholeif>(elements));
}


antlrcpp::Any Builder::visitIfconstrukt(SwiftParser::IfconstruktContext* context) {
    Ifconstrukt::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->comparemembers()));
    elements.push_back(visit(context->secname()));
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    for (auto element_ : context->element()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<Ifconstrukt>(Ifconstrukt(elements,token)));
}

antlrcpp::Any Builder::visitR_while(SwiftParser::R_whileContext* context) {
    R_while::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->comparemembers()));
    elements.push_back(visit(context->secname()));
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    for (auto element_ : context->element()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<R_while>(R_while(elements,token)));
}

antlrcpp::Any Builder::visitElseconstrukt(SwiftParser::ElseconstruktContext* context) {
    Elseconstrukt::Elements elements;
    for (auto element_ : context->element()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<Elseconstrukt>(elements));
}

antlrcpp::Any Builder::visitName(SwiftParser::NameContext* context) {
    auto const text = context->getText();
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Name>(Name(text,token)));
}

antlrcpp::Any Builder::visitFuncname(SwiftParser::FuncnameContext* context) {
    auto const text = context->getText();
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Funcname>(Funcname(text,token)));
}

antlrcpp::Any Builder::visitSecname(SwiftParser::SecnameContext* context) {
    auto const text = context->getText();
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Secname>(Secname(text,token)));
}

antlrcpp::Any Builder::visitComparemembers(SwiftParser::ComparemembersContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<Comparemembers>(text));
}

antlrcpp::Any Builder::visitOpplus(SwiftParser::OpplusContext* context) {
    
    Opplus::Elements elements;
    elements.push_back(visit(context->avalibforplus()));

    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Opplus>(Opplus(elements,token)));
}

antlrcpp::Any Builder::visitOpminus(SwiftParser::OpminusContext* context) {
    
    Opminus::Elements elements;
    elements.push_back(visit(context->avalibforplus()));

    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Opminus>(Opminus(elements,token)));
}

antlrcpp::Any Builder::visitOpmulti(SwiftParser::OpmultiContext* context) {
    
    Opmulti::Elements elements;
    elements.push_back(visit(context->avalibformulti()));

    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Opmulti>(Opmulti(elements,token)));
}

antlrcpp::Any Builder::visitOpdivision(SwiftParser::OpdivisionContext* context) {
    
    Opdivision::Elements elements;
    elements.push_back(visit(context->avalibformulti()));

    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Opdivision>(Opdivision(elements,token)));
}

antlrcpp::Any Builder::visitFunction(SwiftParser::FunctionContext* context) {
    Function::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->args()));
    elements.push_back(visit(context->ret_type()));
    elements.push_back(visit(context->funcname()));
    for (auto element_ : context->element()) {
        elements.push_back(visit(element_));
    }
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Function>(Function(elements,token)));
}

antlrcpp::Any Builder::visitArgs(SwiftParser::ArgsContext* context) {
    Args::Elements elements;
    for (auto element_ : context->name()) {
        elements.push_back(visit(element_));
    }
    for (auto element_ : context->type()) {
        elements.push_back(visit(element_));
    }
    return static_cast<Node*>(program_.create_node<Args>(elements));
}

antlrcpp::Any Builder::visitRet_type(SwiftParser::Ret_typeContext* context) {
    auto const text = context->getText();
    return static_cast<Node*>(program_.create_node<Type>(text));
}

antlrcpp::Any Builder::visitArrayelem(SwiftParser::ArrayelemContext* context) {
    Arrayelem::Elements elements;
    elements.push_back(visit(context->name()));
    elements.push_back(visit(context->r_index()));
    return static_cast<Node*>(program_.create_node<Arrayelem>(elements));
}

antlrcpp::Any Builder::visitReadline(SwiftParser::ReadlineContext* context) {
    auto const text = context->getText();
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Readline>(Readline(text,token)));
}

antlrcpp::Any Builder::visitFunctioncall(SwiftParser::FunctioncallContext* context) {
    Function::Elements elements;
    elements.push_back(visit(context->funcname()));
    for (auto element_ : context->name()) {
        elements.push_back(visit(element_));
    }
    for (auto element_ : context->avalibforplus()) {
        elements.push_back(visit(element_));
    }
    auto const token = std::to_string(context->getStart()->getLine())+":"+std::to_string(context->getStart()->getCharPositionInLine());
    return static_cast<Node*>(program_.create_node<Functioncall>(Functioncall(elements,token)));
}
