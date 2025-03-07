#include <iostream>

void stepA() {}

void stepB() {}

void stepC() { throw std::runtime_error("Oops"); }

void doSomething() {
    stepA();
    stepB();
    stepC();
}

int main() {
    try {
        doSomething();
    } catch (std::runtime_error &ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
}