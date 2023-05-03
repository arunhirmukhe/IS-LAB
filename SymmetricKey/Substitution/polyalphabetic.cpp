#include <iostream>
#include <string>

using namespace std;

string polyalphabetic_cipher(string text, string key, bool encrypt) {
    string result = "";
    int key_index = 0;
    int sign = encrypt ? 1 : -1;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char shift = tolower(key[key_index]) - 'a';
            char new_char = ((c - base + sign * shift + 26) % 26) + base;
            result += new_char;
            key_index = (key_index + 1) % key.length();
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string plaintext = "Hello, world!";
    string key = "secret";
    string ciphertext = polyalphabetic_cipher(plaintext, key, true);
    string decrypted_text = polyalphabetic_cipher(ciphertext, key, false);
    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted text: " << decrypted_text << endl;
    return 0;
}
