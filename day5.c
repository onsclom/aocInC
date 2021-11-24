#include <stdio.h>
#include <stdlib.h>

// Opens txt with fileName, parses into nums array, and puts amount of nums in totalNums
// NOTE: strtok could simplify this function. perhaps I will rewrite with strtok
void initValues(char *fileName, int *nums, int *totalNums)
{
    FILE *inputFile;
    inputFile = fopen(fileName, "r");

    int curNum = 0;
    char curNumString[10];
    char curCharNum = 0;
    char curChar;
    while (curChar = fgetc(inputFile))
    {
        if (curChar == ',' || curChar == EOF)
        {
            curNumString[curCharNum] = '\0';
            nums[curNum] = atoi(curNumString);
            curCharNum = 0;
            curNum += 1;
        }
        else
        {
            curNumString[curCharNum] = curChar;
            curCharNum += 1;
        }
        if (curChar == EOF)
            break;
    }

    *totalNums = curNum;
    fclose(inputFile);
}

void getPaddedInstruction(char *paddedInst, int currentInstruction)
{
    char instructionStr[6];
    sprintf(instructionStr, "%i", currentInstruction);
    char padZeros[6];
    int nullSpot = 0;
    for (int i = 0; i < 6; i++)
    {
        nullSpot = i;
        if (instructionStr[i] == '\0')
            break;
    }
    int i;
    for (i = 0; i < 5 - nullSpot; i++)
    {
        padZeros[i] = '0';
    }
    padZeros[i] = '\0';
    sprintf(paddedInst, "%s%s", padZeros, instructionStr);
}

// interprets nums input following opcode rules
// returns value at nums[0] if success, and -1 if writing or reading outside of nums bounds
int interpretNums(int *nums, int totalNums)
{
    int currentPos = 0;
    int currentInstruction = nums[currentPos];
    //opcode 99 is end program
    while (currentInstruction != 99)
    {
        char paddedInst[14];
        getPaddedInstruction(paddedInst, currentInstruction);
        //printf("INSTRUCTION: %s\n", paddedInst);
        char modeOfP3 = paddedInst[0];
        char modeOfP2 = paddedInst[1];
        char modeOfP1 = paddedInst[2];
        char opcode[3];
        sprintf(opcode, "%s", paddedInst + 3);
        int opcodeInt = atoi(opcode);

        //printf("p1:%c p2:%c p3:%c op:%i\n", modeOfP1, modeOfP2, modeOfP3, currentInstruction);

        //opcode 1 is add
        if (opcodeInt == 1)
        {
            int pos1 = nums[currentPos + 1];
            int pos2 = nums[currentPos + 2];
            int pos3 = nums[currentPos + 3];

            int num1;
            int num2;
            
            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (modeOfP3 == '1') {
                printf("Add cannot support P3!\n");
                exit(0);
            }

            nums[pos3] = num1 + num2;
            currentPos += 4;
        }
        //if not add, then multiply
        else if (opcodeInt == 2)
        {
            int pos1 = nums[currentPos + 1];
            int pos2 = nums[currentPos + 2];
            int pos3 = nums[currentPos + 3];

            int num1;
            int num2;

            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (modeOfP3 == '1') {
                printf("Mult cannot support P3!\n");
                exit(0);
            }

            nums[pos3] = num1 * num2;
            currentPos += 4;
        }
        else if (opcodeInt == 3)
        {
            //input
            int pos1 = nums[currentPos + 1];
            //get input
            int inputNum;
            scanf("%i", &inputNum);

            nums[pos1] = inputNum;
            currentPos += 2;
        }
        else if (opcodeInt == 4)
        {
            //print
            int pos1 = nums[currentPos + 1];
            printf("OUTPUT4: %i\n", nums[pos1]);
            currentPos += 2;
        }
        else if (opcodeInt == 5) {
            //jit
            int pos1 = nums[currentPos+1];
            int pos2 = nums[currentPos+2];

            int num1;
            int num2;

            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (num1 != 0) {
                currentPos = num2;
            }
            else {
                currentPos += 3;
            }
        }
        else if (opcodeInt == 6) {
            //jif
            int pos1 = nums[currentPos+1];
            int pos2 = nums[currentPos+2];

            int num1;
            int num2;

            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (num1 == 0) {
                currentPos = num2;
            }
            else {
                currentPos += 3;
            }
        }
        else if (opcodeInt == 7) {
            //lt
            int pos1 = nums[currentPos+1];
            int pos2 = nums[currentPos+2];
            int pos3 = nums[currentPos+3];

            int num1;
            int num2;

            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (num1 < num2) {
                nums[pos3] = 1;
            }
            else {
                nums[pos3] = 0;
            }
            currentPos += 4;
        }
        else if (opcodeInt == 8) {
            //eq
            int pos1 = nums[currentPos+1];
            int pos2 = nums[currentPos+2];
            int pos3 = nums[currentPos+3];

            int num1;
            int num2;

            if (modeOfP1 == '1')
                num1 = pos1; //immediate mode
            else
                num1 = nums[pos1]; //position mode

            if (modeOfP2 == '1')
                num2 = pos2;
            else
                num2 = nums[pos2];
            
            if (num1 == num2) {
                nums[pos3] = 1;
            }
            else {
                nums[pos3] = 0;
            }
            currentPos += 4;
        }
        else
        {
            printf("UNKNOWN INSTRUCTION: %i\n", opcodeInt);
            exit(0);
        }
        //if 3 then take single int as input and save it to position
        //if 4 output the value of its parameter
        currentInstruction = nums[currentPos];
    }
    return nums[0];
}

void part1()
{
    int nums[1000];
    int totalNums;
    initValues("day5-input.txt", nums, &totalNums);

    // printf("input: ");
    // for (int i = 0; i < totalNums; i++)
    //     printf("%i ", nums[i]);
    // printf("\n");

    interpretNums(nums, totalNums);

    // printf("output: ");
    // for (int i = 0; i < totalNums; i++)
    // {
    //     printf("%i ", nums[i]);
    // }
    // printf("\n");
}

int main()
{
    part1();
}