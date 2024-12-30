#include <iostream>
#include <openssl/rand.h>

using namespace std;

void generateKey(int keyLength, string algorithmName, string keyType) {
    unsigned char key[64];
    if (keyLength > sizeof(key)) {
        cerr << "Key length exceeds maximum size of " << sizeof(key) << " bytes." << endl;
        return;
    }
    
    if (!RAND_bytes(key, keyLength)) {
        cerr << "Error generating " << keyType << " key for " << algorithmName << endl;
        return;
    }
    
    cout << algorithmName << " " << keyType << " Key (" << keyLength * 8 << " bits): ";
    for (int i = 0; i < keyLength; i++) {
        printf("%02x", key[i]);
    }
    cout << endl;
}

int main() {
    int keyLength;
    string algorithmName, keyType;

    cout << "Enter the key type (symmetric or hmac): ";
    cin >> keyType;

    cout << "Enter the algorithm name: ";
    cin >> algorithmName;

    cout << "Enter the key length in bytes: ";
    cin >> keyLength;

    generateKey(keyLength, algorithmName, keyType);

    return 0;
}
