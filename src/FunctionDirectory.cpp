// FunctionDirectory.cpp
#include "FunctionDirectory.h"

bool FunctionDirectory::addFunction(const std::string &name, Type returnType) {
    if (directory.find(name) != directory.end()) {
        return false;
    }
    directory[name] = {name, returnType};
    currentFunction = &directory[name];
    return true;
}

FunctionInfo* FunctionDirectory::getFunctionInfo(const std::string &name) {
    return directory.count(name) ? &directory[name] : nullptr;
}

std::unordered_map<std::string, FunctionInfo> *FunctionDirectory::getFunctionDirectory() {
    return &directory;
}

FunctionInfo *FunctionDirectory::getCurrentFunction() {
    return currentFunction;
}

void FunctionDirectory::setMainFunction(FunctionInfo *function) {
    mainFunction = function;
}

void FunctionDirectory::setCurrentFunction(FunctionInfo *function) {
    currentFunction = function;
}

FunctionInfo *FunctionDirectory::getMainFunction() {
    return mainFunction;
}

void FunctionDirectory::setStartAddressToCurFunc(int startAddress) {
    if (currentFunction == nullptr) {
        std::cerr << "No function to set start address to." << std::endl;
        return;
    }
    currentFunction->startAddress = startAddress;
    return;
}

bool FunctionDirectory::addParameterToCurFunc(const std::string &name, Type type, int memoryAddress) {
    if (currentFunction == nullptr) {
        std::cerr << "No function to add parameter to." << std::endl;
        return false;
    }
    // Check if parameter name is already declared as a parameter in the current function
    for (const auto &param : currentFunction->parametersTable) {
        if (param.name == name) {
            std::cerr << "Parameter " << name << " already declared as a parameter in this function." << std::endl;
            return false;
        }
    }
    // Check if parameter name is already declared as a variable in the global scope
    // if (mainFunction->variableTable.getVariableInfo(name) != nullptr) {
    //     std::cerr << "Parameter " << name << " already declared as a variable in the global scope." << std::endl;
    //     return false;
    // }
    // add the parameter to the current function's parameter table
    currentFunction->parametersTable.push_back({name, type, memoryAddress});
    currentFunction->numParams++;
    return true;
}

bool FunctionDirectory::addVariableToCurFunc(const std::string &name, Type type, int memoryAddress) {
    if (currentFunction == nullptr) {
        std::cerr << "No function to add variable to." << std::endl;
        return false;
    }
    // validar que no haya en los parametros
    for (const auto &param : currentFunction->parametersTable) {
        if (param.name == name) {
            std::cerr << "Variable " << name << " already declared as a parameter in this function." << std::endl;
            return false;
        }
    }
    // validar que no haya en la funcion actual
    if (currentFunction->variableTable.getVariableInfo(name) != nullptr) {
        std::cerr << "Variable " << name << " already declared in this scope." << std::endl;
        return false;
    }
    // validar que no haya en el global
    // if (mainFunction->variableTable.getVariableInfo(name) != nullptr) {
    //     std::cerr << "Variable " << name << " already declared in the global scope." << std::endl;
    //     return false;
    // }
    // agarro la tabla de variables de la funcion actual y le agrego la variable
    // si se agrega correctamente, regreso true
    currentFunction->variableTable.addVariable(name, type, memoryAddress);
    currentFunction->numVars++;
    return true;
}

VariableInfo* FunctionDirectory::getVarInfoFuncScope(const std::string &name) {
    if (currentFunction != nullptr) {
        if (currentFunction->variableTable.getVariableInfo(name) != nullptr) {
            return currentFunction->variableTable.getVariableInfo(name);
        }
    }
    return nullptr;
}

VariableInfo* FunctionDirectory::getVarInFuncOrGlobalScope(const std::string &name) {
    if (currentFunction != nullptr) {
        // check if the variable is in the current function's variable table
        if (currentFunction->variableTable.getVariableInfo(name) != nullptr) {
            return currentFunction->variableTable.getVariableInfo(name);
        }
        // check if the variable is in the current function's parameters table
        for (auto &param : currentFunction->parametersTable) {
            if (param.name == name) {
                return &param;
            }
        }
    }
    // check if the variable is in the global scope
    if (mainFunction != nullptr) {
        if (mainFunction->variableTable.getVariableInfo(name) != nullptr) {
            return mainFunction->variableTable.getVariableInfo(name);
        }
    }
    return nullptr;
}

bool FunctionDirectory::isGlobalScope() {
    return currentFunction == mainFunction;
}