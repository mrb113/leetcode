#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INDEX_ARRAY_SIZE 2

int compare(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

int*
michelle(int *nums, int nums_size, int target)
{
    // If the array were sorted, I could do some awesome pointer stuff on the arrays and do it in one pass with O(1) extra space.
    // I could sort the array and do it, but then I need O(nlogn) time and O(n) extra space. Hm. LET'S DO IT.
    int left = 0;
    int right = nums_size - 1;
    int first;
    int second;

    int* indices = (int*)malloc(sizeof(int) * INDEX_ARRAY_SIZE);
    if (!indices)
    {
        return NULL;
    }

    int* tempArray = (int*)malloc(sizeof(int) * nums_size);
    if (!tempArray)
    {
        return NULL;
    }

    memcpy(tempArray, nums, sizeof(int) * nums_size);

    qsort(tempArray, nums_size, sizeof(int), compare);

    for (;;)
    {
        if (target - (tempArray[right] + tempArray[left]) > 0)
        {
            left++;
        }
        else if (target - (tempArray[right] + tempArray[left]) < 0)
        {
            right--;
        }
        else
        {
            first = tempArray[left];
            second = tempArray[right];
            break;
        }
    }

    int firstFound = 0;
    int secondFound = 0;
    for (int i = 0; i < nums_size; i++)
    {
        // Find left and right in the original array
        // I can probably optimize this so it stops as soon as it finds it.
        if (!firstFound && nums[i] == first)
        {
            firstFound = 1;
            indices[0] = i;
        }
        else if (!secondFound && nums[i] == second)
        {
            secondFound = 1;
            indices[1] = i;
        }
    }

    free(tempArray);
    return indices;
}

int*
iterative(int *nums, int nums_size, int target)
{
    int *indices = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < nums_size; i++)
    {
        for (int j = nums_size - 1; j > i; j--)
        {
            if (nums[i] + nums[j] == target)
            {
                indices[0] = i;
                indices[1] = j;
                return indices;
            }
        }
    }
    return NULL;
}

void main()
{
    int nums[8] = { 2,1,9,4,4,56,90,3 };
    int* indices = michelle(nums, 8, 8);

    printf("Indices = %d, %d\n", indices[0], indices[1]);
    getchar();
}