#include <stdio.h>

void cat(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
}
