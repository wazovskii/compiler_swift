#pragma once
#include <visitor.hpp>
#include <ostream>

class TypesVisit final : public Visitor {
public:
    static void run(Program& program, std::ostream& out);
    
    void visit(Print& node) override;
    void visit(String& node) override;
    void visit(Number& node) override;
    void visit(R_float& node) override;
    void visit(Numbes& node) override;
    void visit(R_while& node) override;
    void visit(Array& node) override;
    void visit(Arithmetic& node) override;
    void visit(Opplus& node) override;
    void visit(Opminus& node) override;
    void visit(Opmulti& node) override;
    void visit(Opdivision& node) override;
    void visit(Function& node) override;
    void visit(Args& node) override;
    void visit(Ret_type& node) override;
    void visit(Type& node) override;
    void visit(Name& node) override;
    void visit(Funcname& node) override;
    void visit(Variable& node) override;
    void visit(Wholeif& node) override;
    void visit(Ifconstrukt& node) override;
    void visit(Elseconstrukt& node) override;
    void visit(Secname& node) override;
    void visit(Comparemembers& node) override;
    void visit(Statement& node) override;
    void visit(Importdeclaration& node) override;
    void visit(Arrayelem& node) override;
    void visit(Readline& node) override;
    void visit(Functioncall& node) override;

};

