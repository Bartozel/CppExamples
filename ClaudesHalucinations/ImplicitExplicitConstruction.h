#include <iostream>

// Example 1: WITHOUT explicit keyword
class ImplicitVector {
private:
    size_t capacity;
public:
    // Constructor WITHOUT explicit - allows implicit conversions
    ImplicitVector(size_t cap) : capacity(cap) {
        std::cout << "ImplicitVector created with capacity: " << capacity << std::endl;
    }

    size_t getCapacity() const { return capacity; }
};

// Example 2: WITH explicit keyword
class ExplicitVector {
private:
    size_t capacity;
public:
    // Constructor WITH explicit - prevents implicit conversions
    explicit ExplicitVector(size_t cap) : capacity(cap) {
        std::cout << "ExplicitVector created with capacity: " << capacity << std::endl;
    }

    size_t getCapacity() const { return capacity; }
};

// Helper function to demonstrate implicit conversion issues
void processImplicitVector(const ImplicitVector& vec) {
    std::cout << "Processing vector with capacity: " << vec.getCapacity() << std::endl;
}

void processExplicitVector(const ExplicitVector& vec) {
    std::cout << "Processing vector with capacity: " << vec.getCapacity() << std::endl;
}
