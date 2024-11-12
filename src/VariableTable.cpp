// VariableTable.cpp
#include "VariableTable.h"

bool VariableTable::addVariable(const std::string &name, Type type) {
    // std::cout << "size of variables: " << variables.size() << std::endl;
    if (variables.find(name) != variables.end()) {
        return false;
    }
    variables[name] = {name, type};
    return true;
}

VariableInfo* VariableTable::getVariableInfo(const std::string &name) {
    if (variables.find(name) != variables.end()) {
        return &variables[name];
    }
    std::cerr << "Variable " << name << " not found." << std::endl;
    return nullptr;
}

