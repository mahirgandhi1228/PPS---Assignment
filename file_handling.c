#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char sourcePath[100], destPath[100];
    char ch;

    // Input file paths from the user
    printf("Enter source file path: ");
    scanf("%s", sourcePath);

    printf("Enter destination file path: ");
    scanf("%s", destPath);

    // Open source file in read mode ("r")
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("\nError: Unable to open source file '%s'.\n", sourcePath);
        exit(EXIT_FAILURE);
    }

    // Open destination file in write mode ("w")
    destFile = fopen(destPath, "w");
    if (destFile == NULL) {
        printf("\nError: Unable to open or create destination file '%s'.\n", destPath);
        fclose(sourceFile); // Close the already opened source file
        exit(EXIT_FAILURE);
    }

    // Copy file contents character by character until End-Of-File (EOF)
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("\nFile copied successfully from '%s' to '%s'.\n", sourcePath, destPath);

    // Close both files to release resources
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
