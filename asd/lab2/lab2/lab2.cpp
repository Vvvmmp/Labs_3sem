#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

void bfs(const vector<vector<int>>& adj, int s, vector<bool>& visited, int& maxEl)
{
    priority_queue<int, vector<int>, greater<int>> q;

    visited[s] = true;
    q.push(s);
    if (maxEl < s) {
        maxEl = s;
    }
    while (!q.empty()) {
        int curr = q.top();
        q.pop();
        cout << curr + 1 << " "; 

        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
                if (maxEl < x) {
                    maxEl = x;
                }
            }
        }
    }
}

void dfs(const vector<vector<int>>& adj, int s, vector<bool>& visited, int& maxEl)
{
    visited[s] = true;
    cout << s + 1 << " "; 
    if (maxEl < s) {
        maxEl = s;
    }
    for (int x : adj[s]) {
        if (!visited[x]) {
            dfs(adj, x, visited, maxEl);
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u - 1].push_back(v - 1); 
    adj[v - 1].push_back(u - 1);
}

void printAdjacencyList(const vector<vector<int>>& adj) {
    cout << "\nСписок смежности:\n";
    for (int i = 0; i < adj.size(); i++) {
        cout << i + 1 << ": ";
        for (int neighbor : adj[i]) {
            cout << neighbor + 1 << " "; 
        }
        cout << "\n";
    }
}

void printAdjacencyMatrix(const vector<vector<int>>& matrix) {
    cout << "\nМатрица смежности:\n";
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    setlocale(0, "");
    int V, V1, V2;
    int maxEl = 0;
    int choice;
    int start;
    cout << "Введите количество вершин: ";
    cin >> V;

    vector<vector<int>> adj(V);
    vector<pair<int, int>> edgeList;
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    vector<bool> visited(V, false);

    cout << "Введите количество рёбер: ";
    int E;
    cin >> E;
    int result;
    result = E + V;

    cout << "Введите начальную вершину графа: ";
    cin >> start;

    cout << "Введите рёбра (u v): \n";
    for (int i = 0; i < E; i++)
    {
        cin >> V1 >> V2;
        addEdge(adj, V1, V2);
        edgeList.push_back(make_pair(V1, V2));
        matrix[V2 - 1][V1 - 1] = 1;
        matrix[V1 - 1][V2 - 1] = 1;
    }

    cout << "Выберите один из вариантов хранения графов\n";
    cout << "1 - список смежности\n";
    cout << "2 - список рёбер\n";
    cout << "3 - матрица смежности\n";
    cout << "4 - список рёбер (DFS)\n";
    cout << "5 - список смежности для DFS\n";
    cout << "6 - матрица смежности для DFS\n";
    cout << "Ваш выбор: ";
    cin >> choice;
    
    switch (choice)
    {
    case 1:
        cout << "BFS начинается с " << start << ": ";
        bfs(adj, start - 1, visited, maxEl);
        printAdjacencyList(adj);
        cout << "\nСложность: " << result;
        break;

    case 2:  
        cout << "BFS начинается с " << start << ": ";
        bfs(adj, start - 1, visited, maxEl);
        cout << "\nСписок рёбер: ";
        for (const auto& edge : edgeList) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << '\n';
        cout << "\nСложность: " << result;
        break;

    case 3:
        cout << "BFS начинается с " << start << ": ";
        bfs(adj, start - 1, visited, maxEl);
        printAdjacencyMatrix(matrix);
        cout << "\nСложность: " << pow(V,2);
        break;

    case 4: 
        cout << "DFS начинается с " << start << ": ";
        dfs(adj, start - 1, visited, maxEl);
        cout << "\nСписок рёбер: ";
        for (const auto& edge : edgeList) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << '\n';
        cout << "\nСложность: " << result;
        break;

    case 5:
        printAdjacencyList(adj);
        cout << "DFS начинается с " << start << ": ";
        dfs(adj, start - 1, visited, maxEl);
        cout << "\nСложность: " << result;
        break;
    case 6:
        {
        printAdjacencyMatrix(matrix);          
            cout << "DFS начинается с " << start << ": ";
            dfs(adj, start - 1, visited, maxEl);
            cout << "\nСложность: " <<  pow(V,2);
        break;
        }

    default:
        cout << "Неверный выбор!\n";
        return 0;
    }

    return 0;
}