#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 15
char l[10];
struct symb
{
    int add;
    char label[10];
} sy[max];
void search();
void main()
{
    int a[max], num, key, i, ch;
    char ans;
    int create(int);
    void lprob(int[], int, int);
    void display(int[]);
    for (i = 0; i < max; i++)
        a[i] = 0;
    do
    {
        printf("\nSymbol Menu \n\t1.create a symbol table \n\t2.search in the symbol table\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            do
            {
                printf("\nEnter the address:");
                scanf("%d", &num);
                key = create(num);
                printf("enter The label:");
                scanf("%s", l);
                lprob(a, key, num);
                printf("\nContinue(y/n)?");
                scanf("%c",&ans);
                scanf("%c",&ans);
            } while (ans == 'y');
            display(a);
            break;
        case 2:
            search();
            break;
        }
    } while (ch <= 2);
}

int create(int num)
{
    return num % max;
}

void lprob(int a[max], int key, int num)
{
    int flag, i, count = 0;
    void display(int a[]);
    flag = 0;
    if (a[key] == 0)
    {
        a[key] = num;
        sy[key].add = num;
        strcpy(sy[key].label, l);
    }
    else
    {
        i = 0;
        while (i < max)
        {
            if (a[i] != 0)
                count++;
            i++;
        }
        if (count == max)
        {
            printf("\nHash table is full");
            display(a);
            exit(1);
        }
        for (i = key + 1; i < max; i++)
            if (a[i] == 0)
            {
                a[i] = num;
                flag = 1;
                sy[key].add = num;
                strcpy(sy[key].label, l);
                break;
            }
        for (i = 0; i < key && flag == 0; i++)
            if (a[i] == 0)
            {
                a[i] = num;
                flag = 1;
                sy[key].add = num;
                strcpy(sy[key].label, l);
                break;
            }
    }
}
void display(int a[max])
{
    FILE *fp;
    int i;
    fp = fopen("symbol.txt", "w");
    printf("\nThe Symbol Table is");
    printf("\nhashvalues address label");
    for (i = 0; i < max; i++)
    {
        printf("\n%d\t %d\t %s", i, sy[i].add, sy[i].label);
        fprintf(fp, "\n%d %d %s", i, sy[i].add, sy[i].label);
    }
    fclose(fp);
}

void search()
{
    FILE *fp1;
    char la[10];
    int set = 0, s;
    int j, i;
    printf("enter the label: ");
    scanf("%s", la);
    fp1 = fopen("symbol.txt", "r");
    for (i = 0; i < max; i++)
    {
        fscanf(fp1, "%d%d", &j, &sy[i].add);
        if (sy[i].add != 0)
            fscanf(fp1, "%s", sy[i].label);
    }
    for (i = 0; i < max; i++)
    {
        if (sy[i].add != 0)
        {
            if (strcmp(sy[i].label, la) == 0)
            {
                set = 1;
                s = sy[i].add;
            }
        }
    }
    if (set == 1)
        printf("\nThe label --%s-- is present in the symbol table at address:%d\n", la, s);
    else
        printf("\nThe label is not present in the symbol table\n");
}
/*
//hash data

struct DataItem
{
    int data;
    int key;
};
int hashCode(int key)
{
    return key % SIZE;
}
struct DataItem *search(int key)
{
    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}
void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    hashArray[hashIndex] = item;
}
struct DataItem *delete (struct DataItem *item)
{
    int key = item->key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key)
        {
            struct DataItem *temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}
*/
