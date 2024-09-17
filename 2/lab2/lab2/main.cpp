#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");

    int choice = 0;

    int* graph[] = {
        new int[2] {2, 5},
        new int[3] {1, 7, 8},
        new int[1] {8},
        new int[2] {6, 9},
        new int[2] {1, 6},
        new int[3] {4, 5, 9},
        new int[2] {2, 8},
        new int[3] {2, 3, 7},
        new int[3] {4, 6, 10},
        new int[1] {9}
    };

    int size[] = {2, 3, 1, 2, 2, 3, 2, 3, 3, 1};
    bool vis[10] = {false};
    


    
    while (true)
    {
        cout << "Введите вершину: "; cin >> choice;
        if (choice > 0 && choice<=10)
        {
            break;
        }
        cout << "Вы ввели неправильно значение!" << endl;
    }
    cout << "--------Список смежности----------" << endl << endl;
    cout << "BFS: " << endl << endl;
    queue<int> qPeaks1;

    qPeaks1.push(choice);

    cout << endl;
    int count = 0;
    while (!qPeaks1.empty())
    {
        int temp = qPeaks1.front()-1;

        qPeaks1.pop();
        
        if (vis[temp])
        {
            continue;
        }

        cout << "Посетили вершину: " << temp + 1 << endl;

        for (int i = 0; i < size[temp];i++)
        {
            if (!vis[graph[temp][i] - 1])
            {
                qPeaks1.push(graph[temp][i]);
                count++;
            }
           
        }

        vis[temp] = true;
       

    }


    cout << endl << "DFS: " << endl << endl;

    for (int i = 0;i < 10;i++)
    {
        vis[i] = false;
    }

    stack<int> sPeaks1;
    sPeaks1.push(choice);

    while (!sPeaks1.empty())
    {
        int temp = sPeaks1.top() - 1;

        sPeaks1.pop();

       if (vis[temp])
        {
            continue;
        }

        cout << "Посетили вершину: " << temp + 1 << endl;

        for (int i = 0; i < size[temp];i++)
        {
            if (!vis[graph[temp][i] - 1])
            {
                sPeaks1.push(graph[temp][i]);
            }
        }

        vis[temp] = true;
    }


    int matr[10][10] = { {0,1,0,0,1,0,0,0,0,0},
                         {1,0,0,0,0,0,1,1,0,0},
                         {0,0,0,0,0,0,0,1,0,0},
                         {0,0,0,0,0,1,0,0,1,0},
                         {1,0,0,0,0,1,0,0,0,0},
                         {0,0,0,1,1,0,0,0,1,0},
                         {0,1,0,0,0,0,0,1,0,0},
                         {0,1,1,0,0,0,1,0,0,0},
                         {0,0,0,1,0,1,0,0,0,1},
                         {0,0,0,0,0,0,0,0,1,0} };


    cout << endl<<endl<<"--------Матрица смежности----------" << endl << endl;
    cout << "BFS: " << endl << endl;


    queue<int> qPeaks2;

    qPeaks2.push(choice-1);

    for (int i = 0;i < 10;i++)
    {
        vis[i] = false;
    }

    while (!qPeaks2.empty())
    {
        int temp = qPeaks2.front();

        qPeaks2.pop();

        if (vis[temp])
        {
            continue;
        }

        cout << "Посетили вершину: " << temp + 1 << endl;

        for (int i = 0; i < 10; i++) {
            if (matr[temp][i] == 1 && !vis[i]) {
                qPeaks2.push(i);
            }
        }

        vis[temp] = true;
    }

        
    cout << endl << "DFS: " << endl << endl;

    for (int i = 0;i < 10;i++)
    {
        vis[i] = false;
    }

    stack<int> sPeaks2;
    sPeaks2.push(choice-1);


    while (!sPeaks2.empty())
    {
        int temp = sPeaks2.top();

        sPeaks2.pop();

        if (vis[temp])
        {
            continue;
        }

        cout << "Посетили вершину: " << temp + 1 << endl;

        for (int i = 0; i < 10; i++) {
            if (matr[temp][i] == 1 && !vis[i]) {
                sPeaks2.push(i);
            }
        }

        vis[temp] = true;
    }


    struct Edge
    {
        int start;
        int finish;
    };

    Edge edges[] = {
        {1, 2}, {1, 5},
        {2, 1}, {2, 7}, {2, 8},
        {3, 8},
        {4, 6}, {4, 9},
        {5, 1}, {5, 6},
        {6, 4}, {6, 5}, {6, 9},
        {7, 2}, {7, 8},
        {8, 2}, {8, 3}, {8, 7},
        {9, 4}, {9, 6}, {9, 10},
        {10, 9}
    };

    cout << endl << endl << "--------Список рёбер----------" << endl << endl;
    cout << "BFS: " << endl << endl;

    queue<int> qPeaks3;
    qPeaks3.push(choice);

    for (int i = 0; i < 10; i++) {
        vis[i] = false;
    }
    vis[choice-1] = true;
    
    while (!qPeaks3.empty())
    {
        int temp = qPeaks3.front();
        qPeaks3.pop();


        cout << "Посетили вершину: " << temp << endl;

        for (Edge e : edges)
        {
            if (e.start == temp && !vis[e.finish - 1])
            {
                qPeaks3.push(e.finish);
                vis[e.finish - 1] = true;
            }
            else if (e.finish == temp && !vis[e.start - 1])
            {
                qPeaks3.push(e.start);
                vis[e.start - 1] = true;
            }
        }
        
       
    }

    cout << endl << "DFS: " << endl << endl;

    for (int i = 0; i < 10; i++) {
        vis[i] = false;
    }

    stack<int> sPeaks3;
    sPeaks3.push(choice);

    while (!sPeaks3.empty())
    {
        int temp = sPeaks3.top();
        sPeaks3.pop();

        if (vis[temp - 1])
        {
            continue;
        }

        cout << "Посетили вершину: " << temp << endl;

        for (Edge e : edges)
        {
            if (e.start == temp && !vis[e.finish - 1])
            {
                sPeaks3.push(e.finish);
            }
            else if (e.finish == temp && !vis[e.start - 1])
            {
                sPeaks3.push(e.start);
            }
        }

        vis[temp - 1] = true;
    }


    int V = 10;
    int E = 11;

    cout << "О для матрицы смежности: " << V * V << endl;
    cout << "О для списков смежности и рёбер: " << V + E;

    return 0;
}