#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "generated/PanicoLexer.h"
#include "generated/PanicoParser.h"
#include "generated/PanicoBaseVisitor.h"

// Custom visitor to process parse tree nodes (override methods as needed)
class CustomVisitor : public PanicoBaseVisitor {
public:
    // Override a specific visit method, for example, for the "imprime" rule
    antlrcpp::Any visitImprime(PanicoParser::ImprimeContext *ctx) override {
        std::cout << "Visiting an 'imprime' statement" << std::endl;
        return visitChildren(ctx);
    }
};

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

    // Generate the parse tree to visualize it
    std::ofstream out("parseTree.dot");
    out << antlr4::tree::Trees::toStringTree(tree, &parser, true) << std::endl;
    out.close();


    // Print the parse tree (for debugging)
    std::cout << tree->toStringTree(&parser) << std::endl;

    // Visit the parse tree with our custom visitor
    CustomVisitor visitor;
    visitor.visit(tree);

    return 0;
}

