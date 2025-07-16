// Enumerations (enums)

// Enums are used to define named integer constants, making code more readable.

#include <stdio.h>

// Define an enum for days of the week with explicit values
typedef enum {
    MONDAY = 0,
    TUESDAY = 1,
    WEDNESDAY = 2,
    THURSDAY = 3,
    FRIDAY = 4,
    SATURDAY = 5,
    SUNDAY = 6
} Weekday;

// Enum with explicit values
typedef enum {
    OFF = 0,
    ON = 1,
    ERROR = -1
} Status;

int main() {
    Weekday today = WEDNESDAY;
    Status system_status = ON;

    // Check for valid enum values
    if (today >= MONDAY && today <= SUNDAY) {
        printf("Today is day number %d\n", today);  // Output: Today is day number 2
    } else {
        printf("Invalid day of the week\n");
    }

    printf("System status: %d\n", system_status);  // Output: System status: 1
    return 0;
}