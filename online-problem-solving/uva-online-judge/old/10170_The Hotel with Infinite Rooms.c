#include<stdio.h>

void main()
{
  long long s,d,r,i;
  while (scanf("%lld %lld",&s,&d)!=EOF)
  {
    r=0;
    for (i=s;r<d;i++)
      r+=i;
    i--;
    printf("%lld\n",i);
  }
}
