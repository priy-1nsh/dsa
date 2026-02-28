#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Student
{
    int marks;
    int delay;
} Student;

int main()
{
    // your code goes here
    // create an array of students
    int N;
    scanf("%d", &N);
    Student arr[N];

    for (int i = 0; i < N; i++)
    {
        // accept user input
        scanf("%d %d", &arr[i].marks, &arr[i].delay);
    }

    // sorting - Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            // comparison
            if ((arr[j].marks < arr[j + 1].marks) || (arr[j].marks == arr[j + 1].marks && arr[j].delay > arr[j + 1].delay))
            {
                // swap
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // printing the array
    for (int i = 0; i < N; i++)
    {
        printf("%d %d", arr[i].marks, arr[i].delay);
    }

    return 0;
}