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
    VariableTable parametersTable;
    VariableTable variableTable;
    int startAddress = -1;
    int numVars = 0;
    int numParams = 0;
};

class FunctionDirectory {
public:
    bool addFunction(const std::string &name,Type returnType);
    FunctionInfo *getFunctionInfo(const std::string &name);
    std::unordered_map<std::string, FunctionInfo> *getFunctionDirectory();
    FunctionInfo *getCurrentFunction();

    void setMainFunction(FunctionInfo *function);
    FunctionInfo *getMainFunction();

    void setStartAddressToCurFunc(int startAddress);
    bool addParameterToCurFunc(const std::string &name, Type type);
    bool addVariableToCurFunc(const std::string &name, Type type);
    VariableInfo *getVarInfoFuncScope(const std::string &name);
    VariableInfo *getVarInFuncOrGlobalScope(const std::string &name);
    
private:
    FunctionInfo *mainFunction = nullptr;
    FunctionInfo *currentFunction = nullptr;
    std::unordered_map<std::string, FunctionInfo> directory;
};

#endif // FUNCTION_DIRECTORY_H
