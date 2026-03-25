#include "tsp.h"

void Backtracking(int i, int n, const int graph[][20], int &d, int &ans, int cmin, int visited[], int City[], int result[])
{
    for (int j = 0; j < n; j++)
    {
        if (visited[j] == 0)
        {
            visited[j] = 1;
            City[i] = j;
            d += graph[City[i - 1]][City[i]];
            if (graph[City[i - 1]][City[i]] != 0)
            {
                if (i == n - 1)
                {
                    if (graph[City[n - 1]][0] != 0)
                    {
                        if (ans > d + graph[City[n - 1]][City[0]])
                        {
                            ans = d + graph[City[n - 1]][City[0]];
                            for (int k = 0; k < n; k++)
                            {
                                result[k] = City[k];
                            }
                        }
                    }
                }
                else if (d + (n - i) * cmin < ans)
                {
                    Backtracking(i + 1, n, graph, d, ans, cmin, visited, City, result);
                }
            }
            visited[j] = 0;
            d -= graph[City[i - 1]][City[i]];
        }
    }
}

string Traveling(const int graph[][20], int num_vertices, char start)
{
    int visited[20];
    int City[20];
    int result[20];
    int d = 0, ans = INT_MAX, cmin;
    memset(visited, 0, sizeof(visited));
    cmin = INT_MAX;
    for (int i = 0; i < num_vertices; i++)
    {
        for (int j = 0; j < num_vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                cmin = min(cmin, graph[i][j]);
            }
        }
    }
    City[0] = int(start - 'A');
    visited[int(start - 'A')] = 1;
    Backtracking(1, num_vertices, graph, d, ans, cmin, visited, City, result);
    string path = "";
    for (int i = 0; i < num_vertices; i++)
    {
        string node(1, static_cast<char>('A' + result[i]));
        path += node + " ";
    }
    path += static_cast<char>('A' + result[0]);
    cout << "Cost: " << ans << endl;
    return path;
}