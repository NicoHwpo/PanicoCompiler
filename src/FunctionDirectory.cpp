// FunctionDirectory.cpp
#include "FunctionDirectory.h"

bool FunctionDirectory::addFunction(const std::string &name, Type returnType) {
    if (directory.find(name) != directory.end()) {
        std::cerr << "Function " << name << " already declared." << std::endl;
        return false;
    }
    // Initialize FunctionInfo with a new VariableTable for each function
    directory[name] = {name, returnType, {}, VariableTable(), -1};
    return true;
}

FunctionInfo* FunctionDirectory::getFunction(const std::string &name) {
    return directory.count(name) ? &directory[name] : nullptr;
}
