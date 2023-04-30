#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int modExp(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) // if exponent is odd
            result = (result * base) % modulus;
        base = (base * base) % modulus; // square the base
        exponent /= 2; // divide the exponent by 2
    }
    return result;
}

int main() {
    int p, q, n, phi, e, d, message, encrypted_message, decrypted_message;

    cout << "Enter the first prime number (p): ";
    cin >> p;
    cout << "Enter the second prime number (q): ";
    cin >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "Enter the message to be encrypted (less than " << n << "): ";
    cin >> message;

    // Choose e such that 1 < e < phi and gcd(e, phi) = 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }
    cout<<"value of e is: "<<e<<endl;

    // Compute d such that d is the multiplicative inverse of e mod phi
    for (d = 1; d < phi; d++) {
        if ((e * d) % phi == 1)
            break;
    }

    // Encryption: C = M^e mod n
    encrypted_message = modExp(message, e, n);
    cout << "Encrypted message: " << encrypted_message << endl;

    // Decryption: M = C^d mod n
    decrypted_message = modExp(encrypted_message, d, n);
    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}