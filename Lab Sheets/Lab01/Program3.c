#include <stdio.h>
#include <stddef.h>
#include <string.h>

int wordCount(char *string)
{
    int i = 0;
    int count = 0;
    while (*(string + i) != '\0')
    {
        if (*(string + i) == ' ')
        {
            count++;
        }
        i++;
    }
    count++;
    return count;
}

// int vowelCount(char* string) {
//     int i = 0, count = 0;
//     char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
//     while (*(string + i) != '\0') {
//         if (strchr(vowels, *(string + i)) != NULL) count++;
//         i++;
//     }
//     return count;
// }

// another approach for the vowelCount
int vowelCount(char *string)
{
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; string[i] != '\0'; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (string[i] == vowels[j])
            {
                count++;
            }
        }
    }
    return count;
}

void reverseString(char *string)
{
    int left = 0;
    int right = strlen(string) - 1;
    while (left < right)
    {
        char temp = string[left];
        string[left] = string[right];
        string[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    char string[50] = "This is a String";
    printf("Words: %d\n", wordCount(string));
    printf("Vowels: %d\n", vowelCount(string));
    reverseString(string);
    printf("Reversed: %s", string);

    return 0;
}