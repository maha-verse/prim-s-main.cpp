#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    int V = 4;
    int graph[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    int key[4], parent[4];
    bool mst[4] = {false};

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0;
    int cost = 0;

    for (int count = 0; count < V; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;

        mst[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !mst[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Roads selected:\n";

    for (int i = 1; i < V; i++)
    {
        cout << parent[i] + 1 << " - " << i + 1
             << " : " << key[i] << endl;
        cost += key[i];
    }

    cout << "Minimum construction cost = " << cost << endl;

    return 0;
}
