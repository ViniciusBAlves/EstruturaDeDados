#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"
#define max 6


void DFS (int grafo[max+1][max+1], int v, int vis[max+1], int colour[max+1]);
void BFS (int grafo[max+1][max+1], int v, int vis[max+1], int colour[max+1]);

int main()
{
    int i,j;
    int grafo[max+1][max+1];
    int vis[max+1], colour[max+1];

    TipoDFila* FV;

    for(i=1; i <= max; i++)
        for(j=1; j <= max; j++)
            grafo[i][j] = 0;

    for (i=1;i<=max;i++)
        vis[i]=false;

    for(i=1; i<= max; i++)
        colour[i]=0;

    grafo[1][2]=1;
    grafo[1][6]=1;
    grafo[2][1]=1;
    grafo[2][3]=1;
    grafo[2][4]=1;
    grafo[3][2]=1;
    grafo[3][4]=1;
    grafo[3][5]=1;
    grafo[4][2]=1;
    grafo[4][3]=1;
    grafo[4][5]=1;
    grafo[4][6]=1;
    grafo[5][3]=1;
    grafo[5][4]=1;
    grafo[5][6]=1;
    grafo[6][1]=1;
    grafo[6][4]=1;
    grafo[6][5]=1;


    i = highestGrade(grafo);
    DFS(grafo, i, vis, colour);

    printf("\n");

    for (i=1;i<=max;i++)
        vis[i]=false;
    for (i=0;i<=max;i++)
        colour[i]=0;

    i=highestGrade(grafo);

    BFS(grafo, i, vis, colour);

    return 0;
}


void DFS(int grafo[max+1][max+1], int v, int vis[], int colour[])
{
    int w;

    vis[v] = true;
    printf("%d\n", v);
    colourNode(grafo, v, colour);
    printColour(colour[v]);

    for(w = 1; w <= max+1; w++)
    {
        if(grafo[v][w] == 1){
            if(vis[w] == 0){
                DFS(grafo, w, vis, colour);
            }
        }
    }
}

void BFS(int grafo[max+1][max+1], int v, int vis[max+1], int colour[])
{
    TipoDFila *FV;
    int w;
    vis[v] = true;
    FV = InicializaFila(FV);
    InserirFila(&FV, v);
    while(VaziaFila(FV) == 0)
    {
        RemoverFila(&FV, &w);
        printf("%d\n", w);
        colourNode(grafo, w, colour);
        printColour(colour[w]);
        v = w;
        for(w=1; w < max+1; w++)
        {
            if(grafo[v][w]==1){
                if(vis[w] == 0)
                {
                    InserirFila(&FV, w);
                    vis[w] = true;
                }
            }
        }
    }
}

int highestGrade(int grafo[max+1][max+1])
{
    int highGrade = 0, w, grade=0;
    for(int i=1; i <= max+1; i++)
    {
        grade = 0;
        for(int j=1; j <= max+1; j++)
        {
            if(grafo[i][j] == 1)
            {
                grade++;
            }
        }
        if(grade > highGrade)
        {
            highGrade = grade;
            w = i;
        }
    }

    return w;
}

void colourNode(int grafo[max+1][max+1], int i, int colour[])
{
    int loop = 1;
    do
    {
        loop=0;
        for(int j=1; j < max+1; j++)
        {
            if(grafo[i][j] == 1)
            {
                if(colour[i] == colour[j] || colour[i] == 0)
                {
                    colour[i]++;
                    loop=1;
                }
            }
        }
    }while(loop);
}

void printColour(int colour)
{
    switch(colour)
    {
        case 1:
            printf("Amarelo\n");
            break;
        case 2:
            printf("Vermelho\n");
            break;
        case 3:
            printf("Azul\n");
            break;
        case 4:
            printf("Verde\n");
            break;
    }
}
