#include <stdio.h>

int main() {
    FILE *file;

    // Open file in write mode
    file = fopen("hello.txt", "w");

    // Check if file opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write to file
    fprintf(file, "Hello World");

    // Close the file
    fclose(file);

    printf("Data written to file successfully.\n");

    return 0;
}