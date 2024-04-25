#include "HashTable.h"
using namespace std;

HashTable::HashTable() {
    this->_size = 511;
    this->_hash_table = vector<pair<string, string>>(this->_size);
    for (vector<pair<string, string>>::iterator it = this->_hash_table.begin(); it != this->_hash_table.end(); it++)
        *it = make_pair("", "");
}

HashTable::HashTable(const HashTable& other) {
    this->_size = other._size;
    this->_hash_table = other._hash_table;
}

HashTable::HashTable(unsigned int count)
{
    this->_size = 511;
    this->_hash_table = std::vector<std::pair<std::string, std::string>>(this->_size);
    for (vector<pair<string, string>>::iterator it = this->_hash_table.begin(); it != this->_hash_table.end(); it++)
        *it = std::make_pair("", "");

    unsigned int size = this->_size >= count ? count : this->_size;
    for (unsigned int i = 0; i < size; i++) {
        string key = this->_random_string(rand() % 10 + 1);
        string value = this->_random_string(rand() % 50 + 1);
        this->insert(key, value);
    }

}

HashTable::~HashTable() {
    this->_hash_table.clear();
}

HashTable& HashTable::operator =(const HashTable& other) {
    this->_hash_table.clear();

    this->_size = other._size;
    this->_hash_table = other._hash_table;
    return *this;
}

void HashTable::insert(string key, string value) {
    unsigned int id = this->_hash(key);
    if (this->_hash_table[id].first == "" && this->_hash_table[id].second == "") {
        this->_hash_table[id] = std::make_pair(key, value);
        return;
    }
    for (; id < this->_hash_table.size(); id++)
        if (this->_hash_table[id].first == "" && this->_hash_table[id].second == "") {
            this->_hash_table[id] = make_pair(key, value);
            return;
        }
    throw SizeLimitException();
}

std::string HashTable::search(string key) {
    unsigned int id = this->_hash(key);
    if (this->_hash_table[id].first != "" && this->_hash_table[id].second != "") {
        for (; id < this->_hash_table.size(); id++)
            if (this->_hash_table[id].first == key)
                return this->_hash_table[id].second;
    }

    throw KeyErrorException();
}

bool HashTable::contains(string value) {
    for (vector<std::pair<string, string>>::iterator it = this->_hash_table.begin(); it != this->_hash_table.end(); it++) {
        if (it->second == value)
            return true;
    }
    return false;
}

void HashTable::insert_or_assign(string key, string value)
{
    unsigned int id = this->_hash(key);
    if (this->_hash_table[id].first != "" && this->_hash_table[id].second != "") {
        this->_hash_table[id] = std::make_pair("", "");
        this->insert(key, value);
        return;
    }
    this->insert(key, value);
}

void HashTable::erase(string key) {
    unsigned int id = this->_hash(key);
    if (this->_hash_table[id].first == "" && this->_hash_table[id].second == "") {
        return;
    }
    for (; id < this->_hash_table.size(); id++)
        if (this->_hash_table[id].first == key) {
            this->_hash_table[id] = std::make_pair("", "");
            return;
        }

}

void HashTable::print() {
    unsigned int current_id = 0;
    for (std::vector<std::pair<std::string, std::string>>::iterator it = this->_hash_table.begin(); it != this->_hash_table.end(); it++) {
        if (it->first != "" && it->second != "") {
            cout << "HASH: " << current_id << ":: ";
            cout << it->first << "-->" << it->second << "   ";
            cout << std::endl;
        }
        current_id++;
    }
}

int HashTable::count(std::string key)
{
    unsigned int id = this->_hash(key);
    if (this->_hash_table[id].first == "" && this->_hash_table[id].second == "") {
        return 0;
    }
    for (; id < this->_hash_table.size(); id++)
        if (this->_hash_table[id].first == key) {
            this->_hash_table[id] = std::make_pair("", "");
            return 1;
        }
    return 0;
}

unsigned int HashTable::_hash(std::string value) {
    unsigned int h = 0, a = 127;
    for (unsigned int ind = 0; ind < value.size(); ind++)
        h = (a * h + (unsigned int)(value[ind])) % this->_size;
    return h;
}

std::string HashTable::_random_string(unsigned int size)
{
    char symbols[30] = "abcdefghijklmnopqrstuvwxyz _.";
    std::string value = "";
    for (unsigned int i = 0; i < size; i++) {
        char c = symbols[rand() % 30];
        value += c;
    }
    return value;
}
