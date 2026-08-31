#include <stdio.h>

// This program prints a Fahrenheit to Celsius conversion table for 0, 20, 40, 60, 80, and 100 degrees Fahrenheit.
int main() {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5 * (fahr - 32)) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}
