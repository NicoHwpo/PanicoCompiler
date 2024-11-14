// VariableTable.cpp
#include "VariableTable.h"

bool VariableTable::addVariable(const std::string &name, Type type) {
    // if (variables.find(name) != variables.end()) {
    //     return false;
    // }
    variables[name] = {name, type};
    return true;
}

VariableInfo* VariableTable::getVariableInfo(const std::string &name) {
    if (variables.find(name) != variables.end()) {
        return &variables[name];
    }
    return nullptr;
}

std::unordered_map<std::string, VariableInfo> *VariableTable::getVariables() {
    return &variables;
}