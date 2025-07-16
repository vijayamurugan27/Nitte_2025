// a C program that showcases various math functions available in the <math.h> library:

#include <stdio.h>
#include <math.h>   // Required for math functions
#include <stdlib.h> // For abs() function

int main() {
    double num = 64.0;
    double angle = 45.0; // in degrees
    double radians = angle * (M_PI / 180.0); // Convert to radians
    
    printf("Math Functions Demonstration\n");
    printf("============================\n\n");
    
    // Basic operations
    printf("Absolute value of -5: %d\n", abs(-5));
    printf("Absolute value of -3.14: %f\n", fabs(-3.14));
    
    // Square root and powers
    printf("Square root of %.2f: %.2f\n", num, sqrt(num));
    printf("Cube root of %.2f: %.2f\n", num, cbrt(num));
    printf("%.2f raised to power 3: %.2f\n", num, pow(num, 3));
    
    // Exponential and logarithmic functions
    printf("Exponential of 1 (e^1): %.2f\n", exp(1));
    printf("Natural log of %.2f: %.2f\n", num, log(num));
    printf("Log base 10 of %.2f: %.2f\n", num, log10(num));
    
    // Trigonometric functions (using radians)
    printf("Sine of %.2f degrees: %.2f\n", angle, sin(radians));
    printf("Cosine of %.2f degrees: %.2f\n", angle, cos(radians));
    printf("Tangent of %.2f degrees: %.2f\n", angle, tan(radians));
    
    // Inverse trigonometric functions
    printf("Arcsine of 0.5: %.2f degrees\n", asin(0.5) * (180.0 / M_PI));
    printf("Arccosine of 0.5: %.2f degrees\n", acos(0.5) * (180.0 / M_PI));
    printf("Arctangent of 1: %.2f degrees\n", atan(1) * (180.0 / M_PI));
    
    // Hyperbolic functions
    printf("Hyperbolic sine of 1: %.2f\n", sinh(1));
    printf("Hyperbolic cosine of 1: %.2f\n", cosh(1));
    printf("Hyperbolic tangent of 1: %.2f\n", tanh(1));
    
    // Rounding functions
    printf("Floor of 3.7: %.2f\n", floor(3.7));
    printf("Ceiling of 3.2: %.2f\n", ceil(3.2));
    printf("Round of 3.5: %.2f\n", round(3.5));
    
    // Other functions
    printf("Modulus of 10.5 divided by 3.2: %.2f\n", fmod(10.5, 3.2));
    
    return 0;
}





// The program will output various mathematical calculations including:

    // Square roots and powers

    // Trigonometric functions (sine, cosine, tangent)

    // Logarithmic and exponential functions

    // Rounding functions

    // Hyperbolic functions

    // Absolute values