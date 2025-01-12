#include <stdio.h>
#include <stdlib.h>

struct Student
{
    char name[100];
    int roll;
    int marks[5];
    int avg, total;
};

void merge(struct Student *S, int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct Student leftArr[n1], rightArr[n2];

    for (i = 0; i < n1; i++)
        leftArr[i].total = S[left + i].total;
    for (j = 0; j < n2; j++)
        rightArr[j].total = S[mid + 1 + j].total;

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i].total <= rightArr[j].total)
        {
            S[k] = leftArr[i];
            i++;
        }
        else
        {
            S[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        S[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        S[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(struct Student *S, int left, int right)
{
    if (left < right)
    {

        int mid = left + (right - left) / 2;

        mergeSort(S, left, mid);
        mergeSort(S, mid + 1, right);

        merge(S, left, mid, right);
    }
}

void takeStudentsDataInput(struct Student *S, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("Enter Student %d name: ", i + 1);
        scanf("%s", S[i].name);

        printf("Enter Student %d roll: ", i + 1);
        scanf("%d", &S[i].roll);
        printf("Enter Student %d marks:\n\n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("Enter marks for subject s[%d]: ", j + 1);
            scanf("%d", &S[i].marks[j]);
        }
    }
}

void findAverage(struct Student *S, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        S[i].avg = 0;
        for (int j = 0; j < 5; j++)
        {
            S[i].avg += S[i].marks[j];
        }
        S[i].avg /= 5;
    }

    for (int i = 0; i < noOfStudents; i++)
    {
        printf("Average of Student S%d is: %d\n", i + 1, S[i].avg);
    }
}

void totalMarks(struct Student *S, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        S[i].total = 0;
        for (int j = 0; j < 5; j++)
        {
            S[i].total += S[i].marks[j];
        }
    }

    for (int i = 0; i < noOfStudents; i++)
    {
        printf("Total marks of Student S%d is: %d\n", i + 1, S[i].total);
    }
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student *S = malloc(n * sizeof(struct Student));

    takeStudentsDataInput(S, n);

    findAverage(S, n);
    totalMarks(S, n);

    printf("Sorted order of students based on Total: \n");
    mergeSort(S, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("Student %d\n\nName: %s\nRoll: %d\nAverage: %d\nTotal: %d\n\n",
               i + 1, S[i].name, S[i].roll, S[i].avg, S[i].total);
    }

    free(S);
}
