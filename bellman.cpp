#include "bellman.h"

void BF(const int graph[][20], int num_vertices, char start_vertex,
        int distance[], int pre[])
{
    int startIndex = int(start_vertex - 'A');
    if (distance[startIndex] == -1)
    {
        distance[startIndex] = 0;
    }
    int *dis_input = new int[num_vertices];
    for (int i = 0; i < num_vertices; i++)
    {
        dis_input[i] = distance[i];
    }
    for (int v = 0; v < num_vertices; ++v)
    {
        for (int u = 0; u < num_vertices; ++u)
        {
            if (u == startIndex || dis_input[u] != -1)
            {
                if (graph[u][v] > 0 && distance[u] != -1)
                {
                    if (dis_input[u] + graph[u][v] < distance[v] || distance[v] == -1)
                    {
                        distance[v] = dis_input[u] + graph[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
    delete[] dis_input;
}

string BF_Path(const int graph[][20], int num_vertices, char start, char goal)
{
    int distance[20];
    int pre[20];
    memset(distance, -1, sizeof(distance));
    memset(pre, -1, sizeof(pre));
    for (int i = 0; i < num_vertices; i++)
    {
        BF(graph, num_vertices, start, distance, pre);
    }

    string path;
    for (int at = int(goal - 'A'); at != -1; at = pre[at])
    {
        string node(1, static_cast<char>('A' + at));
        path = node + (path.empty() ? "" : " ") + path;
        if (at == start - 'A')
            break;
    }
    if (path.substr(0, 1) != string(1, start))
    {
        return "";
    }

    return path;
}