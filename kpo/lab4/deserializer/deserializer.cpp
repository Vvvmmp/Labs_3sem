#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>

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

void deserialize(const string& filename, Data& data, vector<MetaInfo>& meta) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("ошибка открытия файла для чтения");
    }

    size_t metaCount;
    file.read(reinterpret_cast<char*>(&metaCount), sizeof(metaCount));

    meta.clear();
    for (size_t i = 0; i < metaCount; ++i) {
        size_t nameLen, typeLen;

        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        string name(nameLen, '\0');
        file.read(&name[0], nameLen);

        file.read(reinterpret_cast<char*>(&typeLen), sizeof(typeLen));
        string type(typeLen, '\0');
        file.read(&type[0], typeLen);

        size_t size, offset;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        file.read(reinterpret_cast<char*>(&offset), sizeof(offset));

        meta.push_back({ name, type, size, offset });
    }

    file.read(reinterpret_cast<char*>(&data), sizeof(data));

    file.close();
}

void generateAsm(const string& filename, const Data& data, const vector<MetaInfo>& meta) {
    ofstream file(filename);
    if (!file) {
        throw runtime_error("Ошибка открытия файла для записи");
    }

    file << ".586\n";
    file << ".model flat, stdcall\n";
    file << "includelib kernel32.lib\n";
    file << "ExitProcess PROTO :DWORD\n";
    file << "MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD\n\n";

    file << ".STACK 4096\n\n";

    file << ".CONST\n";
    file << "button DD 0\n\n";

    file << ".DATA\n";
    file << "HW DD 0\n";
    file << "resultString DB 256 DUP(?), 0\n";
    file << "window BYTE \"Окно\", 0\n";

    for (const auto& info : meta) {
        file << info.name << " ";
        if (info.type == "unsigned short") {
            file << "dw " << data.ushortL << "\n";
        }
        else if (info.type == "short") {
            file << "dw " << data.shortN << "\n";
        }
    }

    file << "\n.CODE\n";
    file << "main PROC\n";
    file << "\tLEA EDI, resultString\n";

    for (size_t i = 0; i < meta.size(); ++i) {
        const auto& info = meta[i];
        file << "\mov AX, " << info.name << "\n";
        file << "\call ConvertToDecimal\n";

        if (i < meta.size() - 1) {
            file << "\mov BYTE PTR [EDI], ' '\n";
            file << "\inc EDI\n";
        }
    }

    file << "\mov BYTE PTR [EDI], 0\n";
    file << "INVOKE MessageBoxA, HW, OFFSET resultString, OFFSET window, button\n";
    file << "INVOKE ExitProcess, 0\n";
    file << "main ENDP\n";

    file << "ConvertToDecimal PROC\n";
    file << "\tpush EAX\n";
    file << "\tpush EBX\n";
    file << "\tpush ECX\n";
    file << "\tpush EDX\n";

    file << "\tcmp AX, 0\n";
    file << "\tjge PositiveNumber\n";

    file << "\tneg AX\n";
    file << "\tmov BYTE PTR [EDI], '-'\n";
    file << "\tinc EDI\n";

    file << "PositiveNumber:\n";
    file << "\txor EBX, EBX\n";
    file << "\tmov BX, 10\n";
    file << "\txor ECX, ECX\n";

    file << "ConvertLoop:\n";
    file << "\txor EDX, EDX\n";
    file << "\tdiv BX\n";
    file << "\tpush DX\n";
    file << "\tinc ECX\n";
    file << "\ttest AX, AX\n";
    file << "\tjnz ConvertLoop\n";

    file << "RestoreDigits:\n";
    file << "\tpop DX\n";
    file << "\tadd DL, '0'\n";
    file << "\tmov BYTE PTR [EDI], DL\n";
    file << "\tinc EDI\n";
    file << "\tloop RestoreDigits\n";

    file << "\tpop EDX\n";
    file << "\tpop ECX\n";
    file << "\tpop EBX\n";
    file << "\tpop EAX\n";
    file << "\tRET\n";
    file << "ConvertToDecimal ENDP\n";

    file << "end main\n";

    file.close();
}



int main() {
    setlocale(0, "");
    Data data;
    vector<MetaInfo> meta;

       
    try {

        deserialize("../serializer/data.bin", data, meta);
        cout << "Сериализация прошла успешно" << endl;
        cout << data.shortN << endl;
        cout << data.ushortL << endl;
        generateAsm("../assembler/data.asm", data, meta);
        cout << "Преобразовано в asm" << endl;
    }
    catch (const exception& e) {
        cerr << "ошибка: " << e.what() << endl;
    }

    return 0;
}
