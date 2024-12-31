#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

struct MetaInfo {
    string name;
    string type;
    size_t size;
    size_t offset;
};

struct Data {
    unsigned short ushortL;
    short shortN;
};

void serialize(const string& filename, const Data& data, const vector<MetaInfo>& meta) {
    ofstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("ошибка открытия файла для чтения");
    }

    size_t metaCount = meta.size();
    file.write(reinterpret_cast<const char*>(&metaCount), sizeof(metaCount));

    for (const auto& info : meta) {
        size_t nameLen = info.name.size();
        size_t typeLen = info.type.size();

        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(info.name.c_str(), nameLen);

        file.write(reinterpret_cast<const char*>(&typeLen), sizeof(typeLen));
        file.write(info.type.c_str(), typeLen);

        file.write(reinterpret_cast<const char*>(&info.size), sizeof(info.size));
        file.write(reinterpret_cast<const char*>(&info.offset), sizeof(info.offset));
    }

    file.write(reinterpret_cast<const char*>(&data), sizeof(data));

    file.close();
}

int main() {
    setlocale(0, "");
    Data data = { 10, -55 };
    vector<MetaInfo> meta = {
        {"ushortL", "unsigned short", sizeof(data.ushortL), offsetof(Data, ushortL)},
        {"shortN", "short", sizeof(data.shortN), offsetof(Data, shortN)}
    };

    try {
        serialize("data.bin", data, meta);
        cout << "данные сериализованны" << endl;
    }
    catch (const exception& e) {
        cerr << "ошибка: " << e.what() << endl;
    }

    return 0;
}
