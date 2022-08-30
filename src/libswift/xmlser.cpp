#include <xmlser.hpp>
#include <iostream>
#include <string>


void XmlSerializer::exec(Program& program, std::ostream& out) {
    XmlSerializer xml_serializer;
    xml_serializer.nodes_.push(xml_serializer.doc_.append_child("swift"));
    program.get_node()->accept(xml_serializer);
    xml_serializer.doc_.save(out, "  ");
}

void XmlSerializer::visit(Statement& node) {
    auto item = append_child("program");
    nodes_.push(item);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Print& node) {
    auto key = append_child("print");
    nodes_.push(key);
    for (const auto& objects : node.object()) {
        objects->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Numbes& node) {
    auto key = append_child("multiple elements");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(String& node) {
    auto key = append_child("string");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Number& node) {
    auto key = append_child("integer");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Type& node) {
    auto key = append_child("type");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Name& node) {
    std::string content="identificator type = "+node.get_type();
    auto key = append_child(content.c_str());
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Funcname& node) {
    auto key = append_child("function identificator");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(R_float& node) {
    auto key = append_child("float");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Importdeclaration& node) {
    auto key = append_child("import");
    nodes_.push(key);
    append_text(node.text().c_str());
}


void XmlSerializer::visit(Secname& node) {
    std::string content="identificator type = "+node.get_type();
    auto key = append_child(content.c_str());
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Comparemembers& node) {
    auto key = append_child("compare");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Variable& node) {
    std::string content="variable declaration type = "+node.get_type();
    auto key = append_child(content.c_str());
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
    
}

void XmlSerializer::visit(Array& node) {
    std::string content="array declaration type = "+node.get_type();
    auto key = append_child(content.c_str());
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
    
}

void XmlSerializer::visit(Ifconstrukt& node) {
    std::string content;
    if(node.get_type()!="")
        content="if type = "+node.get_type();
    else
        content="if";
    
    auto key = append_child(content.c_str());
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Arithmetic& node) {
    std::string content;
    if(node.get_type()!="")
        content="assignment type = "+node.get_type();
    else
        content="assignment";
    
    auto key = append_child(content.c_str());
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(R_while& node) {
    std::string content;
    if(node.get_type()!="")
        content="while type = "+node.get_type();
    else
        content="while";
    
    auto key = append_child(content.c_str());
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Elseconstrukt& node) {
    auto key = append_child("Else");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Wholeif& node) {
    auto key = append_child("if else");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

pugi::xml_node XmlSerializer::append_child(const char* name) {
    return nodes_.top().append_child(name);
}

void XmlSerializer::append_text(const char* text) {
    auto text_node = nodes_.top().append_child(pugi::node_pcdata);
    text_node.set_value(text);
}

void XmlSerializer::visit(Opplus& node) {
    auto key = append_child("plus");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Opminus& node) {
    auto key = append_child("minus");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Opmulti& node) {
    auto key = append_child("multi");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Opdivision& node) {
    auto key = append_child("division");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Function& node) {
    auto key = append_child("func");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Args& node) {
    auto key = append_child("arguments");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Ret_type& node) {
    auto key = append_child("return type");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Arrayelem& node) {
    auto key = append_child("element of array");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}

void XmlSerializer::visit(Readline& node) {
    auto key = append_child("readline");
    nodes_.push(key);
    append_text(node.text().c_str());
}

void XmlSerializer::visit(Functioncall& node) {
    auto key = append_child("funcltioncall");
    nodes_.push(key);
    for (const auto& element : node.elements()) {
        element->accept(*this);
        nodes_.pop();
    }
}
