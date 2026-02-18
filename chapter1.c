#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* insertion sort example, pg4 */
void insertion_sort(int s[], int n)
{
    int i, j; /* counters */

    for (i = 1; i < n; i++)
    {
        j = i;
        while ((j > 0) && (s[j] < s[j - 1]))
        {
            swap(&s[j], &s[j - 1]);
            j = j - 1;
        }
    }
}

/* implementation of the nearest neightbour. pseudocode:
    NearestNeighbour(P)
        Pick and visit an initial point P0 from P
        p = p0
        While there are still unvisited points
            i = i + 1
            select pi to be the closest unvisited point to pi-1
            visit pi
        return to p0 from pn-1 */
void nearest_neighbour(int num_list[], int length)
{
    if (length < 2)
        return;

    // print the num list
    printf("Initial num list:");
    for (int num = 0; num < length; num++)
    {
        printf("%d ", num_list[num]);
    }

    int p = num_list[0];
    int i = 0;
    int *sorted_num_list = malloc(length * sizeof(int));
    // we will always start from the first point
    sorted_num_list[0] = num_list[0];

    while (i < length)
    {
        i = i + 1;
        int pn;
        int min_index = 1;
        for (int j = 2; j < length; j++)
        {
            if (p - num_list[j] < p - num_list[min_index])
            {
                min_index = j;
            }
        }
        sorted_num_list[i] = num_list[min_index];
    }

    // print the sorted num list
    printf("\nSorted num  list:");
    for (int num = 0; num < length; num++)
    {
        printf("%d ", sorted_num_list[num]);
    }

    free(sorted_num_list);
}

int main()
{
    int test_array[] = {1, 9, 2, 4, 6, 8, 5, 7};
    int length = sizeof(test_array) / sizeof(test_array[0]);
    nearest_neighbour(test_array, length);
    return 0;
}