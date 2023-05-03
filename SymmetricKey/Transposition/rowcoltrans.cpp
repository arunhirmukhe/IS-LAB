#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string encrypt(const string& plaintext, int key) {
    int rows = ceil(static_cast<double>(plaintext.length()) / key);
    string ciphertext;

    for (int col = 0; col < key; ++col) {
        for (int row = 0; row < rows; ++row) {
            int index = row * key + col;
            if (index < plaintext.length()) {
                ciphertext += plaintext[index];
            }
        }
    }

    return ciphertext;
}

string decrypt(const std::string& ciphertext, int key) {
    int rows = ceil(static_cast<double>(ciphertext.length()) / key);
    string plaintext;

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < key; ++col) {
            int index = row + col * rows;
            if (index < ciphertext.length()) {
                plaintext += ciphertext[index];
            }
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    int key;

    cout << "Enter the plaintext: ";
    getline(std::cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string encrypted_text = encrypt(plaintext, key);
    cout << "Encrypted text: " << encrypted_text << std::endl;

    string decrypted_text = decrypt(encrypted_text, key);
    cout << "Decrypted text: " << decrypted_text << std::endl;

    return 0;
}
