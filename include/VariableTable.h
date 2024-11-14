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
    int memoryAddress = -1;
};

class VariableTable {
public:
    bool addVariable(const std::string &name, Type type);
    VariableInfo *getVariableInfo(const std::string &name);
    std::unordered_map<std::string, VariableInfo> *getVariables();

private:
    std::unordered_map<std::string, VariableInfo> variables;
};

#endif // VARIABLE_TABLE_H
