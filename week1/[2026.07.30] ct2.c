#include <stdio.h>

// This program prints a Fahrenheit to Celsius conversion table for 0, 20, 40, 60, 80, and 100 degrees Fahrenheit.
//floating version

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.1f\t%3.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}
