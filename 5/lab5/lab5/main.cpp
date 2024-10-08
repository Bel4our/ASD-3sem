#include <iostream>

using namespace std;

int findParent(int v, int parent[])
{
    while (v != parent[v])
    {
        v = parent[v];
    }
    return v;
}

void unionSets(int u, int v, int parent[])
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    parent[rootU] = rootV;
}

int main()
{
    setlocale(LC_ALL, "rus");

    const int N = 8;


    int graph[N][N] = {
        {0, 2, 0, 8, 2, 0, 0, 0},
        {2, 0, 3, 10, 5, 0, 0, 0},
        {0, 3, 0, 0, 12, 0, 0, 7},
        {8, 10, 0, 0, 14, 3, 1, 0},
        {2, 5, 12, 14, 0, 11, 4, 8},
        {0, 0, 0, 3, 11, 0, 6, 0},
        {0, 0, 0, 1, 4, 6, 0, 9},
        {0, 0, 7, 0, 8, 0, 9, 0},
    };

    int edge = 0; 

    bool selected[N] = { false };
    selected[0] = true;        

    int x, y, weight=0; 

    while (edge < N - 1)
    {
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < N; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < N; j++)
                {
                    if (!selected[j] && graph[i][j]!=0)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x+1 << " - " << y+1 << " : " << graph[x][y] << endl;

        selected[y] = true; 
        weight += graph[x][y];
        edge++;             
    }
    cout << "Вес: " << weight<<endl<<endl;



    struct Edge
    {
        int V, U, weight;
    };

    Edge edges[] = {
        {0, 1, 2}, {0, 3, 8},
        {0, 4, 2}, {1, 2, 3},
        {1, 3, 10}, {1, 4, 5},
        {2, 4, 12}, {2, 7, 7},
        {3, 4, 14}, {3, 5, 3},
        {3, 6, 1}, {4, 5, 11},
        {4, 6, 4}, {4, 7, 8},
        {5, 6, 6}, {6, 7, 9}
    };

    int edgeCount = 16;

    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }


    int parent[N];
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    int weight2 = 0;

    int edgesUsed = 0;

    for (int i = 0; i < edgeCount && edgesUsed < N - 1; i++)
    {
        int u = edges[i].V;
        int v = edges[i].U;
        int weight = edges[i].weight;

        if (findParent(u, parent) != findParent(v, parent))
        {

            unionSets(u, v, parent);
            weight2 += weight;
            edgesUsed++;

            cout << " " << u + 1 << "   -   " << v + 1 << "   :   " << weight << endl;
        }
    }

    cout << "Вес: " << weight2 << endl;
    cout << endl << endl << endl << "Цикломатическое число: " << edgeCount - N + 1 << endl;
    return 0;
}