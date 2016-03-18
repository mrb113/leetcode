#include <stdio.h>
#include <stdlib.h>


bool isUgly(int num)
{
    if (num == 1)
    {
        return true;
    }

    // Check that the number is not negative
    if (num < 1)
    {
        return false;
    }

    // Check if the number is divisible by 2, 3, or 5.
    if (!(num % 2 == 0 || num % 3 == 0 || num % 5 == 0))
    {
        return false;
    }

    // Trial division time
    while (num % 2 == 0)
    {
        num /= 2;
    }
    while (num % 3 == 0)
    {
        num /= 3;
    }
    while (num % 5 == 0)
    {
        num /= 5;
    }
    return num == 1;
}

void main()
{
    int num = 15;
    printf("Is %d ugly? %d\n", num, isUgly(num));
    getchar();
}
