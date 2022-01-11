#define _CRT_SECURE_NO_WARNINGS
#include "Parser.h"

#include <fstream>
#include <iostream>
#include <string.h>
#include <boost/range/adaptor/reversed.hpp>



Parser::Parser(std::string InputFile, std::string OutputFile)
  : m_InputFile(InputFile), m_OutputFile(OutputFile) {
}

void Parser::GetData() {
  std::ifstream data;
  data.open(m_InputFile);

  std::string s;

  if (data.is_open()) {
    while (!data.eof()) {
      std::getline(data, s);

      auto info = split_string(s);
      if (!info.empty()) {
        m_info.push_back(info);
      }
    }
    data.close();
  } 
  else {
    std::cerr << "Can't open file.";
  }
}

std::vector<std::string> Parser::split_string(std::string s) {
  std::vector<std::string> result;
  char* pTempStr = _strdup(s.c_str());
  char* pWord = strtok(pTempStr, m_delim);
  while (pWord != NULL) {
    result.push_back(pWord);
    pWord = strtok(NULL, m_delim);
  }
  free(pTempStr);

  return result;
}


std::string Parser::GetMonth(std::string YyyyMmDd) {
  std::vector<std::string> MonthName{
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"
  };
  std::string ToReturn;

  int month = std::stoi(YyyyMmDd.substr(5, 2));
  if (month > 0) {
    ToReturn = MonthName[month - 1] + " " + YyyyMmDd.substr(0, 4);
  }
  else {
    std::cerr << "Incorrect value of month";
  }
  return ToReturn;
}
 
void Parser::MakeData() {
  m_result["Name"]["Month"] = "Total hours";
  int counter = 1;
  auto iter = *(m_info.begin() + 1);
  bool toContinue = counter < m_info.size();
  while (toContinue) {
    auto& name = iter[0];
    std::string month = GetMonth(iter[6]);

    m_result[name][month] = std::to_string((int)atoi(iter[7].c_str()) + (int)(!m_result[name][month].empty() ? stoi(m_result[name][month]) : 0));

    counter += 1;
    if (counter < m_info.size()) {
      iter = m_info[counter];
    }
    else {
      toContinue = false;
    }
  }
}

void Parser::StoreToFile() {
  std::ofstream file;
  file.open(m_OutputFile);

  if (file.is_open()) {
    for (auto const& iter : boost::adaptors::reverse(m_result)) {
      file << iter.first << ";";
      auto const& internal_map = iter.second;
      for (auto const& iter2 : internal_map) {
          file << iter2.first << ";" << iter2.second;
      }
      file << std::endl;
    }
    file.close();
  }
}