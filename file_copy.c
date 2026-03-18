#include <stdio.h>

int main() {
    FILE *input, *output;
    char ch;

    // Open input file in read mode
    input = fopen("input.txt", "r");

    // Check if input file exists
    if (input == NULL) {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    // Open output file in write mode
    output = fopen("output.txt", "w");

    // Check if output file opened
    if (output == NULL) {
        printf("Error: Cannot open output.txt\n");
        fclose(input);
        return 1;
    }

    // Copy content character by character
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    printf("File copied successfully.\n");

    return 0;
}