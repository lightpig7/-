//Implement Kruskal's minimum spanning tree algorithm, understand graph data structure storage representation.
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <cstring>
#include <string>

#define maxnode 64
#define maxedgs 2016
#define maxvalue 10000

typedef struct acr            //Definition of arc
{
    int pre;                  //One node of the arc
    int bak;                  //The other node of the arc
    int weight;               //Weight value of the arc
}edg;


  //Arc tag array to prevent loops



void init(edg *edgs,int graph[][3])
{
    for(int i = 0; i < 10; i++) {
        edgs[i].pre = graph[i][0];
        edgs[i].bak = graph[i][1];
        edgs[i].weight = graph[i][2];
    }
}

int find(int f,int *arcvisited)                              //Use union-find set
{
    while(arcvisited[f]>0)
        f=arcvisited[f];
    return f;
}

std::string kruskal(edg *edgs,edg *edgs2,int m,int n)
{
    int x,y,v;
    int buf,edf;
    int l=0;
    int k;
    int arcvisited[maxnode]={0};
    for(int i=1;i<=n;i++)
    {
        v=maxvalue;
        k=0;

        for(int j=1;j<=n;j++)                     //Find edge with minimum weight
        {
            if(edgs[j].weight<v)
            {
                v=edgs[j].weight;
                x=edgs[j].pre;
                y=edgs[j].bak;
                k=j;
            }
        }

        buf=find(x,arcvisited);
        edf=find(y,arcvisited);
        edgs[k].weight=maxvalue;            //Set weight of this edge to max to mark as visited
        if(buf!=edf)                        //no loop
        {
            l++;
            arcvisited[buf]=edf;
            edgs2[l].pre=x;
            edgs2[l].bak=y;
            edgs2[l].weight=v;
        }
        if(l==m-1)
            break;
    }

    if(l<m-1)
    {
        return "Does not exist!\n";
    }
    else
    {
        std::string result = "Kruskal:Edges and weights of the minimum spanning tree:\n";
        for(int i=1; i<=l; i++){

            char tmp[100];
            sprintf(tmp, "(%d,%d):%d\n", edgs2[i].pre, edgs2[i].bak, edgs2[i].weight);

            result += tmp;
        }
        return result;
    }
}

std::string runKruskal(int m,int n,int graph[][3])
{
    edg edgs[maxedgs],edgs2[maxedgs];
    init(edgs,graph);
    std::string result = kruskal(edgs,edgs2,m,n);
    return result;
}
