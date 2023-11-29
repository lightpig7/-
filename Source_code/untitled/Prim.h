#include <stdio.h>
#include <string>

#define MAX 100
#define MAXCOST 100000

std::basic_string<char> prim(int graph[][MAX + 1], int n)
{
    std::string result = "Prim: Edges and weights of the minimum spanning tree:\n";
    int lowcost[MAX + 1];
    int mst[MAX + 1];
    int i, j, min, minid, sum = 0;

    for (i = 2; i <= n; i++)
    {
        lowcost[i] = graph[1][i];
        mst[i] = 1;
    }
    mst[1] = 0;

    for (i = 2; i <= n; i++)
    {
        min = MAXCOST;
        minid = 0;

        for (j = 2; j <= n; j++)
        {
            if (lowcost[j] < min && lowcost[j] != 0)
            {
                min = lowcost[j];
                minid = j;
            }
        }

        if (minid != 0)
        {
            char tmp[100];
            sprintf(tmp, "V%d-V%d=%d\n", mst[minid]-1, minid-1, min);
            result += tmp;

            sum += min;
            lowcost[minid] = 0;

            for (j = 2; j <= n; j++)
            {
                if (graph[minid][j] < lowcost[j] && lowcost[j] != 0)
                {
                    lowcost[j] = graph[minid][j];
                    mst[j] = minid;
                }
            }
        }
    }

    char tmp[100];
    sprintf(tmp, "The sum of minimum weights=%d", sum);
    result += tmp;
    return result;
}

std::basic_string<char> runPrim(int m, int n, int graph_v[][3])
{
    int graph[MAX + 1][MAX + 1];
    int i, j, k;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            graph[i][j] = MAXCOST;
        }
    }

    for (k = 0; k < n; k++)
    {
        i = graph_v[k][0] + 1; // 调整节点索引
        j = graph_v[k][1] + 1;
        graph[i][j] = graph[j][i] = graph_v[k][2];
    }

    return prim(graph, m);
}
