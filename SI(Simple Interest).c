#include <stdio.h>
int main() {
float principleAmount, n;
float rate=9.5;
printf("Enter your principle amount : ");
scanf("%f",&principleAmount);
printf("Enter how many years you want to invest : ");
scanf("%f", &n);
float Simple_Interest = (principleAmount*rate*n)/100;
float AM = (Simple_Interest+principleAmount);
printf("Your simple interest amounts to  ₹%f \n", Simple_Interest);
printf("Your final amount is  ₹%f", AM);
}