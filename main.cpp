#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
const int inf=16000;

void full(int a[100][100],int n)
{
    int c,e,f;
    scanf("%d %d %d",&c,&e,&f);
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
        {
            if (i==j) a[i][j] = 0;
            else a[i][j] = inf;
        }
    while (c != -1)
    {
        a[c-1][e-1]=f;
        scanf("%d %d %d",&c,&e,&f);
    }
    c=0;
    for (int i=0; i<n; ++i)
    {

        for (int j=1+c; j<n; ++j)
            a[j][i]=a[i][j];
        c++;
    }
}

int main()
{
    int n,i,j,k,a[100][100];
    scanf("%d", &n);
    full(a,n);

    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
            printf("%5d ",a[i][j]);
        printf("\n");
    }

    for (k=0;k<n;++k)
        for (i=0;i<n;++i)
            for (j=0;j<n;++j)
                if (a[i][k]<inf && a[k][j]<inf) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);

    printf ("\n");

    for (i=0; i<n; ++i)
    {
        for (j=0; j<n; ++j)
            printf("%5d ",a[i][j]);
        printf("\n");
    }

    int sum=16000, sum1, med_v;
    for (i=0; i<n; ++i)
    {
        sum1=0;
        for(j=0; j<n; ++j)
            if (a[i][j]<16000) sum1 += a[i][j];
        if (sum > sum1)
            {
                sum=sum1;
                med_v=i;
            }
    }
    printf("%d \n",sum);
    printf("%d ",med_v);
system("pause");
return 0;
}
