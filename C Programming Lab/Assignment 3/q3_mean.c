#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(int *arr, int n)
{
    int i;

    double res = 0;

    for (i = 0; i < n; i++)
    {
        res += (double)arr[i];
    }

    return res / (double)n;
}

int mode(int *arr, int n)
{

    int modeNum = -1;
    int modeIndex = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                /*Counting each number from next index*/
                count++;
            }
        }

        if (count > modeNum)
        {
            modeNum = count;
            modeIndex = i;
        }
    }

    return arr[modeIndex];
}

double standardDeviation(int *arr, int n)
{
    double m = mean(arr, n);
    double sumdff = 0;
    for (int i = 0; i < n; i++)
    {
        sumdff += (m - (double)arr[i]) * (m - (double)arr[i]);
    }

    double variance = sumdff / n;

    return sqrt(variance);
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 6, 8, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    printf("\nMean: %.2lf", mean(arr, size));

    printf("\nMode: %d", mode(arr, size));

    printf("\nStandard Deviation: %.2lf", standardDeviation(arr, size));
}