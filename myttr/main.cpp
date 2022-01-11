#include <iostream>
#include <string>

#include "Timer.h"
#include "Parser.h"

int main() {
  std::string InputFile, OutputFile;

  std::cout << "Enter path to input file: ";
  std::cin >> InputFile;
  std::cout << "Enter path to outnput file: ";
  std::cin >> OutputFile;

  Timer timer;
  timer.StartTimer();
  Parser p(InputFile, OutputFile);
  p.GetData();
  p.MakeData();
  timer.StopTimer();
  p.StoreToFile();

  std::cout << "Parsed in " << timer.GetTime() << " nanoseconds." << std::endl;

  return 0;
}