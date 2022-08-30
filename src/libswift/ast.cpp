#include <ast.hpp>
#include <iostream>

#include <visitor.hpp>



void String::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Importdeclaration::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Print::accept(Visitor& visitor) {
    visitor.visit(*this);
}
void Statement::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Arithmetic::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Opplus::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Opminus::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Opmulti::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Opdivision::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Name::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Funcname::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Secname::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Comparemembers::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Wholeif::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Numbes::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Elseconstrukt::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Number::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void R_float::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Variable::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Type::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Ifconstrukt::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void R_while::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Array::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Function::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Args::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Ret_type::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Arrayelem::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Readline::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void Functioncall::accept(Visitor& visitor) {
    visitor.visit(*this);
}
