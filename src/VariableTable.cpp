// VariableTable.cpp
#include "VariableTable.h"

bool VariableTable::addVariable(const std::string &name, Type type, int memoryAddress) {
    // if (variables.find(name) != variables.end()) {
    //     return false;
    // }
    variables[name] = {name, type, memoryAddress};
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

bool VariableTable::setMemoryAddress(const std::string &name, int memoryAddress) {
    if (variables.find(name) == variables.end()) {
        return false;
    }
    variables[name].memoryAddress = memoryAddress;
    return true;
}