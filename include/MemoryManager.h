// MemoryManager.h

#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "Types.h"
#include <unordered_map>
#include <string>

class MemoryManager {
private:
    // Base addresses and current pointers for each segment
    // Global memory
    int globalIntBase = 1000, globalIntPointer = 1000;
    int globalFloatBase = 2000, globalFloatPointer = 2000;
    // Local memory
    int localIntBase = 3000, localIntPointer = 3000;
    int localFloatBase = 4000, localFloatPointer = 4000;
    // Temporary memory
    int tempIntBase = 5000, tempIntPointer = 5000;
    int tempFloatBase = 6000, tempFloatPointer = 6000;
    // Constant memory
    int constIntBase = 7000, constIntPointer = 7000;
    int constFloatBase = 8000, constFloatPointer = 8000;
    int constStringBase = 9000, constStringPointer = 9000;

    // Maps to track constants for deduplication
    std::unordered_map<int, int> intConstants;
    std::unordered_map<float, int> floatConstants;
    std::unordered_map<std::string, int> stringConstants;

public:
    // Allocate memory for global integers
    int allocateGlobalInt();

    // Allocate memory for global floats
    int allocateGlobalFloat();

    // Allocate memory for local integers
    int allocateLocalInt();

    // Allocate memory for local floats
    int allocateLocalFloat();

    // Allocate memory for temporary integers
    int allocateTempInt();

    // Allocate memory for temporary floats
    int allocateTempFloat();

    // Get or create a constant integer or float address
    int getOrCreateConstant(Type type, std::string value);

    // Get or create a constant string address
    int getOrCreateConstString(const std::string& value);

    // Reset locals for a new function scope
    void resetLocals();

    // Reset temporaries for a new function or expression
    void resetTemporaries();
};


#endif // MEMORY_MANAGER_H