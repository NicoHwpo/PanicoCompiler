#ifndef VARIABLE_TABLE_H
#define VARIABLE_TABLE_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "Types.h"

struct VariableInfo {
    std::string name;
    Type type;
};

class VariableTable {
public:
    VariableTable() { enterScope(); }

    void enterScope();
    void exitScope();
    
    bool addVariable(const std::string &name, Type type);
    VariableInfo* getVariable(const std::string &name);

private:
    std::vector<std::unordered_map<std::string, VariableInfo>> scopes;
};

#endif // VARIABLE_TABLE_H
