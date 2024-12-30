#include <iostream>
#include <openssl/rand.h>

using namespace std;

void generateKey(int keyLength, string algorithmName, string keyType)
{
    unsigned char key[64];       // Set a maximum key length (e.g., 64 bytes)
    if (keyLength > sizeof(key)) // sizeof - convert int to bytes/bits
    {
        cerr << "Key length exceeds maximum size of " << sizeof(key) << " bytes." << endl;
        return;
    }

    if (RAND_bytes(key, keyLength) != 1)
    {
        cerr << "Error generating " << keyType << " key for " << algorithmName << endl;
        return;
    }

    cout << algorithmName << " " << keyType << " Key (" << keyLength * 8 << " bits): ";
    for (int i = 0; i < keyLength; i++)
    {
        printf("%02x", key[i]);
    }
    cout << endl;
}

int main()
{
    int keyLength;
    string algorithmName, keyType;

    cout << "Enter the key type: ";
    cin >> keyType;

    cout << "Enter the algo name: ";
    cin >> algorithmName;

    if (keyType == "symmetric")
    {
        if (algorithmName == "des")
            keyLength = 8;
        if (algorithmName == "blowfish")
            keyLength = 16;
        if (algorithmName == "idea")
            keyLength = 16;
        if (algorithmName == "triple des")
            keyLength = 24;
        generateKey(keyLength, algorithmName, keyType);
    }
    else
    {
        cout << "Wrong";
    }

    return 0;
}
