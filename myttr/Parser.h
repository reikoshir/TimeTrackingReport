#pragma once
#include <vector>
#include <string>
#include <map>
#include <vector>


class Parser {
public:
  Parser(std::string InputFile, std::string OutputFile);
  void GetData();
  std::vector<std::string> split_string(std::string s);
  std::string GetMonth(std::string YyyyMmDd);
  void MakeData();
  void StoreToFile();

private:
  std::string m_InputFile;
  std::string m_OutputFile;
  const char* m_delim = ";,:'\n";
  std::vector<std::vector<std::string>> m_info;
  std::map<std::string, std::map<std::string, std::string>> m_result;
};
