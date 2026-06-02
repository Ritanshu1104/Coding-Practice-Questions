#include <stdio.h>

int main() {
    int age;
    char name[50];

    printf("Enter your age: ");
    scanf("%d", &age); // Reads an integer and stores it in 'age'

    printf("Enter your name: ");
    scanf("%s", name); // Reads a string and stores it in 'name' (no & for array names)

    printf("You are %d years old and your name is %s.\n", age, name);

    return 0;
}