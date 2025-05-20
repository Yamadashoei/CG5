#pragma once

#include <string>

namespace KamataEngine {

struct FilePathSet {
	std::string directory;
	std::string fileName;
	std::string extension;
};

/// <summary>
/// マルチバイト文字列をワイド文字列に変換する
/// </summary>
/// <param name="str">マルチバイト文字列</param>
/// <returns>ワイド文字列</returns>
std::wstring ConvertStringMultiByteToWide(const std::string& str);

/// <summary>
/// ファイルパスを分解する
/// </summary>
/// <param name="filePath">ファイルパス</param>
FilePathSet SeparateFilePath(const std::string& filePath);

} // namespace KamataEngine
