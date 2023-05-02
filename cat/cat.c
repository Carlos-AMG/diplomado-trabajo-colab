#include <stdio.h>
#include "cat.h"

int cat(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, 1024, fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
