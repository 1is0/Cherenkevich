#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("chcp 1251");
    system("cls");
    int n = 0, size = 0, i = 0, right = 0, left = 0;
    FILE* fp;

    fp = fopen("input.txt", "r+");
    if (!fp) exit(1);

    if (!fp) perror("Error opening file");
    else
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
    }
    fseek(fp, 0, SEEK_SET);
    char* str = NULL;
    str = (char*)malloc(size+1 * sizeof(char));

    fgets(str, size+1, fp);
    fclose(fp);
    for (i = 0; i <= size; i++)
    {
        switch (str[i])
        {
        case ')':
        {
            right++;
            if (right > left)
            {
                printf("Баланс скобок не соблюдён");
                return 0;
            }
            break;
        }

        case'(':
            left++; break;


        default:break;
        }
    }

    if (left == right)
    {
        for (i = 0; i <= size; i++)
        {
            switch (str[i])
            {
            case'(':
            {
                n++;
                if (n == 2)
                    str[i] = '[';
                else if (n >= 3)
                    str[i] = '{';
                break;
            }
            case ')':
            {
                if (n == 2)
                    str[i] = ']';
                else if (n >= 3)
                    str[i] = '}';
                n--;
                break;
            }
            
            default:break;
            }
        }

    }
    else
    {
        printf("Баланс скобок не соблюдён");
        return 0;
    }
    fopen("input.txt", "w");
    fputs(str, fp);
    fclose(fp);
    return 0;
}