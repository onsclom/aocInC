#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

#define GRID_SIZE 50000

void part1() {
    FILE *inputFile;
    inputFile = fopen("day3-input.txt", "r");

    char wire1String[10000];
    char wire2String[10000];    

    fgets(wire1String, 100000, inputFile);
    fgets(wire2String, 100000, inputFile);

    int ** grid;
    grid = malloc(sizeof(int*)*GRID_SIZE);
    for (int i=0; i<GRID_SIZE; i++) {
        grid[i] = (int*) calloc(GRID_SIZE, sizeof(int));
    }

    int originPoint = GRID_SIZE/2;
    int curX = originPoint;
    int curY = originPoint;

    char * cur;
    cur = strtok(wire1String,",");
    while (cur != NULL) {
        char dirLetter = cur[0];
        int amount = atoi(cur+1);  

        for (int i=0; i<amount; i++) {
            if (dirLetter=='R') curX+=1;
            else if (dirLetter=='L') curX-=1;
            else if (dirLetter=='U') curY-=1;
            else if (dirLetter=='D') curY+=1;
            grid[curX][curY]=1;
        }

        cur = strtok(NULL,",");
    }

    curX = GRID_SIZE/2;
    curY = GRID_SIZE/2;
    cur = strtok(wire2String,",");
    int minDist = -1;
    while (cur != NULL) {
        char dirLetter = cur[0];
        int amount = atoi(cur+1);   
        for (int i=0; i<amount; i++) {
            if (dirLetter=='R') {
                curX+=1;
            }
            else if (dirLetter=='L') {
                curX-=1;
            }
            else if (dirLetter=='U') {
                curY-=1;
            }
            else if (dirLetter=='D') {
                curY+=1;
            }
            
            
            if (grid[curX][curY]==1) {
                int manhattanDist = abs(originPoint-curX)+abs(originPoint-curY);
                if (minDist==-1 || manhattanDist<minDist) {
                    minDist = manhattanDist;
                }
            } 
        }

        cur = strtok(NULL,",");
    }

    printf("min manhattan: %i\n", minDist);
    
    fclose(inputFile);
}

void part2() {
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

    int ** grid;
    grid = malloc(sizeof(int*)*GRID_SIZE);
    for (int i=0; i<GRID_SIZE; i++) {
        grid[i] = malloc(sizeof(int*)*GRID_SIZE);
    }

    int originPoint = GRID_SIZE/2;
    int curX = originPoint;
    int curY = originPoint;

    char * cur;
    cur = strtok(wire1String,",");
    int dist = 0;
    while (cur != NULL) {
        char dirLetter = cur[0];
        int amount = atoi(cur+1);  

        for (int i=0; i<amount; i++) {
            if (dirLetter=='R') curX+=1;
            else if (dirLetter=='L') curX-=1;
            else if (dirLetter=='U') curY-=1;
            else if (dirLetter=='D') curY+=1;
            dist+=1;
            grid[curX][curY]=dist;
        }

        cur = strtok(NULL,",");
    }

    curX = GRID_SIZE/2;
    curY = GRID_SIZE/2;
    cur = strtok(wire2String,",");
    int minDist = -1;
    dist = 0;
    while (cur != NULL) {
        char dirLetter = cur[0];
        int amount = atoi(cur+1);       
        for (int i=0; i<amount; i++) {
            if (dirLetter=='R') {
                curX+=1;
            }
            else if (dirLetter=='L') {
                curX-=1;
            }
            else if (dirLetter=='U') {
                curY-=1;
            }
            else if (dirLetter=='D') {
                curY+=1;
            }
            
            dist+=1;
            if (grid[curX][curY]>0) {
                int manhattanDist = grid[curX][curY]+dist;
                if (minDist==-1 || manhattanDist<minDist) {
                    minDist = manhattanDist;
                }
            } 
        }

        cur = strtok(NULL,",");
    }

    printf("min manhattan: %i\n", minDist);
    
    fclose(inputFile);
}

int main() {
    part1();
    //part2();
}