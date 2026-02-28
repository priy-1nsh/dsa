#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// string compression
int main()
{
    char str[1000];
    scanf("%s", str);
    int n = strlen(str);

    char compressed[1000];

    int i = 0; // index for the string str
    int k = 0; // index for the compressed string

    while (i < n)
    {
        int count = 1;
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        compressed[k] = str[i];
        k++;

        k += sprintf(&compressed[k], "%d", count);

        i++;
    }

    compressed[k] = '\0';

    if (strlen(compressed) < n)
    {
        printf("%s", compressed);
    }
    else
    {
        printf("%s", str);
    }
    return 0;
}