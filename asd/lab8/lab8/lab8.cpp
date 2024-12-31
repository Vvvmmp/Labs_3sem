#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

struct product {
	string name;
	int price;
	int weight;
};

//struct kpd {
//	string productName;
//	double efficienly;
//};


//bool compareKpd(const kpd& a, const kpd& b) {
//	return a.efficienly > b.efficienly;
//}

int main() {
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, maxWeight = 35;
	cout << "Введите кол-во товаров: ";
	cin >> N;
	vector<product> products(N);
	//vector<kpd> efficiencies;
	//vector<product> resultProduct;
	for (int i = 0; i < N; i++)
	{	
		cout << "\n\t\t" << i + 1 << "\nВведите название товара: ";
		cin >> products[i].name;
		cout << "Введите вес товара: ";
		cin >> products[i].weight;
		cout << "Введите цену товара: ";
		cin >> products[i].price;
		//double efficient = static_cast<double>(products[i].price) / products[i].weight;
		//efficiencies.push_back({ products[i].name, efficient });
	}
	vector<vector<int>> mw(N + 1, vector<int>(maxWeight + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int w = 1; w <= maxWeight; w++)
		{
			if (products[i - 1].weight <= w) {
				mw[i][w] = max(mw[i - 1][w], mw[i - 1][w - products[i - 1].weight] + products[i - 1].price);
			}
			else {
				mw[i][w] = mw[i - 1][w];
			}
		}
	}

	vector<product> resultProduct;
	int w = maxWeight;
	for (int i = N; i > 0 && w > 0; i--) {
		if (mw[i][w] != mw[i - 1][w]) {
			resultProduct.push_back(products[i - 1]);
			w -= products[i - 1].weight;
		}
	}
	cout << "Максимальный вес рюкзака: " << maxWeight;
	cout << "\nИтоговый список товаров:\n";
	for (const auto& prod : resultProduct) {
		cout << "Название: " << prod.name
			<< ", Вес: " << prod.weight
			<< " кг, Цена: " << prod.price << " руб.\n";
	}

	return 0;
}