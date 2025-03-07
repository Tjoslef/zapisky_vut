#include <iostream>

#include "Person.h"


Person::Person(char *name, int age) {
    this->name = name;
    this->age = age;
}


Person::~Person() {
//    free(this->name);
        std::cout << "Destructor" << std::endl;
    this->name = nullptr;
}

void Person::print() {
    std::cout << "Hello, I am " << this->name << std::endl;
}
