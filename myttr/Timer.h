#include <iostream>
#include <chrono>

class Timer {
public:

  Timer();
  void StartTimer();
  void StopTimer();
  long GetTime()const;

private:
  std::chrono::high_resolution_clock::time_point m_StartTime;
  std::chrono::high_resolution_clock::time_point m_EndTime;
};

