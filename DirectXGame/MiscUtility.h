#pragma once
#include <string>

// string=>wstring文字列変換
std::wstring ConvertString(const std::string& str);
// wstring=>string文字列変換
std::string ConvertString(const std::wstring& str);