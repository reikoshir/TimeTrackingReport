#include "Timer.h"


Timer::Timer() :m_StartTime() {};

void Timer::StartTimer() {
  m_StartTime = std::chrono::high_resolution_clock::now();
};

void Timer::StopTimer() {
  m_EndTime = std::chrono::high_resolution_clock::now();
};


long Timer::GetTime()const {
  return std::chrono::duration_cast<std::chrono::nanoseconds>(m_EndTime - m_StartTime).count();
}
