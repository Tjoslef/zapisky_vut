#ifndef IVS_EXAMPLES_PERSON_H
#define IVS_EXAMPLES_PERSON_H


class Person {
    int age;
    char *name;

public:

    Person(char *name, int age);

    ~Person();

    void print();
};


#endif //IVS_EXAMPLES_PERSON_H
