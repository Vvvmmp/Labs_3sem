#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Graph {
    int numCities;
    vector<vector<int>> adjMatrix;

    Graph(int cities) : numCities(cities) {
        adjMatrix.resize(cities, vector<int>(cities, 0));
    }

    void setRandomDistance() {
        for (int i = 0; i < numCities; i++) {
            for (int j = 0; j < numCities; j++) {
                if (i != j) {
                    adjMatrix[i][j] = rand() % 50 + 1;
                }
                else {
                    adjMatrix[i][j] = 0;
                }
            }
        }
    }

    int getDistance(int city1, int city2) {
        if (city1 < 0 || city1 >= numCities || city2 < 0 || city2 >= numCities) {
            return 1;
        }
        return adjMatrix[city1][city2];
    }

    void loadFromFile(const string& filename) {
        ifstream input(filename);
        if (!input) {
            cout << "Не открылся файл!" << endl;
            return;
        }

        input >> numCities;
        adjMatrix.clear();
        adjMatrix.resize(numCities, vector<int>(numCities, 0));

        int city1, city2, distance;
        while (input >> city1 >> city2 >> distance) {
            addRoad(city1 - 1, city2 - 1, distance);
        }
        input.close();
        cout << "Граф загружен из файла\n";
    }
    void addRoad(int city1, int city2, int distance) {
        if (city1 < numCities && city2 < numCities) {
            adjMatrix[city1][city2] = distance;
        }
        else {
            cout << "Дороги не существуют!";
        }
    }
    void display() {
        cout << "Матрица смежности:\n";
        for (int i = 0; i < numCities; i++) {
            for (int j = 0; j < numCities; j++) {
                if (adjMatrix[i][j] > 9)
                    cout << adjMatrix[i][j] << " ";
                else
                    cout << adjMatrix[i][j] << "  ";
            }
            cout << '\n';
        }
    }
};

struct Ant {
    vector<int> path;
    float totalDistance;

    void travel(Graph& graph, const vector<vector<float>>& pheromones, float a, float b) {
        int currentCity = path.back();
        vector<double> probabilities(graph.numCities, 0.0);
        double sumProbabilities = 0.0;

        for (int i = 0; i < graph.numCities; ++i) {
            if (find(path.begin(), path.end(), i) == path.end()) {
                double visibility = 1.0 / graph.getDistance(currentCity, i);
                double pheromoneLevel = pheromones[currentCity][i];
                probabilities[i] = pow(visibility, a) * pow(pheromoneLevel, b);
                sumProbabilities += probabilities[i];
            }
        }

        if (sumProbabilities == 0.0) {
            int randomCity;
            do {
                randomCity = rand() % graph.numCities;
            } while (find(path.begin(), path.end(), randomCity) != path.end());
            path.push_back(randomCity);
            totalDistance += graph.getDistance(currentCity, randomCity);
            return;
        }

        for (int i = 0; i < graph.numCities; ++i) {
            probabilities[i] /= sumProbabilities;
        }

        double randomValue = static_cast<double>(rand()) / RAND_MAX;
        double cumulativeProbability = 0.0;

        for (int i = 0; i < graph.numCities; ++i) {
            cumulativeProbability += probabilities[i];
            if (randomValue <= cumulativeProbability) {
                path.push_back(i);
                totalDistance += graph.getDistance(currentCity, i);
                cout << "Муравей перешел из города " << currentCity + 1 << " в город " << i + 1 << endl;
                return;
            }
        }
    }
};

struct Pheromone {
    vector<vector<float>> pherom;
    int numCities;
    Pheromone(int numCities) {
        pherom.resize(numCities, vector<float>(numCities, 0.1f));
    }

    void updatePheromones(const vector<int>& bestPath, float bestDistance, float clearFer) {
        for (int i = 0; i < pherom.size(); ++i) {
            for (int j = 0; j < pherom[i].size(); ++j) {
                pherom[i][j] *= (1.0f - clearFer);
                //if (pherom[i][j] < 0.1f) {
                //    pherom[i][j] = 0.1f;
                //}
            }
        }

        for (size_t i = 0; i < bestPath.size() - 1; ++i) {
            int cityA = bestPath[i];
            int cityB = bestPath[i + 1];
            pherom[cityA][cityB] += 0.3f / bestDistance;
        }
    }

    void displayFer() {
        cout << "Таблица феромонов:\n";
        for (const auto& row : pherom) {
            for (const auto& pher : row) {
                cout  << pher << " ";
            }
            cout << '\n';
        }
    }
    };

int main() {
    srand(static_cast<unsigned int>(time(0)));
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int countCities, iterations;
    float alpha, beta, clearFer = 0.05;

    cout << "Введите количество городов: ";
    cin >> countCities;
    cout << "Введите количество итераций: ";
    cin >> iterations;
    cout << "Введите значения alpha и beta: ";
    cin >> alpha >> beta;

    Graph graph(countCities);
    //graph.setRandomDistance();
    graph.loadFromFile("input.txt");
    graph.display();

    Pheromone pheromones(countCities);
    vector<int> bestPath;
    float bestDistance = FLT_MAX;

    for (int i = 0; i < countCities; ++i) {
        for (int j = 0; j < countCities; ++j) {
            if (i != j) {
                pheromones.pherom[i][j] = 0.1f;
            }
        }
    }

    for (int iter = 0; iter < iterations; ++iter) {
        vector<Ant> ants(countCities);

        for (int i = 0; i < countCities; ++i) {
            ants[i].path.push_back(rand() % countCities);
            ants[i].totalDistance = 0.0f;

            while (ants[i].path.size() < countCities) {
                ants[i].travel(graph, pheromones.pherom, alpha, beta);
            }
            cout << '\n';

            if (ants[i].totalDistance < bestDistance) {
                bestDistance = ants[i].totalDistance;
                bestPath = ants[i].path;
            }
        }

        for (const Ant& ant : ants) {
            pheromones.updatePheromones(ant.path, ant.totalDistance, clearFer);
        }
        cout << '\n';
        cout << "\nЛучший путь: ";
        for (int city : bestPath) {
            cout << (city + 1) << " ";
        }
        cout << "\n\nИтерация " << iter + 1 << ": Лучший путь имеет длину " << bestDistance << endl;
        pheromones.displayFer();

    }

    cout << "Лучший путь: ";
    for (int city : bestPath) {
        cout << (city + 1) << " ";
    }
    cout << "\nДлина лучшего пути: " << bestDistance << endl;

    return 0;
}

