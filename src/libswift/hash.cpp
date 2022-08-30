#include <iostream>

#include <visitor.hpp>
#include <hash.hpp>


#include <ostream>
#include <stack>
#include <string>
std::string visibility="global";
std::string defined="no";
std::string type="variable";
std::string key="";
std::string buffer("");
int funcvar=0;


void Hashvisit::run(Program& program, std::ostream& out, hash::SymbolTable& st_) {
    
    Hashvisit hash_visit;
    program.get_node()->accept(hash_visit);
    out<<buffer;
    for(int i = 0 ; i<100 ; i++){
        st_.head[i] = hash_visit.st.head[i];
    }
}

void Hashvisit::visit(Statement& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Print& node) {
    for (const auto& objects : node.object()) {
        objects->accept(*this);
    }
}

void Hashvisit::visit(Numbes& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(String& node) {}

void Hashvisit::visit(Number& node) {}

void Hashvisit::visit(Type& node) {}

void Hashvisit::visit(Name& node) {
    auto token = node.text().c_str();
    auto tok = node.token().c_str();
    std::string check = st.find(token);
    if ((check == "-1")&&(defined=="no")){//токен не определен
        buffer.append("at ");
        buffer.append(node.token().c_str());
        buffer.append(" not defined ");
        buffer.append(node.text().c_str());
        buffer.append("\n");
    }
    if ((check != "-1")&&(st.findscope(node.text().c_str())=="Global")&&(key!="")){//уже есть такой токен он глобальный и  он пришел из var'a
        buffer.append("at ");
        buffer.append(node.token().c_str());
        buffer.append(" redefinition of ");
        buffer.append(node.text().c_str());
        buffer.append("\n");
    }
    else if (key=="") {
        st.insert(key+token, visibility, type, node.token().c_str(), defined);
    } else {
        st.insert(token, visibility, type, node.token().c_str(), defined);
    }
}

void Hashvisit::visit(Funcname& node) {
    std::string check = st.find(node.text().c_str());
    if (funcvar==1){
    if (check != "-1"){
        buffer.append("at ");
        buffer.append(node.token().c_str());
        buffer.append(" redefinition of ");
        buffer.append(node.text().c_str());
        buffer.append("\n");
    }
    else {
        st.insert(node.text().c_str(), "global", "function name", node.token().c_str(), "yes");
    }
    } else {
        if (check == "-1"){
        buffer.append("at ");
        buffer.append(node.token().c_str());
        buffer.append(" function not defined ");
        buffer.append(node.text().c_str());
        buffer.append("\n");
    }
}
}

void Hashvisit::visit(R_float& node) {}

void Hashvisit::visit(Importdeclaration& node) {}


void Hashvisit::visit(Secname& node) {
    st.insert(node.text().c_str(), visibility, type, node.token().c_str(), defined);
}

void Hashvisit::visit(Comparemembers& node) {}

void Hashvisit::visit(Variable& node) {
    defined="yes";
    key="var";
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    defined="no";
    key="";
}

void Hashvisit::visit(Array& node) {
    defined="yes";
    type="array";
    key="var";
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    defined="no";
    type="variable";
    key="";
}

void Hashvisit::visit(Ifconstrukt& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Arithmetic& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(R_while& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Elseconstrukt& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Wholeif& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}


void Hashvisit::visit(Opplus& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Opminus& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Opmulti& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Opdivision& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Function& node) {
    visibility="local";
    funcvar=1;
    node.elements()[4]->accept(*this);
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    funcvar=0;
    visibility="global";
}

void Hashvisit::visit(Args& node) {
    defined="yes";
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    defined="no";
}

void Hashvisit::visit(Arrayelem& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void Hashvisit::visit(Ret_type& node) {}

void Hashvisit::visit(Readline& node) {}

void Hashvisit::visit(Functioncall& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}
