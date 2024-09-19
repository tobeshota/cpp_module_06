#include "Utils.hpp"

// 小数部が0に近いかを確認
bool isFractionalPartZero(float f) {
  return std::fabs(f - static_cast<int>(f)) < 1e-6;
}

// 小数部が0に近いかを確認
bool isFractionalPartZero(double d) {
  return std::fabs(d - static_cast<int>(d)) < 1e-6;
}

// 行からNAME=の後にある値を抽出する関数
static std::string extractNameValue(const std::string& line, std::size_t pos) {
  // 空白，タブ，=をスキップ
  while (pos < line.length() &&
         (line[pos] == ' ' || line[pos] == '\t' || line[pos] == '='))
    ++pos;

  // 値部分を抽出
  std::string name_value;
  while (pos < line.length() && !isspace(line[pos])) {
    name_value += line[pos];
    ++pos;
  }

  return name_value;
}

// Makefileを開き、NAME=が含まれる行を探し、その後の文字列を返す関数
std::string getExecutableNameFromMakefile(const std::string& makefilePath) {
  std::ifstream makefile(makefilePath.c_str());
  if (!makefile.is_open()) {
    std::cerr << "Makefileが開けませんでした。" << std::endl;
    return "";
  }

  // ファイルの各行を読み込み、NAME=の行を探す
  std::string line;
  while (std::getline(makefile, line)) {
    std::size_t pos = line.find("NAME");
    if (pos != std::string::npos) {
      // NAME=の位置を基準にして、その値を取得して返す
      return extractNameValue(line, pos + 4);
    }
  }

  // 見つからなければ空文字を返す
  return "";
}
