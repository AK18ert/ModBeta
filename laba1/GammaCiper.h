#pragma once
#include <string>
class GammaCipher
{
	private:
		int key;
	public:
		GammaCipher() = delete;
		GammaCipher(int key);
		std::wstring encrypt(const std::wstring& text);
		std::wstring decrypt(const std::wstring& encrypted_text);
};