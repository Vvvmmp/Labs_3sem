#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;


void printMatrix(vector<vector<pair<int, int>>>graph, int vertexCount)
{
    cout << "    ";
    for (int i = 0; i < vertexCount; ++i) {
        cout << setw(4) << (i + 1);
    }
    cout << endl;

    for (int i = 0; i < vertexCount; ++i) {
        cout << setw(2) << (i + 1) << " |";
        for (int j = 0; j < vertexCount; ++j) {
            bool found = false;
            for (const auto& edge : graph[i]) {
                if (edge.first == j) {
                    cout << setw(4) << edge.second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << setw(4) << "inf"; 
            }
        }
        cout << endl;
    }
}

void printMSTMatrix(const vector<vector<int>>& mst, int vertexCount) {
    cout << "\n(MST) Матрица:\n";
    cout << "    ";
    for (int i = 0; i < vertexCount; ++i) {
        cout << setw(4) << (i + 1);
    }
    cout << endl;

    for (int i = 0; i < vertexCount; ++i) {
        cout << setw(2) << (i + 1) << " |";
        for (int j = 0; j < vertexCount; ++j) {
            cout << setw(4) << mst[i][j]; 
        }
        cout << endl;
    }
}

void Prim(const vector<vector<pair<int, int>>>& graph, int vertexCount, int start) {
    vector<bool> inMST(vertexCount, false);
    vector<int> minEdge(vertexCount, INT_MAX);
    vector<int> parent(vertexCount, -1);
    vector<vector<int>> mst(vertexCount, vector<int>(vertexCount, 0));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Primaq;

    Primaq.push({ 0, start - 1 });
    minEdge[start - 1] = 0;

    int totalWeight = 0;

    while (!Primaq.empty()) {
        int weight = Primaq.top().first;
        int u = Primaq.top().second;
        Primaq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += weight;

        if (weight > 0) {
            cout << "Вершина " << (u + 1) << " включена в MST с весом " << weight << endl;
        }

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int edgeWeight = edge.second;

            
            if (!inMST[v] && edgeWeight < minEdge[v]) {
                minEdge[v] = edgeWeight;
                Primaq.push({ edgeWeight, v });
                parent[v] = u; 
            }
        }
    }

   for (int v = 0; v < vertexCount; ++v) {
        if (parent[v] != -1) {
            mst[parent[v]][v] = minEdge[v]; 
            mst[v][parent[v]] = minEdge[v]; 
        }
    }

    cout << "Полный вес MST: " << totalWeight << '\n';
    printMSTMatrix(mst, vertexCount);
}

void Kruskal(const vector<vector<pair<int, int>>>& graph, int vertexCount) {
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < vertexCount; ++u) {
        for (const auto& edge : graph[u]) {
            if (u < edge.first) { 
                edges.push_back({ edge.second, {u, edge.first} });
            }
        }
    }

    sort(edges.begin(), edges.end());

    vector<int> parent(vertexCount);
    iota(parent.begin(), parent.end(), 0);

    vector<vector<int>> mst(vertexCount, vector<int>(vertexCount, 0));
    int totalWeight = 0;

    for (const auto& edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        int rootU = parent[u];
        int rootV = parent[v];
        while (rootU != parent[rootU]) rootU = parent[rootU];
        while (rootV != parent[rootV]) rootV = parent[rootV];

        if (rootU != rootV) {
            parent[rootU] = rootV;
            mst[u][v] = weight;
            mst[v][u] = weight;
            totalWeight += weight;
            cout << "Вершина " << (u + 1) << " соединена с вершиной " << (v + 1) << " весом " << weight << endl;
        }
    }

    cout << "Полный вес MST: " << totalWeight << '\n';

    printMSTMatrix(mst, vertexCount);
}

int main()
{
	setlocale(0, "");
	ifstream inputFile("input.txt");
	int vertexCount = 8, edgeCount = 16;
    int cycleNumber;
    cycleNumber = edgeCount - vertexCount + 1;
	vector<vector<pair<int, int>>>graph(vertexCount);

	for (int i = 0; i < edgeCount; i++)
	{
		int a, b, weight;

		inputFile >> a >> b >> weight;
        a--;
        b--;
		graph[a].push_back({ b, weight });
		graph[b].push_back({ a, weight });
	}
    printMatrix(graph, vertexCount);

    int start;
    cout << "Выберите стартовую вершину: ";
    cin >> start;
    while (start < 1 || start > vertexCount) {
        cout << "Неверный ввод. Пожалуйста, выберите стартовую вершину (1-" << vertexCount << "): ";
        cin >> start;
    }

    cout << "\nВыберите вариант нахождения минимального остовного дерева:";
    cout << "\n1 - Алгоритм Прима.";
    cout << "\n2 - Алгоритм Краскаля.";
    cout << "\n0 - Выход из программы.";
    cout << "\nВаш вариант: ";
    int choice;
    cin >> choice;

    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "\n\n";
            Prim(graph, vertexCount, start);
            cout << "\n";
            cout << "Цикломатическое число равно: " << cycleNumber;
            cout << "\n";
            break;

        case 2:
            cout << "\n\n";
            Kruskal(graph, vertexCount);
            cout << "\n";
            cout << "Цикломатическое число равно: " << cycleNumber;
            cout << "\n";
            break;

        default:
            cout << "Ошибка";
            break;
        }
        cout << "Ваш выбор: ";
        cin >> choice;
        cout << '\n';
    }
        
    return 0;
}
