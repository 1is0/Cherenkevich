#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char key;
    long count;
    struct Node* left, * right;
} Node;

void insert(Node** q, char x)
{
    if (*q == NULL) {
        *q = (Node*)malloc(sizeof(Node));
        (*q)->key = x;
        (*q)->count = 1;
        (*q)->left = (*q)->right = NULL;
    }
    else {
        if ((*q)->key == x)
            ((*q)->count)++;
        else if ((*q)->key > x)
            insert(&((*q)->left), x);
        else
            insert(&((*q)->right), x);
    }
}

void display(Node* q)
{
    if (q != NULL) {
        display(q->left);
        printf("%c : %ld\n", q->key, q->count);
        display(q->right);
    }
}

int isVovel(char c)
{
    int vovel = 0;
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        vovel = 1;
        break;
    default:
        break;
    }
    return vovel;
}

int countOfVowels(Node* q)
{
    int count = 0;
    if (q != NULL) {
        count += countOfVowels(q->left);
        if (isVovel(q->key))
            count += q->count;
        count += countOfVowels(q->right);
    }
    return count;
}

void answer(int vowels, int consonants)
{
    if (vowels > consonants)
        puts("More vowels");
    else if (vowels == consonants)
        puts("Equal vowels and consonants");
    else
        puts("More consonants");
}

int main()
{
    Node* root = NULL;
    char* s = (char*)malloc(sizeof(char*) * 256);
    char* ps;
    int vowels, consonants;
    printf("Enter line: \n");
    scanf("%s", s);
    for (ps = s; *ps; ++ps)
        insert(&root, *ps);
    printf("Tree elements (value : number)\n");
    display(root);
    vowels = countOfVowels(root);
    consonants = (int)strlen(s) - countOfVowels(root);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    answer(vowels, consonants);
    return 0;
}