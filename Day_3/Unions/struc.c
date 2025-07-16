// Structures (struct)

// Structures allow you to combine data items of different kinds under a single name.


#include <stdio.h>
#include <string.h>

// Define a structure for a person
struct Person {
    char name[50];
    int age;
    float height;
};

// Typedef with structure (creates an alias)
typedef struct {
    int x;
    int y;
} Point;

int main() {
    // Declare and initialize a structure variable
    struct Person person1;
    strcpy(person1.name, "John Doe");
    person1.age = 30;
    person1.height = 1.75f;
    
    printf("Person: %s, Age: %d, Height: %.2f\n", 
           person1.name, person1.age, person1.height);
    
    // Initialize at declaration
    struct Person person2 = {"Alice Smith", 25, 1.68f};
    
    // Using typedef structure
    Point p1 = {10, 20};
    printf("Point coordinates: (%d, %d)\n", p1.x, p1.y);
    
    return 0;
}