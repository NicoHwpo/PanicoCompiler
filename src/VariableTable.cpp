// VariableTable.cpp
#include "VariableTable.h"

void VariableTable::enterScope() {
    scopes.push_back({});
}

void VariableTable::exitScope() {
    if (!scopes.empty()) {
        scopes.pop_back();
    } else {
        std::cerr << "No scope to exit!" << std::endl;
    }
}

bool VariableTable::addVariable(const std::string &name, Type type) {
    if (scopes.back().find(name) != scopes.back().end()) {
        std::cerr << "Variable " << name << " already declared in this scope." << std::endl;
        return false;
    }
    scopes.back()[name] = {name, type};
    // std::cout << "Variable " << scopes.back()[name].name << " of type " << std::to_string(scopes.back()[name].type) << " added to scope." << std::endl;
    return true;
}

VariableInfo* VariableTable::getVariable(const std::string &name) {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        auto& currentScope = *it;
        if (currentScope.find(name) != currentScope.end()) {
            // std::cout << "Variable " << currentScope[name].name << " of type " << std::to_string(currentScope[name].type) << " found." << std::endl;
            return &currentScope[name];
        }
    }
    std::cerr << "Variable " << name << " not found." << std::endl;
    return nullptr; // Variable not found in any scope
}

