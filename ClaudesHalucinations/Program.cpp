#include <iostream>

#include "ImplicitExplicitConstruction.h"

int main()
{
    std::cout << "=== WITHOUT explicit keyword ===" << std::endl;

    // Direct construction - both work the same
    ImplicitVector iv1(10);

    // Copy initialization - THIS WORKS (but might be unintended!)
    ImplicitVector iv2 = 20;  // Implicitly converts int 20 to ImplicitVector

    // Function call with implicit conversion - THIS WORKS (dangerous!)
    processImplicitVector(30);  // int 30 is implicitly converted to ImplicitVector

    // Assignment (if assignment operator allows it)
    ImplicitVector iv3(5);
    // iv3 = 40;  // This would also work if we had assignment operator

    std::cout << "\n=== WITH explicit keyword ===" << std::endl;

    // Direct construction - works fine
    ExplicitVector ev1(10);

    // Copy initialization - COMPILATION ERROR!
    // ExplicitVector ev2 = 20;  // ERROR: cannot convert int to ExplicitVector

    // Must use direct initialization instead
    ExplicitVector ev2(20);  // This works

    // Function call with implicit conversion - COMPILATION ERROR!
    // processExplicitVector(30);  // ERROR: cannot convert int to ExplicitVector

    // Must explicitly construct the object
    processExplicitVector(ExplicitVector(30));  // This works

    // Or create a named object
    ExplicitVector ev3(30);
    processExplicitVector(ev3);

    std::cout << "\n=== Why explicit matters ===" << std::endl;

    // Example of potential bug with implicit conversion
    ImplicitVector bug_prone = 3.14;  // float converted to size_t (becomes 3)
    std::cout << "Bug-prone capacity: " << bug_prone.getCapacity() << std::endl;

    // With explicit, this would be a compilation error:
    // ExplicitVector safe = 3.14;  // ERROR: won't compile

    return 0;
}