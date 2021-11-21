#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile;
    inputFile = fopen("day3-input.txt", "r");

    struct wirePart
    {
        int x;
        int y;
    };
    struct wirePart firstWire[1000];

    char wire1String[10000];
    char wire2String[10000];    

    fgets(wire1String, 100000, inputFile);
    fgets(wire2String, 100000, inputFile);

    // printf("%s\n%s",wire1String,wire2String);

    int curX = 0;
    int curY = 0;

    char * cur;
    cur = strtok(wire1String,",");
    while (cur != NULL) {
        printf("%s",cur); 
        cur = strtok(NULL,",");
    }

    fclose(inputFile);
}