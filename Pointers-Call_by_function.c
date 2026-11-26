#include <stdio.h>

// Function declaration using pointers (Call by Reference)
void swap(int *a, int *b);

int main() {
    int num1, num2;

    // Input two numbers from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("\nBefore swapping: num1 = %d, num2 = %d\n", num1, num2);

    // Passing memory addresses of num1 and num2
    swap(&num1, &num2);

    printf("After swapping:  num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}

// Function definition to swap values using pointers
void swap(int *a, int *b) {
    int temp;

    temp = *a;  // Store the value at address 'a' in temp
    *a = *b;    // Put the value at address 'b' into address 'a'
    *b = temp;  // Put the value of temp into address 'b'
}
