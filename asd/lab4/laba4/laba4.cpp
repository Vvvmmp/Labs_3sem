#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
	

int main() {
	setlocale(0, "");
	const int Inf = 1e9;

	int D[6][6] = {
  {0, 28, 21, 59, 12, 27},
  {7,  0, 24, Inf, 21, 9},
  {9, 32, 0, 13, 11, Inf},
  {8, Inf, 5, 0, 16, Inf},
  {14, 13, 15, 10, 0, 22},
  {15, 18, Inf, Inf, 6, 0}
	};
	int S[6][6] = {
	  {0, 2, 3, 4, 5, 6},
	  {1, 0, 3, 4, 5, 6},
	  {1, 2, 0, 4, 5, 6},
	  {1, 2, 3, 0, 5, 6},
	  {1, 2, 3, 4, 0, 6},
	  {1, 2, 5, 5, 5, 0}
	};


	int VertexCount = 6, edgeCount = 24;

	for (int v = 0; v < VertexCount; v++) {
		for (int a = 0; a < VertexCount; a++) {
			for (int b = 0; b < VertexCount; b++) {
				if (D[a][v] != Inf && D[v][b] != Inf && D[a][b] > D[a][v] + D[v][b]) {
					D[a][b] = D[a][v] + D[v][b]; 
					S[a][b] = v+1;
				}
			}
		}
	}

	for (int a = 0; a < VertexCount; a++) {
		for (int b = 0; b < VertexCount; b++) {
			cout << D[a][b];
			if (D[a][b] > 9)
				cout << " ";
			else
				cout << "  ";
		}
			cout << '\n';	
	}
	cout << "\n\n";

	for (int a = 0; a < VertexCount; a++) {
		for (int b = 0; b < VertexCount; b++) {
			if (a == b) {
				cout << 0 << ' '; 
			}
			else if (S[a][b] != -1) {
				cout << S[a][b] << ' '; 
			}
			else {
				cout << VertexCount << ' ';
			}
		}
		cout << '\n';
	}

	int start;
	int finish;

	while (true)
	{
		cout << "Введите начальную вершину: ";
		cin >> start;
		if (start >= 1 && start <= 6)
		{
			break;
		}
	}


	while (true)
	{
		cout << "Введите конечуню вершину: ";
		cin >> finish;
		if (finish >= 1 && finish <= 6)
		{
			break;
		}
	}

	start--;
	finish--;

	cout << "Кратчайший путь из вершины " << start + 1 << " в вершину " << finish + 1 << " имеет длину: " << D[start][finish] << endl;

	cout << "Путь: " << start + 1 << " ";
	int cur1 = start;
	int cur2 = finish;

	int buf = S[cur1][cur2] - 1;

	while (buf != cur2)
	{
		cout << S[cur1][cur2] << " ";
		cur1 = cur2;
		cur2 = buf;

	}
	cout << finish + 1 << " ";
	cout << endl;
	return 0;
}