#include <stdio.h>
int main()
{
int number;
int factorial;
factorial=1;
printf("Enter a number : ");
scanf("%d",&number);
for(int i=number; i > 0; i--)
{
factorial = factorial * i;
}
printf("Factorial is %d", factorial);
}