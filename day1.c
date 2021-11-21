#include <stdio.h>
#include <stdlib.h>

void part1()
{
    FILE *inputFile;
    inputFile = fopen("day1-input.txt", "r");

    char curInput[10];
    int sum = 0;
    while (fgets(curInput, 10, inputFile))
    {
        int curNum = atoi(curInput);
        curNum /= 3;
        curNum -= 2;
        sum += curNum;
    }

    fclose(inputFile);
    printf("fuel: %i\n", sum);
}

void part2()
{
    FILE *inputFile;
    inputFile = fopen("day1-input.txt", "r");

    char curInput[10];
    int sum = 0;
    while (fgets(curInput, 10, inputFile))
    {
        int curNum = atoi(curInput);
        curNum /= 3;
        curNum -= 2;

        int fuel = curNum;
        while (fuel > 0)
        {
            sum += fuel;
            fuel /= 3;
            fuel -= 2;
        }
    }
    fclose(inputFile);

    printf("fuel: %i", sum);
}

int main()
{
    part1();
    part2();
}
