// SemanticCube.cpp
#include "SemanticCube.h"

SemanticCube::SemanticCube() {
    initializeCube();
}

void SemanticCube::initializeCube() {
    // 0 = INT, 1 = FLOAT
    // additions
    cube["0+0"] = INT;
    cube["0+1"] = FLOAT;
    cube["1+0"] = FLOAT;
    cube["1+1"] = FLOAT;
    // subtractions
    cube["0-0"] = INT;
    cube["0-1"] = FLOAT;
    cube["1-0"] = FLOAT;
    cube["1-1"] = FLOAT;
    // multiplications
    cube["0*0"] = INT;
    cube["0*1"] = FLOAT;
    cube["1*0"] = FLOAT;
    cube["1*1"] = FLOAT;
    // divisions
    cube["0/0"] = FLOAT;
    cube["0/1"] = FLOAT;
    cube["1/0"] = FLOAT;
    cube["1/1"] = FLOAT;
    // comparisons
        // less than
    cube["0<0"] = BOOL;
    cube["0<1"] = BOOL;
    cube["1<0"] = BOOL;
    cube["1<1"] = BOOL;
        // greater than
    cube["0>0"] = BOOL;
    cube["0>1"] = BOOL;
    cube["1>0"] = BOOL;
    cube["1>1"] = BOOL;
        // equal to
    cube["0==0"] = BOOL;
    cube["0==1"] = BOOL;
    cube["1==0"] = BOOL;
    cube["1==1"] = BOOL;
        // not equal to
    cube["0!=0"] = BOOL;
    cube["0!=1"] = BOOL;
    cube["1!=0"] = BOOL;
    cube["1!=1"] = BOOL;
}

Type SemanticCube::getResultType(Type &type1, Type &type2, const std::string &op) {
    std::string key = std::to_string(type1) + op + std::to_string(type2);
    return cube.count(key) ? cube[key] : ERROR;
}

Type SemanticCube::getTypeFromString(const std::string &type) {
    if (type == "int") {
        return INT;
    } else if (type == "float") {
        return FLOAT;
    } else {
        return ERROR;
    }
}
