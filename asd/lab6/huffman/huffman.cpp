#include <iostream>
#include <string>
#include <queue>
#include <Windows.h>
#include <unordered_map>
using namespace std;

struct Node
{
    unsigned char ch;
    int freq;
    Node* left, * right;
};

Node* getNode(unsigned char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct comp
{
    bool operator()(Node* l, Node* r)
    {
       // if (l->freq == r->freq) {
       //    return l->ch > r->ch; 
       //}
       // cout << "Сравнение: '" << l->ch << "' (freq: " << l->freq << ") и '" 
       //      << r->ch << "' (freq: " << r->freq << ")\n";
             
        return l->freq > r->freq; 
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str; 
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int& index, string str)
{
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        cout << root->ch; 
        return;
    }

    index++;

    if (index < str.size()) {
        if (str[index] == '0')
            decode(root->left, index, str);
        else
            decode(root->right, index, str);
    }
}

void buildHuffmanTree(string text)
{
    double totalChars = text.length();
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++; 
    }

    priority_queue<Node*, vector<Node*>, comp> pq;

    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr)); 
    }

    while (pq.size() > 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        int sum = left->freq + right->freq; 
        cout << "Объединение: '" << left->ch << "' и '" << right->ch 
             << "' с общей частотой " << sum << "\n";

        pq.push(getNode('\0', sum, left, right)); 
    }

    Node* root = pq.top(); 

    unordered_map<char, string> huffmanCode; 
    encode(root, "", huffmanCode);

    cout << "Символ\tЧастота\t В %\tКод\n";
    for (auto pair : huffmanCode) {
        double percentage = (freq[pair.first] / totalChars) * 100;
        cout << "   " << pair.first << "\t   " << freq[pair.first] << " \t";
        printf("%.2f", percentage);
        cout << "%\t" << pair.second << '\n';
    }

    cout << "\nИсходный текст:\n" << text << '\n';

    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch]; 
    }

    cout << "\nЗакодированное сообщение:\n" << str << '\n';

    int index = -1;
    cout << "\nРаскодированное сообщение: \n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
    cout << endl; 
}

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string text;
    getline(cin, text);
    buildHuffmanTree(text); 

    return 0;
}
