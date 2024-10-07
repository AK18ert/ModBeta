#include "modAlphaCipher.h"
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>


using namespace std;

/*
bool isGood(const wstring& s)
{
    for(auto c : s) {
        if(!iswalpha(c) || !iswupper(c)) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    wstring key;
    wstring text;
    unsigned op;

    wcout << L"Введите ключ: ";
    wcin >> key;

    if(!isGood(key)) {
        wcerr << L"Ключ недействителен\n";
        return 1;
    }

    wcout << L"Ключ загружен\n";
    modAlphaCipher cipher(key);

    do {
        wcout << L"Шифр готов. Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать): ";
        wcin >> op;

        if(op > 2) {
            cout << "Неправильная операция\n";
        } else if(op > 0) {
            cout << "Введите текст: ";
            wcin >> text;

            if(isGood(text)) {
                if(op == 1) {
                    wcout << L"Зашифрованный текст: " << endl;
                    wcout << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << "Operation aborted: неправильный текст\n";
            }
        }
    } while(op != 0);    setlocale(LC_ALL, "ru_RU.UTF-8");


    return 0;
}
*/

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{ 
	try {
		setlocale(LC_ALL, "ru_RU.UTF-8");
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); // зашифровывание
		if (destructCipherText) // надо "портить"?
			cipherText.front() = tolower(cipherText.front()); 
		decryptedText = cipher.decrypt(cipherText); // расшифровывание
		wcout<<"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}

int main(int argc, char **argv)
{ 
	setlocale(LC_ALL, "ru_RU.UTF-8");
	check(L"МАМАМЫЛАРАМУ", L"КОЛЯ");
	return 0;
}