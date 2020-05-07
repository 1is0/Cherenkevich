#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    system("chcp 1251");
    system("cls");
    char str[256];
    int i = 0;
    printf("Введите текст\n");
    fgets(str, 255, stdin);
    int n = 0, k = 0, z = 0;
    while (str[i] != '\0')
    {
        z++;
        switch (str[i])
        {
        case ',':

        case ':':

        case ';':

        case '!':

        case '?':

        case '.': if ((str[i + 1] != ' ') && (str[i + 1] != '\0')) k++; break;

        default: break;
        }

        i++;
    }

    n = z + k;
    char* str2 = NULL;
    str2 = (char*)malloc(n * sizeof(char));


    k = 0;
    for (i = 0; i < z - 1; i++)
    {
        switch (str[i])
        {
        case ',':

        case ':':

        case ';':
        {
            str2[k] = str[i];
            k++;
            if (str[i + 1] != ' ')
            {
                str2[k] = ' ';
                k++;
            }
            break;
        }

        case '!':

        case '?':

        case '.':
        {
            str2[k] = str[i];
            k++;
            if (str[i + 1] != ' ')
            {
                str2[k] = ' ';
                k++;
                if (('A' <= str[i + 1]) && (str[i + 1] <= 'Z') || ('А' <= str[i + 1]) && (str[i + 1] <= 'Я'))
                    break;
                else
                {
                    if (str[i + 1] != '\n')
                    {
                        str2[k] = (str[i + 1] - 32);
                        if (i + 1 < z)
                            i = i + 1;
                        k++;
                    }
                }
            }
            else
            {
                str2[k] = str[i + 1];
                k++;
                if (('A' <= str[i + 2]) && (str[i + 2] <= 'Z') || ('А' <= str[i + 2]) && (str[i + 2] <= 'Я'))
                    break;
                else
                {
                    if (str[i + 2] != '\n')
                    {
                        str2[k] = (str[i + 2] - 32);
                        if (i + 2 < z)
                            i = i + 2;
                        k++;
                    }
                }
            }
            break;
        }

        default: str2[k] = str[i]; k++; break;
        }
    }
    str2[n - 1] = '\0';
    printf("Исправленный текст:\n");
    puts(str2);
    free(str2);

    return 0;
}