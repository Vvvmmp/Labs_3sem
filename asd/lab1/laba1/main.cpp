#include <iostream>

using namespace std;

void hanoi(int, int, int, int);

int main() {
    setlocale(LC_ALL, "ru");
    int N; // Количество колец
    int k; // Конечный стержень из 3
    int i = 1;
    cout << "Введите кол-во стержней, а после стержень, на который хотите переместить: ";
    cin >> N;
    cin >> k;
    int temp = 6 - k - i;
    if ((k == 2 || k == 3) && N >= 1) {
        hanoi(N, i, k, temp);
    
    }
    else {
        cout << "\nНекорректный ввод!\n";
    }
    return 0;
}

void hanoi(int N, int i, int k, int temp) {
    if (N == 1) {
        cout << "Перемещаем диск №" << N << " с " << i << " стержня на " << k << endl;
    }
    else {
        hanoi(N - 1, i, temp, k);
        cout << "Перемещаем диск №" << N << " с " << i << " стержня на " << k << endl;
        hanoi(N - 1, temp, k, i);
    }
}
