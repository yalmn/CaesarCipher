/* caesercipher.cpp */
#include "caesercipher.h"

CaesarCipher::CaesarCipher(int shift) :
    shift(shift % 26) {}

std::string CaesarCipher::encrypt(const std::string& text)
{
    std::string result = text;
        for (size_t i = 0; i < text.length(); ++i) {
            if (isalpha(text[i])) {
                char base = islower(text[i]) ? 'a' : 'A';
                result[i] = (text[i] - base + shift) % 26 + base;
            }
        }
        return result;
}

std::string CaesarCipher::decrypt(const std::string& text)
{
    std::string result = text;
        for (size_t i = 0; i < text.length(); ++i) {
            if (isalpha(text[i])) {
                char base = islower(text[i]) ? 'a' : 'A';
                result[i] = (text[i] - base - shift + 26) % 26 + base;
            }
        }
        return result;
}
 
int main(int argc, char const *argv[])
{
    int shift;
    std::string text;
    char choice;

    std::cout << "Enter the shift value: ";
    std::cin >> shift;
    CaesarCipher cipher(shift);

    std::cout << "Enter the text: ";
    std::cin.ignore();
    std::getline(std::cin, text);

    std::cout << "Encrypt or Decrypt (e/d): ";
    std::cin >> choice;

    if (choice == 'e' || choice == 'E') {
        std::string encrypted = cipher.encrypt(text);
        std::cout << "Encrypted text: " << encrypted << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        std::string decrypted = cipher.decrypt(text);
        std::cout << "Decrypted text: " << decrypted << std::endl;
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
