#include<stdio.h>
int main()
{
int a,b,c,c1,c2,c3;
char istriangle;
do
{
printf("\nEnter 3 sides of triangle= ");
scanf("%d%d%d",&a,&b,&c);
printf("a=%d,\t b=%d,\t c=%d\t",a,b,c);
c1=(a>=1 && a<=10);
c2=(b>=1 && b<=10);
c3=(c>=1 && c<=10);
if(!c1) printf("The value of a=%d Its not in the range\n",a);
if(!c2) printf("The value of b=%d Its not in the range\n",b);
if(!c3) printf("The value of c=%d Its not in the range\n",c);
}
while(!(c1 && c2 && c3));

if(a<b+c && b<a+c && c<a+b)
istriangle='Y';
else
istriangle='N';

if(istriangle=='Y')
{
if((a==b)&&(b==c))
printf("Equilateral triangle\n");
else if((a!=b) && (a!=c) && (b!=c))
printf("Scalene triangle\n");
else

printf("Isosceles triangle\n");
}
else
printf("Not a triangle\n");
return 0;
}