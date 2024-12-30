#include <iostream>
using namespace std;

int e, d, n, phi;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int modInv(int e, int phi) {
    for (int x = 1; x < phi; x++) {
        if ((e * x) % phi == 1)
            return x;
    }
    return -1;
}


void generate_d(int p, int q) {
    n = p * q;
    phi = (p - 1) * (q - 1);

    e = 2;
    while (gcd(e, phi) != 1) e++;

    d = modInv(e, phi);
}

int encrypt(int msg, int e, int n) {
    int cipher = 1;
    for (int i = 0; i < e; i++) {
        cipher = (cipher * msg) % n;
    }
    return cipher;
}

int decrypt(int cipher, int d, int n) {
    int msg = 1;
    for (int i = 0; i < d; i++) {
        msg = (msg * cipher) % n;
    }
    return msg;
}

int main() {
    int p, q;

    cout << "Enter P (Only Prime): ";
    cin >> p;

    cout << "Enter Q (Only Prime): ";
    cin >> q;

    generate_d(p, q);

    cout << "Public Key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private Key (d, n): (" << d << ", " << n << ")" << endl;
    
    int msg;
    cout << "Enter a message to encrypt (as an integer): ";
    cin >> msg;

    int cipher = encrypt(msg, e, n);
    cout << "Encrypted message: " << cipher << endl;

    int decryptedMsg = decrypt(cipher, d, n);
    cout << "Decrypted message: " << decryptedMsg << endl;

    return 0;
}
