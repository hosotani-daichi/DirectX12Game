#pragma once
#include <string>

//文字コードユーティリティー
namespace StringUtility {
	//stringをwstringに変換する
	std::wstring ConverString(const std::string& str);
	//wstringをstringに変換する
	std::string ConverString(const std::wstring& str);
}

class StringUtility
{
};

