#include <iostream>
#include <fstream>
#include <stack>
#include "include/CustomVisitor.h"

// function to print quadruples
void printQuadruplesAsNames(const std::vector<Quadruple> &quadruples) {
    for (size_t i = 0; i < quadruples.size(); i++) {
        const Quadruple &quad = quadruples[i];
        std::cout << i << ": " << quad.op.name << " " << quad.arg1.name << " " << quad.arg2.name << " " << quad.result.name << std::endl;
    }
}
void printQuadruplesAsAddresses(const std::vector<Quadruple> &quadruples) {
    for (size_t i = 0; i < quadruples.size(); i++) {
        const Quadruple &quad = quadruples[i];
        std::string arg1 = std::to_string(quad.arg1.address);
        if (quad.op.name == "ERA" || quad.op.name == "GOSUB") {
            arg1 = quad.arg1.name;
        }
        std::cout << i << ": " << quad.op.name << " " << arg1 << " " << quad.arg2.address << " " << quad.result.address << std::endl;
    }
}

void genOutputObjFile(CustomVisitor &visitor) {
    std::string programName = visitor.functionDirectory.getMainFunction()->name;
    std::ofstream out("./Output/" + programName + ".obj");
    if (!out.is_open()) {
        std::cerr << "Could not open output file." << std::endl;
        return;
    }
    // write constant table to output file
    out << "# Constant Table" << std::endl;
    out << "CONSTANTS" << std::endl;
    for (const auto &constantInt : visitor.memoryManager.getIntConstants()) {
        out << constantInt.second << " " << constantInt.first << std::endl;
    }
    for (const auto &constantFloat : visitor.memoryManager.getFloatConstants()) {
        out << constantFloat.second << " " << constantFloat.first << std::endl;
    }
    for (const auto &constantString : visitor.memoryManager.getStringConstants()) {
        out << constantString.second << " " << constantString.first << std::endl;
    }

    // write the function directory to the output file
    out << std::endl << "# Function Directory" << std::endl;
    out << "FUNCTIONS" << std::endl;
    std::unordered_map<std::string, FunctionInfo> *functionDirectory = visitor.functionDirectory.getFunctionDirectory();
    for (const auto &function : *functionDirectory) {
        FunctionInfo const &funcInfo = function.second;
        int localIntBase = 3000, localFloatBase = 4000;
        if (funcInfo.name == visitor.functionDirectory.getMainFunction()->name) {
            localIntBase = 1000;
            localFloatBase = 2000;
        }
        out << funcInfo.name << " " << 
            visitor.semanticCube.getStringFromType(funcInfo.returnType) << " " << 
            funcInfo.startAddress << " " << 
            localIntBase << " " <<
            localFloatBase << " " <<
            funcInfo.numVars << " " << 
            funcInfo.numParams << std::endl;
    }

    // Write quadruples to output file
    out << std::endl << "# Quadruples" << std::endl;
    out << "QUADRUPLES" << std::endl;
    for (size_t i = 0; i < visitor.quadruples.size(); i++) {
        const Quadruple &quad = visitor.quadruples[i];
        std::string arg1 = std::to_string(quad.arg1.address);
        if (quad.op.name == "ERA" || quad.op.name == "GOSUB") {
            arg1 = quad.arg1.name;
        }
        out << i << ": " << quad.op.name << " " << arg1 << " " << quad.arg2.address << " " << quad.result.address << std::endl;
    }

    out.close();
}

int main(int argc, const char* argv[]) {
    // Check for input file argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
    }

    // Open the input file
    std::ifstream stream;
    stream.open(argv[1]);
    if (!stream.is_open()) {
        std::cerr << "Could not open file: " << argv[1] << std::endl;
        return 1;
    }

    // Set up ANTLR input and lexer
    antlr4::ANTLRInputStream input(stream);
    PanicoLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    // Create the parser and parse the input starting from the 'programa' rule
    PanicoParser parser(&tokens);
    antlr4::tree::ParseTree *tree = parser.programa();

    // Print the parse tree (for debugging)
    // std::cout << tree->toStringTree(&parser) << std::endl;

    // Visit the parse tree with our custom visitor
    CustomVisitor visitor;
    visitor.visit(tree);

    // print quadruples
    // std::cout << "Quadruples as names:" << std::endl;
    // printQuadruplesAsNames(visitor.quadruples);
    // std::cout <<  std::endl<< std::endl<<"Quadruples as addresses:" << std::endl;
    // printQuadruplesAsAddresses(visitor.quadruples);

    // generate the output file
    genOutputObjFile(visitor);

    
    return 0;
}

