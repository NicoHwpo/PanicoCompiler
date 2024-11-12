// FunctionDirectory.cpp
#include "FunctionDirectory.h"

bool FunctionDirectory::addFunction(const std::string &name, Type returnType) {
    if (directory.find(name) != directory.end()) {
        std::cerr << "Function " << name << " already declared." << std::endl;
        return false;
    }
    directory[name] = {name, returnType};
    currentFunction = &directory[name];
    return true;
}

bool FunctionDirectory::addParameter(const std::string &name, Type type) {
    if (currentFunction == nullptr) {
        std::cerr << "No function to add parameter to." << std::endl;
        return false;
    }
    // Check if parameter name is already declared as a parameter in the current function
    if (currentFunction->parameters.find(name) != currentFunction->parameters.end()) {
        std::cerr << "Parameter " << name << " already declared as a parameter in this function." << std::endl;
        return false;
    }
    // Check if parameter name is already declared as a variable in the global scope
    std::unordered_map<std::string, VariableInfo> globalVariables = mainFunction->variableTable.getVariables();
    if (globalVariables.find(name) != globalVariables.end()) {
        std::cerr << "Parameter " << name << " already declared as a variable in the global scope." << std::endl;
        return false;
    }
    currentFunction->parameters[name] = {name, type};
    return true;
}

FunctionInfo* FunctionDirectory::getFunctionInfo(const std::string &name) {
    return directory.count(name) ? &directory[name] : nullptr;
}
