#include <types.hpp>
#include <iostream>
#include <string>
#include <hash.hpp>
#include <hashclass.hpp>
#include <vector>
#include <algorithm>
#include <list>



std::string currentType="";
std::string secType="";
std::string buf("");


int vars=0;
int varfunc=0;
int fromfunccall=0;
int args=0;
std::vector<std::string> strins;
std::vector<std::string> ints;
std::vector<std::string> floats;
std::vector<std::string> funcs;



std::list <std::string> functypes;
std::list <std::string> funcargs;
std::list <std::string> funccallagrs;



void TypesVisit::run(Program& program, std::ostream& out) {
    TypesVisit types_visit;
    program.get_node()->accept(types_visit);
    out<<buf;

}

void TypesVisit::visit(Statement& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void TypesVisit::visit(Print& node) {
    for (const auto& objects : node.object()) {
        objects->accept(*this);
    }
    node.set_type(currentType);
}

void TypesVisit::visit(Numbes& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    node.set_type(currentType);
}

void TypesVisit::visit(String& node) {
    std::string type="String";
    currentType="String";
    node.set_type(type);
}

void TypesVisit::visit(Number& node) {
    std::string type="Int";
    currentType="Int";
    node.set_type(type);
}

void TypesVisit::visit(Type& node) {
    std::string _int="Int";
    std::string _str="String";
    std::string _flo="Float";
    std::string text=node.text();
    if(_int==text){
        currentType="Int";
        node.set_type(_int);
        
    } else if(_str==text){
        currentType="String";
        node.set_type(_str);
        
    } else if(_flo==text){
        currentType="Float";
        node.set_type(_flo);
    }
}

void TypesVisit::visit(Name& node) {
    std::string _int="Int";
    std::string _str="String";
    std::string _flo="Float";
    std::string item=node.text();
    if (vars==1){
        node.set_type(currentType);
        if(_int==currentType){
            ints.push_back(node.text());
        } else if(_str==currentType){
            strins.push_back(node.text());
        } else if(_flo==currentType){
            floats.push_back(node.text());
        }
    } else {
        if ( std::find(strins.begin(), strins.end(), item) != strins.end() ){
            node.set_type(_str);
            currentType="String";
            
        }
        else if ( std::find(ints.begin(), ints.end(), item) != ints.end() )
        {
            node.set_type(_int);
            currentType="Int";
        }
        else if ( std::find(floats.begin(), floats.end(), item) != floats.end() ){
            node.set_type(_flo);
            currentType="Float";
            
        }
        else
            buf.append("at "+node.token()+" not defined "+node.text().c_str()+"\n");
    }
    if(args==1){
        funcargs.push_back(node.text());
    }
}

void TypesVisit::visit(Funcname& node) {
    std::string item=node.text();
    if (varfunc==1)
    {
        funcs.push_back(node.text());
        functypes.push_back(node.get_type());
    }else if ( std::find(funcs.begin(), funcs.end(), item) != funcs.end() )
    { node.set_type(functypes.front());
        functypes.pop_front();
    }else{
        buf.append("at ");
        buf.append(node.token().c_str());
        buf.append(" "+item+"function not defined\n");
    }
}

void TypesVisit::visit(R_float& node) {
    std::string type="Float";
    currentType="Float";
    node.set_type(type);
}

void TypesVisit::visit(Importdeclaration& node) {}


void TypesVisit::visit(Secname& node) {
    std::string _int="Int";
    std::string _str="String";
    std::string _flo="Float";
    std::string item=node.text();
    
    if ( std::find(strins.begin(), strins.end(), item) != strins.end() ){
        node.set_type(_str);
        currentType="String";
        
    }
    else if ( std::find(ints.begin(), ints.end(), item) != ints.end() )
    {
        node.set_type(_int);
        currentType="Int";
    }
    else if ( std::find(floats.begin(), floats.end(), item) != floats.end() ){
        node.set_type(_flo);
        currentType="Float";
        
    }
    else
        buf.append("at "+node.token()+" not defined "+node.text().c_str()+"\n");

}

void TypesVisit::visit(Comparemembers& node) {}

void TypesVisit::visit(Variable& node) {
    vars=1;
    node.elements()[1]->accept(*this);
    node.elements()[0]->accept(*this);
    node.set_type(currentType);
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])){
            element->accept(*this);
        }
    }
    vars=0;
}

void TypesVisit::visit(Array& node) {
    vars=1;
    node.elements()[1]->accept(*this);
    node.elements()[0]->accept(*this);
    node.elements()[2]->accept(*this);
    node.set_type(currentType);
    vars=0;
}

void TypesVisit::visit(Ifconstrukt& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[2]->accept(*this);
    std::string rType=node.elements()[2]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for 'if' "+lType+" and "+rType+"\n");
    }
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])&&
           (element!=node.elements()[2])){
            element->accept(*this);
        }
    }

}

void TypesVisit::visit(Arithmetic& node) {
    
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[1]->accept(*this);
    std::string rType=node.elements()[1]->get_type();
    if((rType!="")&&(lType!="")){
        if(lType==rType){
            node.set_type(lType);
        } else if(lType!=rType){
            buf.append("at "+node.token()+" ");
            buf.append("unsupported operand type(s) for '=' "+lType+" and "+rType+"\n");
        }
    }
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])){
            element->accept(*this);
        }
    }
}

void TypesVisit::visit(R_while& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[2]->accept(*this);
    std::string rType=node.elements()[2]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for 'while' "+lType+" and "+rType+"\n");
    }
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])&&
           (element!=node.elements()[2])){
            element->accept(*this);
        }
    }
}

void TypesVisit::visit(Elseconstrukt& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void TypesVisit::visit(Wholeif& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}


void TypesVisit::visit(Opplus& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[1]->accept(*this);
    std::string rType=node.elements()[1]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for '+' "+lType+" and "+rType+"\n");
    }
    
    for (const auto& element : node.elements()) {
            if((element!=node.elements()[0])&&
            (element!=node.elements()[1])){
                element->accept(*this);
        }
    }
}

void TypesVisit::visit(Opminus& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[1]->accept(*this);
    std::string rType=node.elements()[1]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for '-' "+lType+" and "+rType+"\n");
    }
    for (const auto& element : node.elements()) {
            if((element!=node.elements()[0])&&
            (element!=node.elements()[1])){
                element->accept(*this);
        }
    }
}

void TypesVisit::visit(Opmulti& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[1]->accept(*this);
    std::string rType=node.elements()[1]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for '*' "+lType+" and "+rType+"\n");
    }
    for (const auto& element : node.elements()) {
            if((element!=node.elements()[0])&&
            (element!=node.elements()[1])){
                element->accept(*this);
        }
    }
}

void TypesVisit::visit(Opdivision& node) {
    node.elements()[0]->accept(*this);
    std::string lType=node.elements()[0]->get_type();
    node.elements()[1]->accept(*this);
    std::string rType=node.elements()[1]->get_type();
    
    if(lType==rType){
        node.set_type(lType);
    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("unsupported operand type(s) for '/' "+lType+" and "+rType+"\n");
    }
    for (const auto& element : node.elements()) {
            if((element!=node.elements()[0])&&
            (element!=node.elements()[1])){
                element->accept(*this);
        }
    }
}

void TypesVisit::visit(Function& node) {
    varfunc=1;
    
    for (const auto& element : node.elements()) {
        if(
           (element!=node.elements()[0])&&
           (element!=node.elements()[2])&&
           (element!=node.elements()[3])){
            element->accept(*this);
        }
    }
    node.elements()[2]->accept(*this);
    node.elements()[0]->accept(*this);

    
    std::string lType=node.elements()[0]->get_type();
    std::string rType=node.elements()[2]->get_type();

    
    if(lType==rType){
        node.set_type(lType);
        node.elements()[3]->set_type(lType);
        node.elements()[3]->accept(*this);

    } else if(lType!=rType){
        buf.append("at "+node.token()+" ");
        buf.append("wrong return type in function  "+lType+" and "+rType+"\n");
    }
    varfunc=0;
}

void TypesVisit::visit(Args& node) {
    vars=1;
//    node.elements()[1]->accept(*this);
//    node.elements()[0]->accept(*this);
    args=1;
    int argsnum=node.elements().size()/2;
    int i,j;
    for ( i = 0, j = argsnum; j < node.elements().size(); i++,j++) {
        node.elements()[j]->accept(*this);
        node.elements()[i]->accept(*this);
        }
    node.set_type(currentType);
    args=0;
    vars=0;
}
void TypesVisit::visit(Ret_type& node) {
    std::string _int="Int";
    std::string _str="String";
    std::string _flo="Float";
    std::string text=node.text();
    if(_int==text){
        currentType="Int";
        node.set_type(_int);
        
    } else if(_str==text){
        currentType="String";
        node.set_type(_str);
        
    } else if(_flo==text){
        currentType="Float";
        node.set_type(_flo);
    }
}

void TypesVisit::visit(Arrayelem& node) {
    node.elements()[0]->accept(*this);
    node.elements()[1]->accept(*this);
    node.set_type(currentType);
}

void TypesVisit::visit(Readline& node) {}

void TypesVisit::visit(Functioncall& node) {
    node.elements()[0]->accept(*this);
    node.set_type(node.elements()[0]->get_type());
    fromfunccall=1;
    int argsnum=node.elements().size()/2;
    int i,j;
    for ( i = 1, j = argsnum+1; j <= node.elements().size()-1; i++,j++) {
        node.elements()[i]->accept(*this);
        node.elements()[j]->accept(*this);
    }
    fromfunccall=0;
    if (funcargs.size()!=argsnum){
        buf.append("at "+node.token()+" "+"different number of arguments called\n");
    }
}


