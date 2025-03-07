#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Person;

Person initPerson(char *name, int age) {
    Person person;
    person.name = name;
    person.age = age;
    return person;
}

void destroyPerson(Person *p) {
//    free(p->name);
    p->name = NULL;
}


void printPerson(Person *p) {
    printf("Hello, I am %s \n", p->name);
}

int main() {
    Person person = initPerson("Martin", 21);
    printPerson(&person);
    destroyPerson(&person);
}