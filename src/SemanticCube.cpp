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
    cube["0<0"] = INT;
    cube["0<1"] = INT;
    cube["1<0"] = INT;
    cube["1<1"] = INT;
        // greater than
    cube["0>0"] = INT;
    cube["0>1"] = INT;
    cube["1>0"] = INT;
    cube["1>1"] = INT;
        // equal to
    cube["0==0"] = INT;
    cube["0==1"] = INT;
    cube["1==0"] = INT;
    cube["1==1"] = INT;
        // not equal to
    cube["0!=0"] = INT;
    cube["0!=1"] = INT;
    cube["1!=0"] = INT;
    cube["1!=1"] = INT;
    // assignments
    cube["0=0"] = INT;
    cube["0=1"] = ERROR;
    cube["1=0"] = ERROR;
    cube["1=1"] = FLOAT;
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

std::string SemanticCube::getStringFromType(const Type &type) {
    if (type == INT) {
        return "int";
    } else if (type == FLOAT) {
        return "float";
    } else {
        return "error";
    }
}

Type SemanticCube::getTypeFromConstant(const std::string &constant) {
    if (constant.find('.') != std::string::npos) {
        return FLOAT;
    } else {
        return INT;
    }
}
