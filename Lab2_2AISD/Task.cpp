#include <iostream>
#include "HashTable.h"

unsigned int hash8(std::string message) {
    unsigned hash = message.size() % 256;
    for (unsigned int i = 0; i < message.size(); i++)
        hash = 255 - (hash + (unsigned int)message[i]) % 256;
    return hash;
}


bool compare(std::string str1, std::string str2) {
    return hash8(str1) == hash8(str2);
}

int main() {


    std::string message1, message2;
    std::cout << "Enter string: ";
    std::cin >> message1;
    std::cout << "For string (" << message1 << ") Hash = " << hash8(message1) << std::endl;

    std::cout << "Enter string: ";
    std::cin >> message2;
    std::cout << "For string (" << message2 << ") Hash = " << hash8(message2) << std::endl;

    std::cout << "Compare " << compare(message1, message2) << std::endl;




    /*HashTable hash_table;

    hash_table.insert("first", "first");
    hash_table.insert("second", "second");

    hash_table.print();
    std::cout << hash_table.search("first") << std::endl;
    std::cout << hash_table.search("second") << std::endl;

    hash_table.erase("first");
    hash_table.erase("first");

    hash_table.print();*/

}