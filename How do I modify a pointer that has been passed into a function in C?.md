# How do I modify a pointer that has been passed into a function in C?

```
#include<stdio.h>
#include<stdlib.h>

typedef struct Bar
{
    // this isn't too important
} Bar;

#define EMPTY_LIST NULL

typedef struct BarList
{
    Bar * val;
    struct  BarList * nextBar;
} BarList;

void barPush(BarList ** list,Bar * bar)
{
    // if there is no move to add, then we are done
    if (bar == NULL) return;
    

    // allocate space for the new node
    BarList * newNode = malloc(sizeof(BarList));

    // assign the right values
    newNode->val = bar;
    newNode->nextBar = *list;

    // and set list to be equal to the new head of the list
    *list = newNode; // This line works, but list only changes inside of this function
}

int main() {
  

BarList * l;
Bar b1,b2;
l = EMPTY_LIST;
barPush(&l,&b1); // b1 and b2 are just Bar's
barPush(&l,&b2);
  return 0;
}

'''
