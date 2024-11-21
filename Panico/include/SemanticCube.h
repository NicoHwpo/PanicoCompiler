// SemanticCube.h
#ifndef SEMANTIC_CUBE_H
#define SEMANTIC_CUBE_H

#include <string>
#include <unordered_map>
#include "Types.h"

class SemanticCube {
public:
    SemanticCube();
    Type getResultType(Type &type1, Type &type2, const std::string &op);
    Type getTypeFromString(const std::string &type);
    std::string getStringFromType(const Type &type);
    Type getTypeFromConstant(const std::string &constant);

private:
    std::unordered_map<std::string, Type> cube;
    void initializeCube();
};

#endif // SEMANTIC_CUBE_H
