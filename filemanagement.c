#include <stdio.h>
#include <stdlib.h>

void createFile() {
    FILE *fp;
    char text[100];

    fp = fopen("file.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return;
    }

    printf("Enter text to write: ");
    getchar(); // clear buffer
    fgets(text, sizeof(text), stdin);

    fprintf(fp, "%s", text);
    fclose(fp);

    printf("File created successfully!\n");
}

void readFile() {
    FILE *fp;
    char ch;

    fp = fopen("file.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return;
    }

    printf("\nFile Content:\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}

void appendFile() {
    FILE *fp;
    char text[100];

    fp = fopen("file.txt", "a");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter text to append: ");
    getchar();
    fgets(text, sizeof(text), stdin);

    fprintf(fp, "%s", text);
    fclose(fp);

    printf("Data appended successfully!\n");
}

void copyFile() {
    FILE *src, *dest;
    char ch;

    src = fopen("file.txt", "r");
    dest = fopen("copy.txt", "w");

    if (src == NULL || dest == NULL) {
        printf("Error copying file\n");
        return;
    }

    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied to copy.txt\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE MANAGER =====\n");
        printf("1. Create File\n");
        printf("2. Read File\n");
        printf("3. Append File\n");
        printf("4. Copy File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: readFile(); break;
            case 3: appendFile(); break;
            case 4: copyFile(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}