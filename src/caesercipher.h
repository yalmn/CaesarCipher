/* caesercipher.h */\
#include <iostream>
#include <string>

class CaesarCipher
{
    private:
    int shift;
    public:
    CaesarCipher(int shift);
    std::string encrypt(const std::string& text);
    std::string decrypt(const std::string& text);
};