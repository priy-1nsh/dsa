#include <stdio.h>

struct Student
{
    int id;
    char name[50];
    float marks[3];
    float avg;
};

int main()
{
    // get the value of the no. of students
    int N;
    scanf("%d", &N);

    struct Student students[N];
    int topperIndex = 0;

    // get the students information
    for (int i = 0; i < N; i++)
    {
        scanf("%d %s", &students[i].id, students[i].name);
        students[i].avg = 0.0;

        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &students[i].marks[j]);
            students[i].avg += students[i].marks[j];
        }
        students[i].avg /= 3.0;

        // finding topper
        if (students[i].avg > students[topperIndex].avg)
        {
            topperIndex = i;
        }
    }

    // printing the merit list
    printf("Merit List:\n");
    for (int i = 0; i < N; i++)
    {
        if (students[i].avg >= 75)
        {
            printf("%d %s (Avg: %.2f)\n", students[i].id, students[i].name, students[i].avg);
        }
    }

    // printing Topper
    prinf("Topper: %s\n", students[topperIndex].name);
}