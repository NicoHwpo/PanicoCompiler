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
    std::unordered_map<std::string, VariableInfo> parameters;
    VariableTable variableTable;
    int startAddress = -1;
};

class FunctionDirectory {
public:
    bool addFunction(const std::string &name,Type returnType);
    FunctionInfo *getFunctionInfo(const std::string &name);
    std::unordered_map<std::string, FunctionInfo> getDirectory() const { return directory; }
    FunctionInfo *getCurrentFunction() { return currentFunction; }
    bool addParameter(const std::string &name, Type type);
    void setMainFunction(FunctionInfo *function) { mainFunction = function; }
    FunctionInfo *getMainFunction() { return mainFunction; }
    
private:
    FunctionInfo *mainFunction = nullptr;
    FunctionInfo *currentFunction = nullptr;
    std::unordered_map<std::string, FunctionInfo> directory;
};

#endif // FUNCTION_DIRECTORY_H
