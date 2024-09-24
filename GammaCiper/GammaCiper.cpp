#include "GammaCiper.h"
#include <iostream>
#include <locale>
#include <string>
using namespace std;
GammaCipher::GammaCipher(int key)
	: key(key)
{
}
	std::wstring GammaCipher::encrypt(const std::wstring& text)
{
	int rows;
	if(text.length() % key != 0) {
		rows = text.length() / key + 1;
	} else {
		rows = text.length() / key;
	}
	wchar_t Gamma[rows][key];
	int index = 0; 
	for(int i = 0; i < rows; i++) { 
		for(int j = 0; j < key; j++) { 
			if(index < text.length()) {
				Gamma[i][j] = text[index];
				index++;
			} else {
				Gamma[i][j] = L' ';
			}
		}
	}
	std::wstring encrypted_text;
	for(int i = key - 1; i >= 0; i--) {
		for(int j = 0; j < rows; j++) {
			encrypted_text += Gamma[j][i];
		}
	}
	return encrypted_text;
}
std::wstring GammaCipher::decrypt(const std::wstring& encrypted_text)
{
	int rows;
	if(encrypted_text.length() % key != 0) {
		rows = encrypted_text.length() / key + 1;
	} else {
		rows = encrypted_text.length() / key;
	}
	wchar_t Gamma[rows][key];
	int index = 0;
	for(int i = key - 1; i >= 0; i--) {
		for(int j = 0; j < rows; ++j) {
			if(index < encrypted_text.length()) {
				Gamma[j][i] = encrypted_text[index];
				index++;
			} else {
				Gamma[i][j] = L' ';
			}
		}
	}
	wstring decrypted_text;
	index = 0;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < key; j++) {
			decrypted_text += Gamma[i][j];
		}
	}
	return decrypted_text;
}