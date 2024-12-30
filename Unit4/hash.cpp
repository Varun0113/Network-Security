#include <iostream>
#include <string>

using namespace std;

// RS Hash Function
unsigned int RSHash(string str) { //unsigned int used for non negative numbers
    unsigned int b = 378551;
    unsigned int a = 63689; //constants
    unsigned int hash = 0;

    for (int i = 0; i < str.length(); i++) {
        hash = hash * a + str[i];
        a = a * b;
    }
    return hash;
}

// JS Hash Function
unsigned int JSHash(string str) {
    unsigned int hash = 1315423911;

    for (int i = 0; i < str.length(); i++) {
        hash ^= ((hash << 5) + str[i] + (hash >> 2)); //Ek baar hash left side 5 baar shift hoga fir str[I] k sath + fir ek baar hash right side 2 baar shift hoga and XOR(^) used to flip the bit
    }
    return hash;
}

// BKDR Hash Function
unsigned int BKDRHash(string str) {
    unsigned int seed = 131; // 31, 131, 1313, 13131, 131313, etc.
    unsigned int hash = 0;

    for (int i = 0; i < str.length(); i++) {
        hash = hash * seed + str[i];
    }
    return hash;
}

// SDBM Hash Function
unsigned int SDBMHash(string str) {
    unsigned int hash = 0;

    for (int i = 0; i < str.length(); i++) {
        hash = str[i] + (hash << 6) + (hash << 16) - hash;
    }
    return hash;
}

// DJB Hash Function
unsigned int DJBHash(string str) {
    unsigned int hash = 5381;

    for (int i = 0; i < str.length(); i++) {
        hash = ((hash << 5) + hash) + str[i]; 
    }
    return hash;
}

int main() {
    string input;

    cout << "Enter a string to hash: ";
    getline(cin, input);

    cout << "RSHash: " << RSHash(input) << endl;
    cout << "JSHash: " << JSHash(input) << endl;
    cout << "BKDRHash: " << BKDRHash(input) << endl;
    cout << "SDBMHash: " << SDBMHash(input) << endl;
    cout << "DJBHash: " << DJBHash(input) << endl;

    return 0;
}
