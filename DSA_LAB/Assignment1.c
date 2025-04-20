#include <stdio.h>
#include <stdlib.h>

void createlist(int *, int);
void displaylist(int *, int);
void reverselist(int *, int);
void indexofelements(int *, int, int);
void elementatindex(int *, int, int);
void insertelement(int *, int, int);
void deleteelement(int *, int, int);
int *merge(int *, int, int *, int, int);
void split(int *, int);
void sort(int *, int);

int main()
{
    int *arr = NULL, *newarr = NULL, size = 0, el, pos, indx, newarrsize;
    char ch;
    do
    {
        printf("\na) Create\nb) Display the entire list\nc) Count (total number of elements in the list)\nd) Reverse the list (reversed list should be stored in the same array)\ne) Index of a given element (all indices if there are duplicate entries)\nf) Indexed element\ng) Insert\nh) Delete\ni) Merge\nj) Split\nk) Sort\n0) Exit\n\n");

        printf("Enter Option: ");
        scanf(" %c", &ch);

        if (ch == 'a')
        {

            if (arr != NULL)
            {
                free(arr);
            }

            printf("Enter Size of the list: ");
            scanf("%d", &size);
            arr = (int *)malloc(size * sizeof(int));
            if (arr == NULL)
            {
                printf("Allocation Failed");
                exit(0);
            }
            createlist(arr, size);
        }
        else
        {
            if (arr == NULL)
            {
                printf("\nCreate a List first\n");
                continue;
            }
            switch (ch)
            {
            case 'b':
                displaylist(arr, size);
                break;
            case 'c':
                printf("Total number of elements in the list are: %d\n", size);
                break;
            case 'd':
                reverselist(arr, size);
                break;
            case 'e':
                printf("Enter Element to find: ");
                scanf("%d", &el);
                indexofelements(arr, size, el);
                break;
            case 'f':
                printf("Enter index to see element(Should be between 0 to %d): ", size - 1);
                scanf("%d", &indx);
                elementatindex(arr, size, indx);
                break;
            case 'g':
                printf("Enter Position to insert the element in: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > size)
                {
                    printf("\nInvalid Position! Try Again.\n");
                    break;
                }
                arr = (int *)realloc(arr, (size + 1) * sizeof(int));
                if (arr == NULL)
                {
                    printf("Memory Reallocation Failed");
                    exit(0);
                }
                insertelement(arr, ++size, pos);
                break;
            case 'h':
                printf("Enter Position to delete the element from: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= size)
                {
                    printf("\nInvalid Position! Try Again.\n");
                    break;
                }
                deleteelement(arr, size, pos);
                arr = (int *)realloc(arr, (size - 1) * sizeof(int));
                if (arr == NULL)
                {
                    printf("Memory Reallocation Failed");
                    exit(0);
                }
                size--;
                break;
            case 'i':
                printf("Enter Size of the new list to merge: ");
                scanf("%d", &newarrsize);
                newarr = (int *)malloc(newarrsize * sizeof(int));
                if (newarr == NULL)
                {
                    printf("Memory Allocation Failed");
                    exit(0);
                }
                createlist(newarr, newarrsize);
                printf("And Merged\n");
                int *temparr = merge(arr, size, newarr, newarrsize, 0);
                free(arr);
                free(newarr);
                arr = temparr;
                size += newarrsize;
                break;
            case 'j':
                split(arr, size);
                break;
            case 'k':
                sort(arr, size);
                printf("\nArray sorted successfully\n");
                break;
            case '0':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
            }
        }
    } while (ch != '0');

    if (arr != NULL)
    {
        free(arr);
    }

    return 0;
}

void createlist(int *arr, int n)
{
    int i;
    printf("Enter Elements of the List: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nList Created Successfully\n");
}

void displaylist(int *arr, int n)
{
    int i;
    printf("Elements in the List are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverselist(int *arr, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    printf("\nList Reversed Successfully\n");
}

void indexofelements(int *arr, int n, int element)
{
    int i, flag = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            if (flag == 0)
                printf("\nElement is present at indices: \n");
            printf("%d ", i);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("\nElement Not Found\n");
    else
        printf("\n");
}

void elementatindex(int *arr, int n, int index)
{
    index < n &&index >= 0 ? printf("\nElement at index %d is: %d\n", index, arr[index]) : printf("\nIndex Cannot be outside range\n");
}

void insertelement(int *arr, int n, int position)
{
    int i, element;
    printf("Enter Element to insert: ");
    scanf("%d", &element);
    for (i = n - 1; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    printf("\nElement inserted\n");
}

void deleteelement(int *arr, int n, int position)
{
    int i;
    for (i = position; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    printf("\nElement deleted\n");
}

int *merge(int *arr1, int n1, int *arr2, int n2, int sort)
{
    int *result = (int *)malloc((n1 + n2) * sizeof(int));
    if (result == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    if (sort)
    {
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                result[k++] = arr1[i++];
            }
            else
            {
                result[k++] = arr2[j++];
            }
        }
        while (i < n1)
        {
            result[k++] = arr1[i++];
        }
        while (j < n2)
        {
            result[k++] = arr2[j++];
        }
    }
    else
    {
        int k = 0;
        for (int i = 0; i < n1; i++)
        {
            result[k++] = arr1[i];
        }
        for (int j = 0; j < n2; j++)
        {
            result[k++] = arr2[j];
        }
    }

    return result;
}

void split(int *arr, int n)
{
    printf("Enter number of splits: ");
    int k;
    scanf("%d", &k);

    if (k <= 0)
    {
        printf("Invalid input: number of splits must be positive.\n");
        return;
    }
    if (k > n)
    {
        printf("Invalid input: number of splits cannot exceed array size.\n");
        return;
    }

    int base_size = n / k;
    int extra_elements = n % k;

    int i = 0, group = 1;
    while (i < n)
    {
        int group_size = base_size + (group <= extra_elements ? 1 : 0);

        printf("Arr %d: ", group++);

        for (int j = 0; j < group_size && i < n; j++, i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }
}

void sort(int *arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = n / 2;

    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((n - mid) * sizeof(int));
    if (left == NULL || right == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    sort(left, mid);
    sort(right, n - mid);

    int *temp = merge(left, mid, right, n - mid, 1);
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    free(temp);
    free(left);
    free(right);
}