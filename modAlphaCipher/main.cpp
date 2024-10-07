#include <iostream>
#include "modAlphaCipher.h"
using namespace std;
void check(const string& Text, const string& key, const bool destructCipherText=false)
{ 
	try {

		string cipherText;
		string decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); // зашифровывание
		if (destructCipherText) // надо "портить"?
			cipherText.front() = tolower(cipherText.front());
		decryptedText = cipher.decrypt(cipherText); // расшифровывание
		cout<<"key="<<key<<endl;
		cout<<Text<<endl;
		cout<<cipherText<<endl;
		cout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}

int main(int argc, char **argv)
{ 
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","SIMPLE");
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","EXAMPLE");
	check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","ABCD");
	return 0;
}