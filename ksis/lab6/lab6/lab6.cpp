#include <iostream>


using namespace std;


bool CheckAdress(char* ip_) {
    int points = 0;
    int numbers = 0;
    char* buff;
    buff = new char[3];

    for (int i = 0; ip_[i] != '\0'; i++) {
        if (ip_[i] <= '9' && ip_[i] >= '0') {
            if (numbers > 3) return false;
            buff[numbers++] = ip_[i];
        }
        else {
            if (ip_[i] == '.') {
                if (atoi(buff) > 255) {
                    return false;
                }
                if (numbers == 0) {
                    return false;
                }
                numbers = 0;
                points++;
                delete[] buff;
                buff = new char[3];
            }
            else {
                return false;
            }
        }
    }
    if (points != 3) {
        return false;
    }
    if (numbers == 0 || numbers > 3) {
        return false;
    }
    return true;
}



unsigned long CharToLong(char* ip_) {
    unsigned long out = 0;
    char* buff = new char[3];
    for (int i = 0, j = 0, k = 0; ip_[i] != '\0'; i++, j++) {
        if (ip_[i] != '.') {
            buff[j] = ip_[i];
        }
        if (ip_[i] == '.' || ip_[i + 1] == '\0') {
            out <<= 8;
            if (atoi(buff) > 255) {
                return NULL;
            }
            out += (unsigned long)atoi(buff);
            k++;
            j = -1;
            delete[] buff;
            buff = new char[3];
        }
    }
    return out;
}

char* longToChar(unsigned long ip) {
    char* ipStr = new char[16];  // 16 символов для строки IP-адреса
    strcpy_s(ipStr, 16, "");  // Инициализация пустой строки

    for (int i = 3; i >= 0; --i) {  // Проходим по четырем байтам IP
        char octet[4];  // Массив для хранения октета (макс. 3 цифры + '\0')
        unsigned long part = (ip >> (i * 8)) & 0xFF;  // Извлекаем байт
        sprintf_s(octet, "%lu", part);  // Преобразуем байт в строку
        strcat_s(ipStr, 16, octet);  // Добавляем строку октета к IP
        if (i > 0) {
            strcat_s(ipStr, 16, ".");  // Добавляем точку между октетами
        }
    }

    return ipStr;
}


int main() {
    setlocale(LC_ALL, "ru");
    unsigned long ip, mask, host, subnet, broadcast;
    char* ip_, * mask_;
    bool flag = true;
    ip_ = new char[16];
    mask_ = new char[16];

    do {
        if (!flag) cout << "Неверно введен адрес!" << endl;
        cout << "IP: ";
        cin >> ip_;
    } while (!(flag = CheckAdress(ip_)));

    ip = CharToLong(ip_);
    flag = true;
    do {
        if (!flag) cout << "Неверное введена маска!" << endl;
        cout << "Маска: ";
        cin >> mask_;
    } while (!(flag = CheckAdress(mask_)));
    mask = CharToLong(mask_);

    host = ip & ~mask;
    subnet = ip & mask;
    broadcast = ip & mask | ~mask;

    char* ipp = new char[16];

    cout << "ID хоста: " << longToChar(host) << endl;
    cout << "ID подсети: " << longToChar(subnet) << endl;
    cout << "Broadcast адрес: " << longToChar(broadcast) << endl;

    return 0;
}
