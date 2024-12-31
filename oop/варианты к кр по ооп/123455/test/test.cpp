
#include <iostream>
#include <ctime>
using namespace std;

const int N = 5, M = 5;

void ex1(int arr[N][M]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] < 0)
                sum += arr[i][j];
        }
    }

    cout << "\nСумма всех отрицательных элементов: " << sum;
} 

void ex3(int arr[N][N]) {
    unsigned long long int multiply = 1;
    int buf = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < buf; j++) {
            multiply *= arr[i][j];
        }
            buf--;
    }

    cout << "\nПроизведение элементов, расположенных  в верхней треугольной матрице, расположенной выше побочной диагонали , включая саму побочную диагональ: " << multiply;
}

void ex5(string str) {
    string buf = str.substr(2,7);
    reverse(buf.begin(), buf.end());
    str.replace(2, 7, buf);
    
   
    cout << "\nИтоговое слово:" << str;
}

int main()
{
    srand(time(NULL));
    setlocale(0, "");
    

    int array[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            array[i][j] = rand() % 200 - 100;
            cout << array[i][j] << '\t';
        }
        cout << '\n';
    }

    ex1(array);
    
    int matrix[N][N];

    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 3+ 1;
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }

    ex3(matrix);

    string str = "абвгдеёжзийк";

    ex5(str);



    return 0;






}
