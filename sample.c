#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Check if the filename length exceeds the buffer size limit
    if (strlen(argv[1]) >= BUFSIZE) {
        fprintf(stderr, "Error: Filename is too long.\n");
        return 1;
    }

    // Calculate file size without using system()
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fclose(file);

    printf("File size: %ld bytes\n", fileSize);
    return 0;
}
