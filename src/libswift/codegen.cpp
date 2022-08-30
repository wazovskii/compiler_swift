#include <codegen.hpp>
#include <iostream>
#include <string>
#include <map>

#include <fstream>

#include <list>

std::ofstream outfile ("test.ll");
std::string buffglobal("");
std::string buff("");
std::string buffconst("");
std::string bufffunc("");
std::string bufflocal("");

std::string intformat("%d\\00");
std::string floatformat("%f\\00");
std::string stringformat("%s\\00");
std::string comparemem("");
std::string textnumber("");
std::string ltype("");


int arraylength=0;

int strglobal=0;
hash::SymbolTable st;
int var = 0;
int fromprint = 0;
int fromarray = 0;
int fromifconstrukt=0;
int fromwholeif=0;
int fromwhile=0;
int fromnumbes=0;
int fromarithmetic=0;
int fromassignment=0;
int fromfunction=0;
int fromarrayelem=0;
int fromfuncall=0;
int fromreadline=0;
int fromargs=0;
int needindex=0;
int forreadline=0;

int ielem=0;
int ifunc=0;
int iarray=0;
int iassignment=0;
int ireadline=0;
int alignnum=0;
std::string pref[26]={"a","b","c","d","e","f","g","h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
int iprint=0;
int iname=0;
int iif=0;
int iwh=0;
std::string arrayindex("");
std::string variablename("");
std::string secvariablename("");
std::string functionname("");
std::list <std::string> operations;
std::list <std::string> funcargumentname;
std::list <std::string> funcargumenttype;
std::list <std::string> funccall;



std::map<std::string, std::string> itypes { {"Int", "i32"}, {"Float","float"}, { "String", "i8*"}, };
std::map<std::string, std::string> align { {"Int", "4"}, {"Float","float"}, { "String", "8"}, };
std::map<std::string, std::string> format { {"Int", "%d\\00"}, {"Float","%f\\00"}, { "String", "%s\\00"}, };
std::map<std::string, std::string> compare { {"<", "slt"}, {">","sgt"}, { "==", "eq"}, {">=","sge"}, {"<=","sle"}, };

//добавить еррор
void CodeGen::run(Program& program, std::ostream& out) {
    
    CodeGen codegen;
    
    
    //    buffconst.append("target triple = \"x86_64-apple-macosx10.15.0\"\n");
    
    
    
    program.get_node()->accept(codegen);
//    std::cout<<buffconst;
//    std::cout<<buffglobal;
//    std::cout<<bufffunc;
//
//    std::cout<<buff;
    
    outfile << "target triple = \"x86_64-apple-macosx10.15.0\"" << std::endl;
    outfile << buffconst.c_str();
    outfile << buffglobal;
    outfile << bufffunc;
    outfile << "define i32 @main() #0 {\n";
    outfile << "  %aa = alloca i32, align 4\n";
    outfile << "  store i32 0, i32* %aa, align 4\n";
    outfile << buff;
    outfile << "  ret i32 0\n}\n";
    outfile << "declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #1\ndeclare i32 @printf(i8*, ...) #2\ndeclare i32 @scanf(i8*, ...) #3\n";
    outfile.close();
    
    out << "target triple = \"x86_64-apple-macosx10.15.0\"" << std::endl;
    out << buffconst.c_str();
    out << buffglobal;
    out << bufffunc;
    out << "define i32 @main() #0 {\n";
    out << "  %aa = alloca i32, align 4\n";
    out << "  store i32 0, i32* %aa, align 4\n";
    out << buff;
    out << "  ret i32 0\n}\n";
    out << "declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #1\ndeclare i32 @printf(i8*, ...) #2\ndeclare i32 @scanf(i8*, ...) #3\n";
    
}

void CodeGen::visit(Statement& node) {
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
}

void CodeGen::visit(Importdeclaration& node) {}


void CodeGen::visit(Print& node) {
    fromprint = 1;
    
    
    for (const auto& objects : node.object()) {
        objects->accept(*this);
    }
    fromprint = 0;
    iprint++;
}

void CodeGen::visit(Numbes& node) {
    fromnumbes=1;
    arraylength=node.elements().size();
    alignnum = arraylength > 3 ? 16: 4 ;
    if ((fromarray==1)&&(node.get_type()=="Int")){
        buffglobal.append("@__const.main.");
        buffglobal.append(variablename);
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append(std::to_string(node.elements().size()));
        buffglobal.append(" x ");
        buffglobal.append(itypes[node.get_type()]);
        buffglobal.append("] [");
        
        
        for (const auto& element : node.elements()) {
            element->accept(*this);
            if(element==node.elements()[node.elements().size()-1]) buffglobal.append("]");
            else buffglobal.append(", ");
        }
        buffglobal.append(", align ");
        buffglobal.append(std::to_string(alignnum)+"\n");
    }
    
    if ((fromarray==1)&&(node.get_type()=="String")){
        buffconst.append("@__const.main.");
        buffconst.append(variablename);
        buffconst.append(" = private unnamed_addr constant [");
        buffconst.append(std::to_string(node.elements().size()));
        buffconst.append(" x ");
        buffconst.append(itypes[node.get_type()]);
        buffconst.append("] [");
        
        
        for (const auto& element : node.elements()) {
            element->accept(*this);
            if(element==node.elements()[node.elements().size()-1]) buffconst.append("]");
            else buffconst.append(", ");
        }
        buffconst.append(", align ");
        buffconst.append(std::to_string(alignnum)+"\n");
    }
    
    fromnumbes=0;
    
}

void CodeGen::visit(String& node) {
    if ((st.find(node.text().c_str())=="-1")&&((fromprint==1)||(fromnumbes==1))){
        st.insert(node.text().c_str(),"","", std::to_string(strglobal), "");
        buffglobal.append("@.str");
        if (strglobal>0){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append(std::to_string(node.text().length()+1));
        buffglobal.append(" x i8] c\"");
        buffglobal.append(node.text().c_str());
        buffglobal.append("\\00\", align 1\n");
        strglobal++;
    }
    if (fromprint==1){
        buff.append("  %"+pref[iprint]+" = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ");
    }
    if ((st.find(node.text().c_str())!="-1")&&(fromprint==1)){
        buff.append("([");
        buff.append(std::to_string(node.text().length()+1));
        buff.append(" x i8], ");
        buff.append("[");
        buff.append(std::to_string(node.text().length()+1));
        buff.append(" x i8]* @.str");
        if (st.find(node.text().c_str())!="0"){
            buff.append(".");
            buff.append(st.find(node.text().c_str()));
        }
        buff.append(", i32 0, i32 0))\n");
    }
    if (var==1){
        buffglobal.append("@.str");
        if (strglobal>0){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append(std::to_string(node.text().length()+1));
        buffglobal.append(" x i8] c\"");
        buffglobal.append(node.text().c_str());
        buffglobal.append("\\00\", align 1\n");
        
        
        if (strglobal>0){
            st.insert(variablename,"",pref[iname]+"st","@.str."+std::to_string(strglobal),"");
        } else {
            st.insert(variablename,"",pref[iname]+"st","@.str","");
        }
        buff.append("  %");
        buff.append(pref[iname]+"st");
        buff.append(" = alloca i8*, align 8\n");
        buff.append("  store i8* getelementptr inbounds ([");
        buff.append(std::to_string(node.text().length()+1));
        buff.append(" x i8], [");
        buff.append(std::to_string(node.text().length()+1));
        buff.append(" x i8]* ");
        buff.append(st.find(variablename));
        buff.append(", i32 0, i32 0), i8** %");
        buff.append(st.findname(variablename));
        buff.append(", align 8\n");
        strglobal++;
    }
    if (fromnumbes==1){
        buffconst.append("i8* getelementptr inbounds ([");
        buffconst.append(std::to_string(node.text().length()+1));
        buffconst.append(" x i8], [");
        buffconst.append(std::to_string(node.text().length()+1));
        buffconst.append(" x i8]* ");
        buffconst.append("@.str");
        if (st.find(node.text().c_str())!="0"){
            buffconst.append(".");
            buffconst.append(st.find(node.text().c_str()));
        }
        buffconst.append(", i32 0, i32 0)");
    }
    if (fromassignment==1){
        st.insert(variablename,"",pref[iarray]+"ar","@__const.main.","Array");
        
        buff.append("  %");
        buff.append(pref[iarray]+"ar");
        buff.append(" = alloca [");
        buff.append(std::to_string(arraylength));
        buff.append(" x ");
        buff.append(itypes[node.get_type()]);
        buff.append("], align "+std::to_string(alignnum)+"\n");
        
        iarray++;
        
        buff.append("  %");
        buff.append(pref[iarray]+"ar");
        buff.append(" = bitcast [");
        buff.append(std::to_string(arraylength));
        buff.append(" x ");
        buff.append(itypes[node.get_type()]);
        buff.append("]* %");
        buff.append(pref[iarray-1]+"ar");
        buff.append(" to i8*\n");
        
        
        buff.append("  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align ");
        buff.append(std::to_string(alignnum));
        buff.append(" %"+pref[iarray]+"ar");
        buff.append(", i8* align ");
        buff.append(std::to_string(alignnum) +" bitcast ([");
        buff.append(std::to_string(arraylength));
        buff.append(" x ");
        buff.append(itypes[node.get_type()]);
        buff.append("]* ");
        buff.append("@__const.main.");
        buff.append(variablename);
        buff.append(" to i8*), i64 ");
        buff.append(std::to_string(arraylength*(std::stoi(align[node.get_type()]))));
        buff.append(", i1 false)\n");
    }
    
}

void CodeGen::visit(Number& node) {
    if ((fromfuncall==1)&&(fromfunction!=1)){
        funccall.push_back(node.text().c_str());
    }
    if (fromarrayelem==1){
        arrayindex=node.text().c_str();
    }
    if (fromarithmetic==1){
        operations.push_back(node.text().c_str());
    }
    if (fromnumbes==1){
        buffglobal.append(itypes[node.get_type()]);
        buffglobal.append(" ");
        buffglobal.append(node.text().c_str());
        
    }
    if ((fromprint==1)&&(fromarrayelem!=1)&&(needindex!=1)){
        buff.append("  %"+pref[iprint]+" = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ");
    }
    if ((st.find(intformat)=="-1")&&(fromprint==1)&&(fromarrayelem!=1)){
        st.insert(intformat,"","", std::to_string(strglobal), "");
        buffglobal.append("@.str");
        if (strglobal>0){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append("3 x i8] c\"");
        buffglobal.append(intformat);
        buffglobal.append("\", align 1\n");
        strglobal++;
    }
    if ((st.find(intformat)!="-1")&&(fromprint==1)&&(fromarrayelem!=1)&&(needindex!=1)){
        buff.append("([");
        buff.append("3 x i8], ");
        buff.append("[");
        buff.append("3 x i8]* @.str");
        if (st.find(intformat)!="0"){
            buff.append(".");
            buff.append(st.find(intformat));
        }
        buff.append(", i32 0, i32 0),");
        buff.append(" i32 ");
        buff.append(node.text().c_str());
        buff.append(")\n");
    }
    if (var==1){
        if (strglobal>0){
            st.insert(variablename,"",pref[iname]+"in","@.str."+std::to_string(strglobal),"");
        } else {
            st.insert(variablename,"",pref[iname]+"in","@.str","");
            
        }
        buff.append("  %");
        buff.append(pref[iname]+"in");
        buff.append(" = alloca i32, align 4\n");
        buff.append("  store i32 ");
        buff.append(node.text().c_str());
        buff.append(", i32* %");
        buff.append(pref[iname]+"in");
        buff.append(", align 4\n");
    }
}

void CodeGen::visit(Type& node) {
    if (fromargs==1){
        funcargumenttype.push_back(node.text().c_str());
    }
}

void CodeGen::visit(Name& node) {
    
    if ((var==1)||(fromarray==1)||(fromassignment==1)||(fromarrayelem==1)||(fromfuncall==1)){
        variablename=node.text().c_str();
    }
    if ((fromfuncall==1)&&(fromfunction!=1)){
        buff.append("  %"+pref[ifunc]+"fu = load i32, i32* %"+st.findname(variablename)+", align 4\n");
        funccall.push_back("%"+pref[ifunc]+"fu");
    }
    if ((fromprint==1)&&(fromarrayelem!=1)){
        if (st.find(format[node.get_type()])=="-1"){
            st.insert(format[node.get_type()],"","", std::to_string(strglobal), "");
            buffglobal.append("@.str");
            if (strglobal>0){
                buffglobal.append(".");
                buffglobal.append(std::to_string(strglobal));
            }
            buffglobal.append(" = private unnamed_addr constant [");
            buffglobal.append("3 x i8] c\"");
            buffglobal.append(format[node.get_type()]);
            buffglobal.append("\", align 1\n");
            strglobal++;
        }
        
        if ((st.findtype(node.text().c_str())=="Array")&&(fromarrayelem!=1)){
            buff.append("  %"+pref[iname]+"va = alloca i32, align 4\n");
            buff.append("  store i32 0, i32* %"+pref[iname]+"va, align 4\n");
            buff.append("  br label %"+pref[iname]+"la\n\n");
            
            
            buff.append(""+pref[iname]+"la:\t\t\t ; preds = %"+pref[iname+1]+"la, %0\n");
            buff.append("  %"+pref[iname+1]+"va = load i32, i32* %"+pref[iname]+"va, align 4\n");
            buff.append("  %"+pref[iname+2]+"va = icmp slt i32 %"+pref[iname+1]+"va, "+std::to_string(arraylength)+"\n");
            buff.append("  br i1 %"+pref[iname+2]+"va, label %"+pref[iname+2]+"la, label %"+pref[iname+3]+"la\n\n");
            
            
            buff.append(""+pref[iname+2]+"la:\t\t\t ; preds = %"+pref[iname]+"la\n");
            buff.append("  %"+pref[iname+3]+"va = load i32, i32* %"+pref[iname]+"va, align 4\n");
            buff.append("  %"+pref[iname+4]+"va = sext i32 %"+pref[iname+3]+"va to i64\n");
            buff.append("  %"+pref[iname+5]+"va = getelementptr inbounds  ["+std::to_string(arraylength)+" x "+itypes[node.get_type()]+"], ["+std::to_string(arraylength)+" x "+itypes[node.get_type()]+"]* %"+st.findname(node.text().c_str())+", i64 0, i64 %"+pref[iname+4]+"va\n");
            buff.append("  %"+pref[iname+6]+"va = load "+itypes[node.get_type()]+", "+itypes[node.get_type()]+"* %"+pref[iname+5]+"va, align "+align[node.get_type()]+"\n");
            buff.append("  %"+pref[iname+7]+"va = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str");
            if (st.find(format[node.get_type()])!="0"){
                buff.append(".");
                buff.append(st.find(format[node.get_type()]));
            }
            buff.append(", i32 0, i32 0), "+itypes[node.get_type()]+" %"+pref[iname+6]+"va)\n");
            buff.append("  br label %"+pref[iname+1]+"la \n\n");
            
            
            buff.append(""+pref[iname+1]+"la:\t\t\t ; preds = %"+pref[iname+2]+"la\n");
            buff.append("  %"+pref[iname+8]+"va = load i32, i32* %"+pref[iname]+"va, align 4\n");
            buff.append("  %"+pref[iname+9]+"va = add nsw i32 %"+pref[iname+8]+"va, 1\n");
            buff.append("  store i32 %"+pref[iname+9]+"va, i32* %"+pref[iname]+"va, align 4\n");
            buff.append("  br label %"+pref[iname]+"la \n\n");
            
            
            buff.append(""+pref[iname+3]+"la:\t\t\t ; preds = %"+pref[iname]+"la\n");
        } else {
            if (st.findscope(node.text().c_str())=="modifiedstr")
            {
                buff.append("  %");
                buff.append(pref[iname]+"na");
                buff.append(" = getelementptr inbounds [100 x i8], [100 x i8]* %");
                buff.append(st.findname(variablename));
                buff.append(", i32 0, i32 0\n");
                
                
            }else{
                
                buff.append("  %");
                buff.append(pref[iname]+"na");
                buff.append(" = load ");
                buff.append(itypes[node.get_type()]);
                buff.append(", ");
                buff.append(itypes[node.get_type()]);
                buff.append("* %");
                buff.append(st.findname(node.text().c_str()));
                buff.append(", align ");
                buff.append(align[node.get_type()]);
                buff.append("\n");
            }
            
            buff.append("  %");
            buff.append(pref[iprint]);
            buff.append("pr = call i32");
            buff.append(" (i8*, ...) @printf(i8* getelementptr inbounds ");
            buff.append("([");
            buff.append("3 x i8], ");
            buff.append("[");
            buff.append("3 x i8]* ");
            buff.append(st.find(node.text().c_str()));
            if (st.find(format[node.get_type()])!="0"){
                buff.append(".");
                buff.append(st.find(format[node.get_type()]));
            }
            buff.append(", i32 0, i32 0), ");
            buff.append(itypes[node.get_type()]);
            buff.append(" %");
            buff.append(pref[iname]+"na");
            buff.append(")\n");
        }
    }
    if (((fromifconstrukt==1)||(fromwhile==1)||(fromarithmetic==1)||(needindex==1))&&(fromarrayelem!=1)&&(fromfuncall!=1)){
        buff.append("  %");
        buff.append(pref[iname]+"na");
        buff.append(" = load ");
        buff.append(itypes[node.get_type()]);
        buff.append(", ");
        buff.append(itypes[node.get_type()]);
        buff.append("* %");
        buff.append(st.findname(node.text().c_str()));
        buff.append(", align ");
        buff.append(align[node.get_type()]);
        buff.append("\n");
        variablename=node.text().c_str();
        
        operations.push_back("%"+pref[iname]+"na");
    }
    if (fromargs==1){
        st.insert((node.text().c_str()),"",pref[iname],"","");
        funcargumentname.push_back(node.text().c_str());
    }
    if (needindex==1){
        //        buff.append("  %");
        //        buff.append(pref[iname+1]+"na");
        //        buff.append(" = sext i32 %");
        //        buff.append(pref[iname]+"na");
        //        buff.append(" to i64\n");
        //        arrayindex=("%"+pref[iname+1]+"na");
        
        
    }
    if (forreadline==1){
        ltype=node.get_type();
    }
    iname++;
}


void CodeGen::visit(Funcname& node) {
    functionname=node.text().c_str();
}

void CodeGen::visit(R_float& node) {
    if ((st.find(floatformat)=="-1")&&(fromprint==1)){
        st.insert(intformat,"","", std::to_string(strglobal), "");
        buffglobal.append("@.str");
        if (strglobal>0){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append("3 x i8] c\"");
        buffglobal.append(floatformat);
        buffglobal.append("\", align 1\n");
        strglobal++;
    }
    if ((st.find(floatformat)!="-1")&&(fromprint==1)){
        buff.append("([");
        buff.append("3 x i8], ");
        buff.append("[");
        buff.append("3 x i8]* @.str");
        if (st.find(floatformat)!="-1"){
            buff.append(".");
            buff.append(st.find(floatformat));
        }
        buff.append(", i32 0, i32 0),");
        buff.append(" i32 ");
        buff.append(node.text().c_str());
        buff.append(")\n");
    }
    if (var==1){
        if (strglobal>0){
            st.insert(variablename,"",pref[iname]+"fl","@.str."+std::to_string(strglobal),"");
        } else {
            st.insert(variablename,"",pref[iname]+"fl","@.str","");
        }
        buff.append("  %");
        buff.append(pref[iname]+"fl");
        buff.append(" = alloca float, align 4\n");
        buff.append("  store float ");
        buff.append(node.text().c_str());
        buff.append(", i32* %");
        buff.append(pref[iname]+"fl");
        buff.append(", align 4\n");
    }
    iname++;
}

void CodeGen::visit(Secname& node) {
    buff.append("  %");
    buff.append(pref[iname]+"na");
    buff.append(" = load ");
    buff.append(itypes[node.get_type()]);
    buff.append(", ");
    buff.append(itypes[node.get_type()]);
    buff.append("* %");
    buff.append(st.findname(node.text().c_str()));
    buff.append(", align ");
    buff.append(align[node.get_type()]);
    buff.append("\n");
    secvariablename=node.text().c_str();
    
    iname++;
}

void CodeGen::visit(Comparemembers& node) {
    comparemem=node.text().c_str();
}

void CodeGen::visit(Variable& node) {
    var=1;
    node.elements()[1]->accept(*this);
    node.elements()[0]->accept(*this);
    node.elements()[2]->accept(*this);
    var=0;
}

void CodeGen::visit(Array& node) {
    arraylength=0;
    fromarray=1;
    node.elements()[0]->accept(*this);//идем в имя
    node.elements()[2]->accept(*this);// идем в элементы
    st.insert(variablename,std::to_string(arraylength),pref[iarray]+"ar","@__const.main.","Array");
    
    buff.append("  %");
    buff.append(pref[iarray]+"ar");
    buff.append(" = alloca [");
    buff.append(std::to_string(arraylength));
    buff.append(" x ");
    buff.append(itypes[node.get_type()]);
    buff.append("], align "+std::to_string(alignnum)+"\n");
    
    iarray++;
    
    buff.append("  %");
    buff.append(pref[iarray]+"ar");
    buff.append(" = bitcast [");
    buff.append(std::to_string(arraylength));
    buff.append(" x ");
    buff.append(itypes[node.get_type()]);
    buff.append("]* %");
    buff.append(pref[iarray-1]+"ar");
    buff.append(" to i8*\n");
    
    
    buff.append("  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align ");
    buff.append(std::to_string(alignnum));
    buff.append(" %"+pref[iarray]+"ar");
    buff.append(", i8* align ");
    buff.append(std::to_string(alignnum) +" bitcast ([");
    buff.append(std::to_string(arraylength));
    buff.append(" x ");
    buff.append(itypes[node.get_type()]);
    buff.append("]* ");
    buff.append("@__const.main.");
    buff.append(variablename);
    buff.append(" to i8*), i64 ");
    buff.append(std::to_string(arraylength*(std::stoi(align[node.get_type()]))));
    buff.append(", i1 false)\n");
    
    fromarray=0;
    iarray++;
}

void CodeGen::visit(Ifconstrukt& node) {
    fromifconstrukt=1;
    node.elements()[0]->accept(*this);
    node.elements()[1]->accept(*this);
    node.elements()[2]->accept(*this);
    buff.append("  %"+pref[iif]+"if = icmp ");
    buff.append(compare[comparemem]);
    buff.append(" "+itypes[node.get_type()]+" %"+pref[iname-2]+"na, %"+pref[iname-1]+"na\n");
    buff.append("  br i1 %"+pref[iif]+"if, label %"+pref[iif+1]+"if, label %"+pref[iif+2]+"if \n\n");
    buff.append(pref[iif+1]+"if:\t\t\t ;preds = %0\n");
    fromifconstrukt=0;
    
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])&&
           (element!=node.elements()[2])){
            element->accept(*this);
        }
    }
    fromifconstrukt=1;
    if(fromwholeif!=1){
        buff.append(" br label %"+pref[iif+2]+"if\n\n");
        buff.append(pref[iif+2]+"if:\t\t\t;preds = %"+pref[iif+1]+"if, %0\n");
    }
    fromifconstrukt=0;
}

void CodeGen::visit(Arithmetic& node) {
    forreadline=1;
    node.elements()[0]->accept(*this);
    forreadline=0;
    
    fromarithmetic=1;
    for (const auto& element : node.elements()) {
        if(element!=node.elements()[0]){
            element->accept(*this);
        }
    }
    
    fromarithmetic=0;
    fromassignment=1;
    node.elements()[0]->accept(*this);
    if(fromreadline==1){
        if(ltype=="String"){
            st.modify(variablename,"modifiedstr",pref[ireadline]+"rl","@.str","");
        }
        buff.append(pref[ireadline+1]+"rl"+")\n");
        fromreadline=0;
    }else if (fromfuncall==1){
        buff.append("  store i32 %"+pref[ifunc+1]+"fu, i32* %"+st.findname(variablename)+", align 4\n");
    } else {
        buff.append("  store i32 %"+pref[iassignment-1]+"op, "+itypes[node.get_type()]+"* %"+st.findname(variablename)+", align 4\n");
    }
    fromassignment=0;
    fromreadline=0;
    fromfuncall=0;
}

void CodeGen::visit(R_while& node) {
    fromifconstrukt=1;
    node.elements()[0]->accept(*this);
    node.elements()[1]->accept(*this);
    node.elements()[2]->accept(*this);
    
    buff.append("  br label %"+pref[iwh]+"wh\n\n");
    
    
    buff.append(pref[iwh]+"wh:\t\t\t ;preds = %"+pref[iwh+1]+"wh, %0\n");
    buff.append("  %"+pref[iwh+2]+"wh = load "+itypes[node.get_type()]+", "+itypes[node.get_type()]+"* %"+st.findname(variablename)+", align 4\n");
    buff.append("  %"+pref[iwh+3]+"wh = load "+itypes[node.get_type()]+", "+itypes[node.get_type()]+"* %"+st.findname(secvariablename)+", align 4\n");
    buff.append("  %"+pref[iwh+4]+"wh = icmp "+compare[comparemem]+" i32 %"+pref[iwh+2]+"wh, %"+pref[iwh+3]+"wh\n");
    buff.append("  br i1 %"+pref[iwh+4]+"wh, label %"+pref[iwh+1]+"wh, label %"+pref[iwh+5]+"wh\n\n");
    
    
    buff.append(pref[iwh+1]+"wh:\t\t\t ;preds = %"+pref[iwh]+"wh\n");
    fromifconstrukt=0;
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[0])&&
           (element!=node.elements()[1])&&
           (element!=node.elements()[2])){
            element->accept(*this);
        }
    }
    fromifconstrukt=1;
    
    buff.append(" br label %"+pref[iwh]+"wh\n\n");
    buff.append(pref[iwh+5]+"wh:\t\t\t;preds = %"+pref[iwh]+"wh\n");
    fromifconstrukt=0;
}

void CodeGen::visit(Elseconstrukt& node) {
    buff.append(" br label %"+pref[iif+3]+"if\n\n");
    
    buff.append(pref[iif+2]+"if:\n");
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    buff.append(" br label %"+pref[iif+3]+"if\n\n");
    
    buff.append(pref[iif+3]+"if:\n");
}

void CodeGen::visit(Wholeif& node) {
    fromwholeif=1;
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    fromwholeif=0;
}


void CodeGen::visit(Opplus& node) {
    node.elements()[0]->accept(*this);
    buff.append("  %"+pref[iassignment]+"op = add nsw i32 ");
    
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append(", ");
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append("\n");
    operations.push_back("%"+pref[iassignment]+"op");
    iassignment++;
    
}

void CodeGen::visit(Opminus& node) {
    node.elements()[0]->accept(*this);
    buff.append("  %"+pref[iassignment]+"op = sub nsw i32 ");
    
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append(", ");
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append("\n");
    operations.push_back("%"+pref[iassignment]+"op");
    iassignment++;
    
}

void CodeGen::visit(Opmulti& node) {
    node.elements()[0]->accept(*this);
    buff.append("  %"+pref[iassignment]+"op = mul nsw i32 ");
    
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append(", ");
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append("\n");
    operations.push_back("%"+pref[iassignment]+"op");
    iassignment++;
}

void CodeGen::visit(Opdivision& node) {
    node.elements()[0]->accept(*this);
    buff.append("  %"+pref[iassignment]+"op = sdiv i32 ");
    
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append(", ");
    buff.append(operations.front());
    operations.pop_front();
    
    buff.append("\n");
    operations.push_back("%"+pref[iassignment]+"op");
    iassignment++;
}

void CodeGen::visit(Function& node) {
    fromfunction=1;
    bufffunc.append("define "+itypes[node.get_type()]+" @");
    node.elements()[3]->accept(*this);
    bufffunc.append(functionname);
    bufffunc.append("(");
    node.elements()[1]->accept(*this);
    int argsnum=funcargumentname.size();
    for(int i = 0; i < argsnum; i++){
        bufffunc.append(itypes[funcargumenttype.front()]);
        bufffunc.append(" %");
        bufffunc.append(funcargumentname.front());
        if ((i+1)!=argsnum) bufffunc.append(", ");
        funcargumentname.pop_front();
        funcargumenttype.pop_front();
    }
    bufffunc.append(") #0 {\n");
    iname=iname-funcargumentname.size();
    node.elements()[1]->accept(*this);
    iname=iname-argsnum*2;
    for(int i = 0; i < argsnum;i++ ){
        bufffunc.append("  %");
        bufffunc.append(pref[iname]);
        bufffunc.append(" = alloca i32, align 4\n");
        bufffunc.append("  store i32 %"+funcargumentname.front()+", i32* %"+pref[iname]+", align 4\n");
        funcargumentname.pop_front();
        funcargumenttype.pop_front();
        iname++;
    }
    
    
    for (const auto& element : node.elements()) {
        if((element!=node.elements()[3])&&
           (element!=node.elements()[0])){
            element->accept(*this);
        }
    }
    fromfuncall=1;
    node.elements()[0]->accept(*this);
    fromfuncall=0;
    
    bufffunc.append(buff);
    buff.assign("");
    bufffunc.append("  %"+pref[ifunc+3]+"fu = load i32, i32* %"+st.findname(variablename)+", align 4\n");
    bufffunc.append("ret "+itypes[node.get_type()]+" %");
    bufffunc.append(pref[ifunc+3]+"fu");
    bufffunc.append("\n}\n");
    //    buff.append("define i32 @main() #0 {\n");
    //    buff.append("  %aa = alloca i32, align 4\n");
    //    buff.append("  store i32 0, i32* %aa, align 4\n");
    
    for(int i = 0; i<100 ; i++){
        st.head[i]=NULL;
    }
    //    funccall.clear();
    fromfunction=0;
}

void CodeGen::visit(Args& node) {
    fromargs=1;
    for (const auto& element : node.elements()) {
        element->accept(*this);
    }
    fromargs=0;
}

void CodeGen::visit(Ret_type& node) {
}
void CodeGen::visit(Arrayelem& node) {
    fromfuncall=0;
    fromarrayelem=1;
    
    needindex=1;
    node.elements()[1]->accept(*this); //отсюда нужен индекс массива
    needindex=0;
    
    node.elements()[0]->accept(*this);
    buff.append("  %"+pref[ielem]+"el = getelementptr inbounds [");
    buff.append(st.findscope(variablename)+" x ");
    buff.append(itypes[node.get_type()]+"], [");
    buff.append(st.findscope(variablename)+" x ");
    buff.append(itypes[node.get_type()]+"]* %");
    buff.append(st.findname(variablename)+", i64 0, i64 "+ arrayindex +"\n");
    
    buff.append("  %"+pref[ielem+1]+"el = load i32, i32* %"+pref[ielem]+"el, align 4\n");
    funccall.push_back("%"+pref[ielem+1]+"el");
    
    if (fromarithmetic==1){
        operations.push_back("  %"+pref[ielem+1]+"el");
    }
    if (fromprint==1){
        if (st.find(format[node.get_type()])=="-1"){
            st.insert(format[node.get_type()],"","", std::to_string(strglobal), "");
            buffglobal.append("@.str");
            if (strglobal>0){
                buffglobal.append(".");
                buffglobal.append(std::to_string(strglobal));
            }
            buffglobal.append(" = private unnamed_addr constant [");
            buffglobal.append("3 x i8] c\"");
            buffglobal.append(format[node.get_type()]);
            buffglobal.append("\", align 1\n");
            strglobal++;
        }
        
        buff.append("  %");
        buff.append(pref[iprint]);
        buff.append("pr = call i32");
        buff.append(" (i8*, ...) @printf(i8* getelementptr inbounds ");
        buff.append("([");
        buff.append("3 x i8], ");
        buff.append("[");
        buff.append("3 x i8]* ");
        buff.append("@.str");
        if (st.find(format[node.get_type()])!="0"){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        
        if (st.find(format[node.get_type()])!="0"){
            buff.append(".");
            buff.append(st.find(format[node.get_type()]));
        }
        buff.append(", i32 0, i32 0), ");
        buff.append(itypes[node.get_type()]);
        buff.append(" %");
        buff.append(pref[ielem+1]+"el");
        buff.append(")\n");
        
    }
    fromarrayelem=0;
}

void CodeGen::visit(Readline& node) {
    if (st.find(format[ltype])=="-1"){
        st.insert(format[ltype],"","", std::to_string(strglobal), "");
        buffglobal.append("@.str");
        if (strglobal>0){
            buffglobal.append(".");
            buffglobal.append(std::to_string(strglobal));
        }
        buffglobal.append(" = private unnamed_addr constant [");
        buffglobal.append("3 x i8] c\"");
        buffglobal.append(format[ltype]);
        buffglobal.append("\", align 1\n");
        strglobal++;
    }
    
    if (ltype=="String"){
        buff.append("  %");
        buff.append(pref[ireadline]+"rl = alloca [100 x i8], align 16\n");
        buff.append("  %");
        buff.append(pref[ireadline+1]+"rl = getelementptr inbounds [100 x i8], [100 x i8]* %"+pref[ireadline]+"rl, i32 0, i32 0\n");
        
    }
    
    fromreadline=1;
    buff.append("  %");
    buff.append(pref[ireadline+3]);
    buff.append("rl = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str");
    if (st.find(format[ltype])!="0"){
        buff.append(".");
        buff.append(st.find(format[ltype]));
    }
    buff.append(", i32 0, i32 0), ");
    if (ltype=="String"){
        buff.append("i8* ");
    } else buff.append("i32* ");
    buff.append("%");
}

void CodeGen::visit(Functioncall& node) {
    fromfuncall=1;
    
    int j;
    for ( j = (node.elements().size()/2)+1; j <= node.elements().size()-1; j++) {
        node.elements()[j]->accept(*this);
        fromfuncall=1;
        ifunc++;
    }
    
    buff.append("  %");
    buff.append(pref[ifunc]+"fu = call i32 @");
    buff.append(functionname);
    buff.append("(");
    
    for ( j = (node.elements().size()/2); j >0; j--) {
        buff.append("i32 ");
        buff.append(funccall.front());
        funccall.pop_front();
        //        %"+pref[ifunc-j]+"fu");
        if(j-1!=0) buff.append(", ");
    }
    buff.append(")\n");
    if(fromarithmetic!=1){fromfuncall=0;}
    
}
