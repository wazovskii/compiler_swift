#pragma once

#include <iostream>

namespace hash {

const int MAX = 100;

class Unit {
    std::string identifier, scope, type, def, lineNo;
    Unit* next;
    
public:
    Unit()
    {
        next = NULL;
    }
    
    Unit(std::string key, std::string value, std::string type, std::string lineNo, std::string def)
    {
        this->identifier = key;
        this->scope = value;
        this->type = type;
        this->lineNo = lineNo;
        this->def = def;
        next = NULL;
    }
    
    void print()
    {
        std::cout << "Identifier's Name:" << identifier
        << "\nType:" << type
        << "\nScope: " << scope
        << "\nLine Number: " << lineNo
        << "\nDefined?: " << def << std::endl;
        std::cout << "\n";
    }
    friend class SymbolTable;
};

class SymbolTable {
    
    
public:
    Unit* head[MAX];
    
    SymbolTable()
    {
        for (int i = 0; i < MAX; i++)
            head[i] = NULL;
    }
    int hashf(std::string id);
    bool insert(std::string id, std::string scope, std::string Type, std::string lineno, std::string def);
    std::string find(std::string id);
    std::string findname(std::string id);
    std::string findtype(std::string id);
    std::string findscope(std::string id);

    bool deleteRecord(std::string id);
    bool modify(std::string id, std::string scope, std::string Type, std::string lineno, std::string def);
};

inline bool SymbolTable::modify(std::string id, std::string s, std::string t, std::string l, std::string d)
{
    int index = hashf(id);
    Unit* start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL) {
        if (start->identifier == id) {
            start->scope = s;
            start->type = t;
            start->lineNo = l;
            start->def=d;
            return true;
        }
        start = start->next;
    }
    return false;
}

inline bool SymbolTable::deleteRecord(std::string id)
{
    int index = hashf(id);
    Unit* tmp = head[index];
    Unit* par = head[index];
    if (tmp == NULL) {
        return false;
    }
    if (tmp->identifier == id && tmp->next == NULL) {
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    while (tmp->identifier != id && tmp->next != NULL) {
        par = tmp;
        tmp = tmp->next;
    }
    if (tmp->identifier == id && tmp->next != NULL) {
        par->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    else {
        par->next = NULL;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    return false;
}

inline std::string SymbolTable::find(std::string id)
{
    int index = hashf(id);
    Unit* start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL) {
        if (start->identifier == id) {
            //start->print();
            return start->lineNo;
        }
        start = start->next;
    }
    return "-1";
}

inline std::string SymbolTable::findname(std::string id)
{
    int index = hashf(id);
    Unit* start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL) {
        if (start->identifier == id) {
            //start->print();
            return start->type;
        }
        start = start->next;
    }
    return "-1";
}

inline std::string SymbolTable::findtype(std::string id)
{
    int index = hashf(id);
    Unit* start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL) {
        if (start->identifier == id) {
            //start->print();
            return start->def;
        }
        start = start->next;
    }
    return "-1";
}

inline std::string SymbolTable::findscope(std::string id)
{
    int index = hashf(id);
    Unit* start = head[index];
    if (start == NULL)
        return "-1";
    while (start != NULL) {
        if (start->identifier == id) {
            //start->print();
            return start->scope;
        }
        start = start->next;
    }
    return "-1";
}

inline bool SymbolTable::insert(std::string id, std::string scope, std::string Type, std::string lineno, std::string def)
{
    int index = hashf(id);
    Unit* p = new Unit(id, scope, Type, lineno, def);
    if (head[index] == NULL) {
        head[index] = p;
        return true;
    }
    else {
        Unit* start = head[index];
        while (start->next != NULL)
            start = start->next;
        start->next = p;
        return true;
    }
    return false;
}

inline int SymbolTable::hashf(std::string id)
{
    int asciiSum = 0;
    for (int i = 0; i < id.length(); i++) {
        asciiSum = asciiSum + id[i];
    }
    return (asciiSum % 100);
}
}

