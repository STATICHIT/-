#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s->base)
        exit(0);

    s->top =s->base;
    s->stackSize = STACK_INIT_SIZE;

}
Push(sqStack *s, ElemType e)
{
    //栈满，追加空间
    if(s->top - s->base >= s->stackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->stackSize+STACKINCREMENT)*)
    }
}
///写不下去了..............
