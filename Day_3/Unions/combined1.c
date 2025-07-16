#include <stdio.h>
#include <string.h>

// Enum for vehicle type
enum VehicleType { CAR, TRUCK, MOTORCYCLE };

// Structure for vehicle details
struct VehicleDetails {
    char make[50];
    char model[50];
    int year;
};

// Union for specific vehicle data
union SpecificData {
    int seats;          // for cars
    float cargo_capacity; // for trucks
    int engine_cc;      // for motorcycles
};

// Combined structure using enum, struct, and union
struct Vehicle {
    enum VehicleType type;
    struct VehicleDetails details;
    union SpecificData specific;
};

void print_vehicle(struct Vehicle v) {
    printf("Make: %s\n", v.details.make);
    printf("Model: %s\n", v.details.model);
    printf("Year: %d\n", v.details.year);
    
    switch(v.type) {
        case CAR:
            printf("Type: Car\n");
            printf("Seats: %d\n", v.specific.seats);
            break;
        case TRUCK:
            printf("Type: Truck\n");
            printf("Cargo Capacity: %.1f tons\n", v.specific.cargo_capacity);
            break;
        case MOTORCYCLE:
            printf("Type: Motorcycle\n");
            printf("Engine: %d cc\n", v.specific.engine_cc);
            break;
    }
    printf("\n");
}

int main() {
    struct Vehicle car = {
        .type = CAR,
        .details = {"Toyota", "Camry", 2020},
        .specific.seats = 5
    };
    
    struct Vehicle truck = {
        .type = TRUCK,
        .details = {"Ford", "F-150", 2019},
        .specific.cargo_capacity = 2.5
    };
    
    struct Vehicle bike = {
        .type = MOTORCYCLE,
        .details = {"Harley-Davidson", "Sportster", 2021},
        .specific.engine_cc = 1200
    };
    
    print_vehicle(car);
    print_vehicle(truck);
    print_vehicle(bike);
    
    return 0;
}



// Key Differences:

//     Structures vs Unions:

//         Structures allocate separate memory for all members

//         Unions share the same memory space for all members (size = largest member)

//     Enums:

//         Provide a way to create named constants

//         Improve code readability

//         Underlying type is integer

//     Memory Usage:

//         Structures: Memory = sum of all members (plus possible padding)

//         Unions: Memory = size of largest member

//         Enums: No memory allocated until you create variables of the enum type