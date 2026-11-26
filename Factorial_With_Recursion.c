#include <stdio.h>


unsigned long long factorialRecursive(int n) {
    // Base case: 0! and 1! are both 1 (stops the recursion)
    if (n == 0 || n == 1) {
        return 1;
    }

    // Recursive step: n! = n * (n - 1)!
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        unsigned long long result = factorialRecursive(num);
        printf("Factorial of %d (using recursion) = %llu\n", num, result);
    }

    return 0;
}
