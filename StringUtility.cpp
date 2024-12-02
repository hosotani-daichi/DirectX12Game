#include "StringUtility.h"

namespace StringUtility {
	//stringをwstringに変換する
	std::wstring ConverString(const std::string& str);
	//wstringをstringに変換する
	std::string ConverString(const std::wstring& str);

}

std::wstring StringUtility::ConverString(const std::string& str)
{
    return std::wstring();
}

std::string StringUtility::ConverString(const std::wstring& str)
{
    return std::string();
}
