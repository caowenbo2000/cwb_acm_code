#include<stdio.h>
#include<math.h>
int main ()
{
    long long t,b,a,c,d,m;
    scanf("%lld",&t);
    double x1,x2,y1,y2,k;
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        m=4*b*b-12*a*c;
        x1=(-2*b+sqrt(m))/(6*a);
        x2=(-2*b-sqrt(m))/(6*a);
        y1=a*x1*x1*x1+b*x1*x1+c*x1+d;
        y2=a*x2*x2*x2+b*x2*x2+c*x2+d;
        k=y1*y2;
        if(m>0)
        {
            if(k>0)
                printf("1\n");
            if(k==0)
                printf("2\n");
            if(k<0)
                printf("3\n");
        }
        if(m<=0)
        {
            printf("1\n");
        }
    }
    return 0;
}
