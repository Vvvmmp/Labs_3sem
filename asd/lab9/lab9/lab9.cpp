#define _USE_MATH_DEFINES
#define MAX_CHILD 2
#define MIN_CITY 8

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <cstdlib>

using namespace std;

struct Graph {
    int numCities;
    vector<vector<int>> adjMatrix;

    Graph(int cities) : numCities(cities) {
        adjMatrix.resize(cities, vector<int>(cities, 0));
    }

    void addCity() {
        numCities++;
        for (auto& row : adjMatrix) {
            row.push_back(0);
        }
        adjMatrix.push_back(vector<int>(numCities, 0));
    }

    void removeCity(int city) {
        if (city < 0 || city >= numCities) {
            cout << "Такого города нету";
            return;
        }
        numCities--;
        adjMatrix.erase(adjMatrix.begin() + city);
        for (auto& row : adjMatrix) {
            row.erase(row.begin() + city);
        }
    }

    void addRoad(int city1, int city2, int distance) {
        if (city1 < numCities && city2 < numCities) {
            adjMatrix[city1][city2] = distance;
            //adjMatrix[city2][city1] = distance;
        }
        else {
            cout << "Дороги не существуют!";
        }
    }

    int getDistance(int city1, int city2) {
        
        if (city1 < 0 || city1 >= numCities || city2 < 0 || city2 >= numCities) {
            //cerr << "Ошибка: недопустимые индексы городов: " << city1 << ", " << city2 << endl;
            return 1;
        }
        return adjMatrix[city1][city2];
    }

    void removeRoad(int city1, int city2) {
        if (city1 < numCities && city2 < numCities) {
            adjMatrix[city1][city2] = 0;
            //adjMatrix[city2][city1] = 0;
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

    void loadFromFile(const string& filename) {
        ifstream input(filename);
        if (!input) {
            cout << "Ошибка открытия файла!" << endl;
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
};


vector<int> createChrom(int numCities, const vector<vector<int>>& population) {
    vector<int> chromosome(numCities);
    for (int i = 0; i < numCities; i++)
    {
        chromosome[i] = i;
    }
    random_shuffle(chromosome.begin(), chromosome.end());
    for (const auto& popul : population) {
        if (popul == chromosome) {
            return createChrom(numCities, population);
        }
    }
    return chromosome;
}

double calculateFitness(Graph& graph, const vector<int>& chromo) {
    double totalDistance = 0;
    for (size_t i = 0; i < chromo.size(); i++)
    {
        int city1 = chromo[i];
        int city2 = chromo[(i + 1) % chromo.size()];
        totalDistance += graph.getDistance(city1, city2);
    }
    return totalDistance;
}

void mutate(vector<int>& chromosome) {
    int index1 = rand() % chromosome.size();
    int index2 = rand() % chromosome.size();
        cout << "Мутация: меняем элементы " << index1 << " и " << index2 << endl;
    cout << "Перед мутацией: ";
    for (int city : chromosome) {
        cout << city + 1 << " ";
    }
    cout << endl;

    swap(chromosome[index1], chromosome[index2]);

    cout << "После мутации: ";
    for (int city : chromosome) {
        cout << city + 1 << " ";
    }   
    cout << endl;
}

void removeDuplicates(vector<vector<int>>& population) {
    set<vector<int>> uniqueIndividuals(population.begin(), population.end());
    population.assign(uniqueIndividuals.begin(), uniqueIndividuals.end());
}

vector<int> crossover(const vector<int>& parent1, const vector<int>& parent2) {
    int size = parent1.size();
    vector<int> child(size, -1);
    vector<bool> taken(size, false);

    for (int i = 0; i < size / 2; i++) {
        child[i] = parent1[i];
        taken[parent1[i]] = true;
    }

    vector<int> remaining;
    for (int i = 0; i < size; i++) {
        if (!taken[parent2[i]]) {
            remaining.push_back(parent2[i]);
        }
    }

    random_shuffle(remaining.begin(), remaining.end());

    int j = 0;
    for (int i = size / 2; i < size; i++) {
        child[i] = remaining[j++];
    }

    return child;
}

void geneticAlg(Graph& graph, int populationSize, int generations, float mutationRate, int countCrossing) {
    vector<vector<int>> population(populationSize);
    for (int i = 0; i < populationSize; i++) {
        population[i] = createChrom(graph.numCities, population); 
    }

    for (int generation = 0; generation < generations; generation++) {
        sort(population.begin(), population.end(), [&graph](const vector<int>& a, const vector<int>& b) {
            return calculateFitness(graph, a) < calculateFitness(graph, b);
            });

        cout << "Итерация " << generation + 1 << ": ";
        cout << "Популяция после " << generation + 1 << " итерации:\n";
        for (const auto& chromo : population) {
            for (int city : chromo) {
                cout << city + 1 << " ";
            }
            cout << " | Длина: " << calculateFitness(graph, chromo) << endl;
        }
        cout << "Минимальный маршрут: ";
        for (int city : population[0]) {
            cout << city + 1 << " ";
        }
        cout << " | Длина маршрута: " << calculateFitness(graph, population[0]) << endl;

        vector<vector<int>> newPopulation;

        for (int i = 0; i < populationSize / 2; i++) {
            newPopulation.push_back(population[i]);
        }

        while (newPopulation.size() < populationSize && newPopulation.size() < countCrossing + populationSize / 2) {
            vector<int> parent1 = population[rand() % populationSize];
            vector<int> parent2 = population[rand() % populationSize];
            cout << "Выбор родителей: ";
            for (int city : parent1) cout << city + 1 << " ";
            cout << "и ";
            for (int city : parent2) cout << city + 1 << " ";
            cout << endl;

            vector<int> child = crossover(parent1, parent2);

            cout << "Созданный потомок: ";
            for (int city : child) cout << city + 1 << " ";
            cout << endl;

            if ((rand() % 100) < (mutationRate * 100)) {
                mutate(child);
            }

            newPopulation.push_back(child);
        }

        removeDuplicates(newPopulation);

        while (newPopulation.size() < populationSize) {
            newPopulation.push_back(population[rand() % populationSize]);
        }

        population = newPopulation;
    }

    sort(population.begin(), population.end(), [&graph](const vector<int>& a, const vector<int>& b) {
        return calculateFitness(graph, a) < calculateFitness(graph, b);
        });

    cout << "Лучший путь: ";
    for (int city : population[0]) {
        cout << city + 1 << " ";
    }
    cout << endl;
    cout << "Длина пути: " << calculateFitness(graph, population[0]) << endl;
}


int main()
{
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int countCities, population, countCrossing, iteration;
    float chanceOfMutation = 2;

    cout << "Введите кол-во городов: ";
    cin >> countCities;

    Graph graph(countCities);


    int choice;
    while (true) {
        cout << "\n1. Загрузить граф из файла\n2. Добавить город\n3. Удалить город\n4. Добавить дорогу\n5. Удалить дорогу\n6. Показать граф\n0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 0) break;

        switch(choice) {

        case 1: {
            string filename;
            cout << "Введите имя файла: ";
            cin >> filename;
            graph.loadFromFile(filename);
            break;
        }
        case 2:
            graph.addCity();
            cout << "Город добавлен\n";
            break;

        case 3:
            int city2;
            cout << "Введите номер города для удаления: ";
            cin >> city2;
            city2--;
            graph.removeCity(city2);
            cout << "Город удалён\n";
            break;

        case 4:
            int city31, city32, distance3;
            cout << "Введите номера городов и расстояние: ";
            cin >> city31 >> city32 >> distance3;
            city31--;
            city32--;
            graph.addRoad(city31, city32, distance3);
            cout << "Дорога добавлена\n";
            break;

        case 5:
            int city41, city42;
            cout << "Введите номера городов для удаления дороги: ";
            cin >> city41 >> city42;
            city41--;
            city42--;
            graph.removeRoad(city41, city42);
            cout << "Дорога удалена\n";
            break;

        case 6:
            graph.display();
            break;

        default:
            cout << "Некорректный выбор!\n";
        }
    }

    //population = countCities % 10;
    //cout << "\nИзначальный размер популяции: " << population << '\n';
    //cout << "\nВведите кол-во скрещиваний: ";
    //cin >> countCrossing;
    //
    //cout << "\nКол-во потомков при скрещиваниие: " << MAX_CHILD;
    //
    //cout << "\nВведите показатель мутации(шанс, что она произойдет) ";
    //while (true) {
    //    cin >> chanceOfMutation;
    //    if (chanceOfMutation > 0.0 && chanceOfMutation < 1.0) break;
    //    cout << "\nШанс мутации должен быть в диапазоне от (0,1): ";
    //}
    //
    //cout << "\nВведите кол-во эволюций(сколько итераций надо сделать): ";
    //cin >> iteration;

    //geneticAlg(graph, population, iteration, chanceOfMutation);
    geneticAlg(graph, 5, 200, 0.4f, 3);

    return 0;
}