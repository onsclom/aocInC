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

// interprets nums input following opcode rules
// returns value at nums[0] if success, and -1 if writing or reading outside of nums bounds
int interpretNums(int *nums, int totalNums)
{
    int currentPos = 0;
    int currentInstruction = nums[currentPos];
    //opcode 99 is end program
    while (currentInstruction != 99)
    {
        if (currentPos + 3 >= totalNums || currentPos < 0)
        {
            //out of of bounds error
            return -1;
        }
        //opcode 1 is add
        if (currentInstruction == 1)
        {
            int pos1 = nums[currentPos + 1];
            int pos2 = nums[currentPos + 2];
            int pos3 = nums[currentPos + 3];
            nums[pos3] = nums[pos1] + nums[pos2];
        }
        //if not add, then multiply
        else
        {
            int pos1 = nums[currentPos + 1];
            int pos2 = nums[currentPos + 2];
            int pos3 = nums[currentPos + 3];
            nums[pos3] = nums[pos1] * nums[pos2];
        }
        currentPos += 4;
        currentInstruction = nums[currentPos];
    }
    return nums[0];
}

void part1()
{
    int nums[1000];
    int totalNums;
    initValues("day2-input.txt", nums, &totalNums);

    printf("input: ");
    for (int i = 0; i < totalNums; i++)
        printf("%i ", nums[i]);
    printf("\n");

    interpretNums(nums, totalNums);

    printf("output: ");
    for (int i = 0; i < totalNums; i++)
    {
        printf("%i ", nums[i]);
    }
    printf("\n");
}

void part2()
{
    int nums[1000];
    int totalNums;

    int noun = 0;
    int verb = 0;

    for (int noun = 0; noun < 100; noun++)
    {
        for (int verb = 0; verb < 100; verb++)
        {
            initValues("day2-input.txt", nums, &totalNums);
            nums[1] = noun;
            nums[2] = verb;
            int result = interpretNums(nums, totalNums);
            //printf("n:%i v:%i r:%i\n", noun, verb, result);
            if (result == 19690720)
            {
                printf("answer: %i\n", 100 * noun + verb);
                return;
            }
        }
    }
}

int main()
{
    part1();
    part2();
}