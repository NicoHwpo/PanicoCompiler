// SemanticCube.h
#ifndef SEMANTIC_CUBE_H
#define SEMANTIC_CUBE_H

#include <string>
#include <unordered_map>

enum Type { INT, FLOAT, ERROR }; // INT = 0, FLOAT = 1, ERROR = 2

class SemanticCube {
public:
    SemanticCube();
    Type getResultType(Type type1, Type type2, const std::string &op);

private:
    std::unordered_map<std::string, Type> cube;
    void initializeCube();
};

#endif // SEMANTIC_CUBE_H
