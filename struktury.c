//==================================================
// Struktury w C
//==================================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int x;
    int y;
} vertex;

struct element
{
    vertex var;
    struct element* next;
};

vertex new_vertex(int x,int y)
{
    vertex temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

void vprint(vertex arg)
{
    printf("(%i,%i)",arg.x,arg.y);
}

struct element* prepare()
{
    struct element* ptr = malloc(sizeof(struct element));
    ptr->next = NULL;
    return ptr;
};

void push(struct element* list, vertex arg)
{
    struct element* ptr = list;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = malloc(sizeof(struct element));
    ptr = ptr->next;
    ptr->var = arg;
    ptr->next = NULL;
}

void insert(struct element* list, int n, vertex arg)
{
    struct element* ptr = list;
    struct element* temp = malloc(sizeof(struct element));
    for(int k=0; k<=n; k++)
        ptr = ptr->next;
    temp->var = arg;
    temp->next = ptr->next;
    ptr->next = temp;
}

void show(struct element* list)
{
    int help = 0;
    struct element* ptr = list;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
        if(help) printf(", ");
        help = 1;
        vprint(ptr->var);
    }
    printf("\n");
}

vertex pop(struct element* list)
{
    vertex temp;
    struct element* ptr = list;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    temp = ptr->next->var;
    free(ptr->next);
    ptr->next = NULL;
    return temp;
}

vertex peek(struct element* list)
{
    vertex temp;
    struct element* ptr = list;
    while(ptr->next->next != NULL)
        ptr = ptr->next;
    temp = ptr->next->var;
    return temp;
}

void fill(struct element* list,int n)
{
    vertex v;
    for(int k=0; k<n; k++)
    {
        v = new_vertex(rand()%20+1,rand()%20+1);
        push(list,v);
    }
}

int main()
{
    srand(time(NULL));
    struct element* list = prepare();
    fill(list,20);
    show(list);
    return 0;
}
