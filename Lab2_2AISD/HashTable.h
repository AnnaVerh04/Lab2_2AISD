#include <iostream>
#include <string>

template <typename K, typename T>
class MyUnorderedMap {
private:
    static const int TABLE_SIZE = 100;
    struct Node {
        K key;
        T value;
        bool empty;
    };
    Node table[TABLE_SIZE];

public:

    MyUnorderedMap() {                           //конструктор по умолчанию
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i].empty = true;
        }
    }

    MyUnorderedMap(const MyUnorderedMap& other) {  //конструктор копирования
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = other.table[i];
        }
    }

                                                 // Оператор присваивания
    MyUnorderedMap& operator=(const MyUnorderedMap& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = other.table[i];
        }

        return *this;
    }
};