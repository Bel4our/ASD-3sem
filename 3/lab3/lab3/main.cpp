#include <iostream>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    struct Edge {
        int start;
        int finish;
        int ves;
    };

    Edge edges[] = {
        {0, 1, 7}, {0, 2, 10},
        {1, 0, 7}, {1, 5, 9}, {1, 6, 27},
        {2, 0, 10}, {2, 5, 8}, {2, 4, 31},
        {3, 4, 32}, {3, 7, 17}, {3, 8, 21},
        {4, 2, 31}, {4, 3, 32},
        {5, 1, 9}, {5, 2, 8}, {5, 7, 11},
        {6, 1, 27}, {6, 8, 15},
        {7, 5, 11}, {7, 3, 17}, {7, 8, 15},
        {8, 3, 21}, {8, 7, 15}, {8, 6, 15}
    };

    int numEdges = sizeof(edges) / sizeof(Edge);
    const int numV = 9;

    char choice;
    cout << "Введите вершину (A-I): ";
    cin >> choice;

    while (choice < 'A' || choice > 'I') {
        cout << "Вы ввели неправильное значение! Введите вершину (A-I): ";
        cin >> choice;
    }

    int ch = choice - 65; 

    int dist[numV]; 
    bool vis[numV] = { false }; 

    for (int i = 0; i < numV; i++) {
        dist[i] = INT_MAX;
    }

    dist[ch] = 0; 

    for (int i = 0; i < numV; i++) {
        int min_distance = INT_MAX;
        int temp = -1;

        for (int j = 0; j < numV; j++) {
            if (!vis[j] && dist[j] < min_distance) {
                min_distance = dist[j];
                temp = j;
            }
        }

        if (temp == -1)
        {
            break; 
        }

        vis[temp] = true;

        for (int j = 0; j < numEdges; j++) {
            if (edges[j].start == temp) {
                int neighbor = edges[j].finish;
                int new_dist = dist[temp] + edges[j].ves;

                if (new_dist < dist[neighbor]) {
                    dist[neighbor] = new_dist;
                }
            }
        }
    }

    cout << "Минимальные расстояния от вершины " << choice << " до других вершин:" << endl;
    for (int i = 0; i < numV; i++) {
        char vName = 'A' + i; 
        if (dist[i] == INT_MAX) 
        {
            cout << vName << ": недостижима" << endl;
        }
        else {
            cout << vName << ": " << dist[i] << endl;
        }
    }

    return 0;
}
