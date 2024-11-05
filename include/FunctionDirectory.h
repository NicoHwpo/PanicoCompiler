// FunctionDirectory.h
#ifndef FUNCTION_DIRECTORY_H
#define FUNCTION_DIRECTORY_H

#include <string>
#include <unordered_map>
#include <vector>
#include "VariableTable.h"

struct FunctionInfo {
    std::string name;
    Type returnType;
    std::vector<VariableInfo> parameters;
    VariableTable variableTable;
    int startAddress;
};

class FunctionDirectory {
public:
    bool addFunction(const std::string &name, Type returnType);
    FunctionInfo* getFunction(const std::string &name);

private:
    std::unordered_map<std::string, FunctionInfo> directory;
};

#endif // FUNCTION_DIRECTORY_H
