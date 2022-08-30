#pragma once

#include <ast.hpp>


class Visitor {
public:
    virtual void visit(Print& node) = 0;
    virtual void visit(String& node) = 0;
    virtual void visit(Number& node) = 0;
    virtual void visit(R_float& node) = 0;
    virtual void visit(Array& node) = 0;
    virtual void visit(Arithmetic& node) = 0;
    virtual void visit(Opplus& node) = 0;
    virtual void visit(Opminus& node) = 0;
    virtual void visit(Opmulti& node) = 0;
    virtual void visit(Opdivision& node) = 0;
    virtual void visit(Function& node) = 0;
    virtual void visit(Args& node) = 0;
    virtual void visit(Ret_type& node) = 0;
    
    virtual void visit(R_while& node) = 0;
    virtual void visit(Numbes& node) = 0;
    virtual void visit(Type& node) = 0;
    virtual void visit(Name& node) = 0;
    virtual void visit(Funcname& node) = 0;

    virtual void visit(Secname& node) = 0;
    virtual void visit(Wholeif& node) = 0;
    virtual void visit(Comparemembers& node) = 0;
    virtual void visit(Ifconstrukt& node) = 0;
    virtual void visit(Elseconstrukt& node) = 0;
    virtual void visit(Variable& node) = 0;
    virtual void visit(Statement& value) = 0;
    virtual void visit(Importdeclaration& node) = 0;
    virtual void visit(Arrayelem& node) = 0;
    virtual void visit(Readline& node) = 0;
    virtual void visit(Functioncall& node) = 0;

};

