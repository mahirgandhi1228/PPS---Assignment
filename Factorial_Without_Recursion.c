#include <stdio.h>

// Function without recursion (Iterative approach)
unsigned long long factorialIterative(int n) {
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function with recursion
unsigned long long factorialRecursive(int n) {
    // Base case: 0! and 1! are both 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive step: n! = n * (n-1)!
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;

    printf("Enter a positive integer : ");
    scanf("%d", &num);

    // Validate input
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } 
    else {
        // Compute using iterative function
        unsigned long long iterResult = factorialIterative(num);
        
        // Compute using recursive function
        unsigned long long recurResult = factorialRecursive(num);

        printf("\n--- Results for %d! ---\n", num);
        printf("Without Recursion (Iterative): %llu\n", iterResult);
        printf("With Recursion    (Recursive): %llu\n", recurResult);
    }

    return 0;
}