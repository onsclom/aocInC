#include <stdio.h>
#include <stdlib.h>

void part1() {
    int start = 178146;
    int end = 676461;
    int validCount = 0;

    for (int i = start; i<end; i++) {
        char strRep[10];
        sprintf(strRep, "%i", i);
        int valid = 0;
        for (int c=0; c<5; c++) {
            if (strRep[c] > strRep[c+1]) {
                valid = 0;
                break;
            }
            if (strRep[c] == strRep[c+1]) {
                valid = 1;
            }
        }
        if (valid)
            validCount+=1;
    }

    printf("%i\n", validCount);
}

void part2() {
    int start = 178146;
    int end = 676461;
    int validCount = 0;

    for (int i = start; i<end; i++) {
        char strRep[10];
        sprintf(strRep, "%i", i);
        int valid = 0;
        char lastChar=0;
        int repeatAmount=1;
        for (int c=0; c<6; c++) {
            if (strRep[c] < lastChar) {
                valid = 0;
                repeatAmount = 0;
                break;
            }
            
            if (strRep[c] == lastChar) {
                repeatAmount += 1;
            }
            else {
                if (repeatAmount == 2)
                    valid = 1;
                repeatAmount = 1;
            }    
            
            lastChar = strRep[c];
        }
        if (valid || repeatAmount == 2)
            validCount+=1;
    }

    printf("%i\n", validCount);
}

int main() {
    //part1();
    part2();
}