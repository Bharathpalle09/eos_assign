#include<stdio.h>
#include"circle.h"
#include"rect.h"

int main()
{
int cir=area(10);
printf("circle : %d",cir);
int rectArea=rect(10,20);
printf("rect :%d",rectArea);
int sqtArea=sqr(20);
printf("sqr :%d",sqtArea);
}

