#include <iostream>
#include <vector>
using namespace std;

vector<int> Find(vector<int> a) 
{
    int n = a.size();
    int* prev = new int[n-1];
    int* current = new int[n-1];
    int answer = current[0], pos = 0;


    for (int i = 0; i < n; i++)
    {
        current[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && current[j] + 1 > current[i]) 
            {
                current[i] = current[j] + 1;
                prev[i] = j;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (current[i] >= answer)
        {   
            pos = i;
            answer = current[i];
        }
    }
    cout << answer << endl;

    vector<int> path;
    while (pos != -1)
    {
        path.push_back(a[pos]);
        pos = prev[pos];
    }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << ' ';
        }
        return path;
}

int main()
{
    setlocale(0, "");

    int N;
    cout << "\nВведите длину последовательности: ";
    cin >> N;
    vector<int> input(N);
    cout << "\nВводите элементы: ";
    for (int i = 0; i < N; i++)
    {   
        cin >> input[i];
    }
    Find(input);


    return 0;
}

