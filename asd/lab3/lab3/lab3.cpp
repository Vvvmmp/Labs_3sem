#include "iostream"
#include "vector"
#include <utility>
#include <fstream>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int start) {
	vector<int> dist(graph.size(), INF);
	dist[start] = 0;
	vector<bool> visited(graph.size(), false);

	for (int i = 0; i < graph.size(); i++) {
		int nearest = -1;
		for (int v = 0; v < graph.size(); v++) {
			if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v])) {
				nearest = v;
			}
		}
		if (nearest == -1) break;
		visited[nearest] = true;

		for (size_t j = 0; j < graph[nearest].size(); j++) {
			int to = graph[nearest][j].first;
			int weight = graph[nearest][j].second;
			if (dist[to] > dist[nearest] + weight) {
				dist[to] = dist[nearest] + weight;
			}
		}
	}
	return dist;
}

int main() {
	setlocale(0, "");
	ifstream inputFile("input.txt");
	int vertexCount = 9, edgeCount = 12;

	vector<vector<pair<int, int>>> graph(vertexCount);

	for (int i = 0; i < edgeCount; i++)
	{
		char a, b;
		int weight;
		//cout << "\nВведите начало, конец и вес ребра: ";
		inputFile >> a >> b >> weight;

		int u = a - 'A';
		int v = b - 'A';

		graph[u].push_back({ v, weight });
		graph[v].push_back({ u, weight });
	}

	char startChar;
	cout << "\nВведите стартовую вершину: ";
	cin >> startChar;
	int start = startChar - 'a';

	vector<int>dist = dijkstra(graph, start);

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] != INF)
			cout << "Расстояние до " << char(i + 'A') << " равно: " << dist[i] << '\n';
		else
			cout << "Расстояние до " << char(i + 'A') << " равно: inf" << '\n';
	}

	return 0;
}