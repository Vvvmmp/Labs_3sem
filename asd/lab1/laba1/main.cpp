#include <iostream>

using namespace std;

void hanoi(int, int, int, int);

int main() {
    setlocale(LC_ALL, "ru");
    int N; // ���������� �����
    int k; // �������� �������� �� 3
    int i = 1;
    cout << "������� ���-�� ��������, � ����� ��������, �� ������� ������ �����������: ";
    cin >> N;
    cin >> k;
    int temp = 6 - k - i;
    if ((k == 2 || k == 3) && N >= 1) {
        hanoi(N, i, k, temp);
    
    }
    else {
        cout << "\n������������ ����!\n";
    }
    return 0;
}

void hanoi(int N, int i, int k, int temp) {
    if (N == 1) {
        cout << "���������� ���� �" << N << " � " << i << " ������� �� " << k << endl;
    }
    else {
        hanoi(N - 1, i, temp, k);
        cout << "���������� ���� �" << N << " � " << i << " ������� �� " << k << endl;
        hanoi(N - 1, temp, k, i);
    }
}
