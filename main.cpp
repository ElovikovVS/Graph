#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
const int inf = 16000;

void full(int mas[100][100],int amount_vertex)
{
    int first_vertex,second_vertex,Rib_weight;
    //Primary zeroing of the matrix
    for (int i = 0; i < amount_vertex; ++i)
        for (int j = 0; j < amount_vertex; ++j)
        {
            if (i == j) mas[i][j] = 0;
            else mas[i][j] = inf;
        }
    //Filling the matrix where i,j element is the weight of the edge
    printf("please enter first_vertex second_vertex Rib weight ");
    scanf("%d %d %d",&first_vertex,&second_vertex,&Rib_weight);
    while (first_vertex != -1)
    {
        mas[first_vertex - 1][second_vertex - 1] = Rib_weight;
        scanf("%d %d %d",&first_vertex,&second_vertex,&Rib_weight);
    }
    //
    first_vertex = 0;
    for (int i = 0; i < amount_vertex; ++i)
    {
        for (int j = 1 + first_vertex; j < amount_vertex; ++j)
            mas[j][i] = mas[i][j];
        first_vertex++;
    }
}

int main()
{
    int amount_vertex,mas[100][100];
    scanf("%d", &amount_vertex);
    full(mas,amount_vertex);

    for (int i = 0; i < amount_vertex; ++i)
    {
        for (int j = 0; j < amount_vertex; ++j)
            printf("%5d ",mas[i][j]);
        printf("\n");
    }

    for (int k = 0; k < amount_vertex; ++k)
        for (int i = 0; i < amount_vertex; ++i)
            for (int j = 0; j < amount_vertex; ++j)
                if (mas[i][k] < inf && mas[k][j] < inf) mas[i][j] = min(mas[i][j],mas[i][k] + mas[k][j]);

    printf ("\n");

    for (int i = 0; i < amount_vertex; ++i)
    {
        for (int j = 0; j < amount_vertex; ++j)
            printf("%5d ",mas[i][j]);
        printf("\n");
    }
    //Finding the median of the graph
    int sum = 16000, sum1, med_v;
    for (int i = 0; i < amount_vertex; ++i)
    {
        sum1 = 0;
        for(int j = 0; j < amount_vertex; ++j)
            if (mas[i][j] < 16000) sum1 += mas[i][j];
        if (sum > sum1)
            {
                sum = sum1;
                med_v = i;
            }
    }
    printf("%d ",med_v);
    system("pause");
    return 0;
}
