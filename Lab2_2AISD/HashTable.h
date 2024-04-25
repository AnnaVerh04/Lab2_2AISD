#include <exception>
#include <random>
#include <iostream>
#include <list>
#include <vector>

class KeyErrorException : public std::exception
{};

class SizeLimitException : public std::exception
{};


class HashTable
{
public:
    HashTable();
    HashTable(const HashTable& other);
    HashTable(unsigned int);
    ~HashTable();

    HashTable& operator = (const HashTable& other);
    void insert(std::string, std::string);
    std::string search(std::string);
    bool contains(std::string);
    void insert_or_assign(std::string, std::string);
    void erase(std::string);
    void print();
    int count(std::string);

private:
    unsigned int _hash(std::string);
    std::string _random_string(unsigned int);

private:
    unsigned int _size;
    std::vector<std::pair<std::string, std::string>> _hash_table;
};