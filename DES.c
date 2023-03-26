#include<stdio.h>
#include<conio.h>
#define ull unsigned long long
#define ul unsigned long
#define pp (((ull)1<<32)-1)
int main()
{
    ull p,c;
    ul k,l0,r0,l1,r1;
    printf("Enter the plain text: ");
    scanf("%llu",p);
    printf("Enter the Key: ");
    scanf("%lu",k);
    l0 = p >> 32;
    r0 = p & pp;
    l1 = r0;
    r1 = l0^(r0^k);
    c=0;
    c=c|l1;
    c=(c << 32)|r1;
    printf("The cipher text is: ",c);
}



