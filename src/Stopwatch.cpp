#include "Stopwatch.hpp"
#include <iomanip>
#include <iostream> //temporary

Stopwatch::Stopwatch() : isRunning_(false), totalDuration_{std::chrono::seconds(0)} {}

void Stopwatch::start() {
  if (isRunning_)
    return;
  isRunning_ = true;
  startTime_ = std::chrono::steady_clock::now();
}

void Stopwatch::pause() {
  if (!isRunning_)
    return;
  isRunning_ = false;
  auto currentDuration = std::chrono::steady_clock::now() - startTime_;
  laps_.push_back(std::chrono::duration_cast<seconds>(currentDuration));
  totalDuration_ += laps_.back();
}

void Stopwatch::resume() {
  start();
}

void Stopwatch::reset() {
  isRunning_ = false;
  totalDuration_ = std::chrono::seconds(0);;
  laps_.clear();
  start();
}

void Stopwatch::lap() {
  pause();
  resume();
}

void Stopwatch::display() const {
  seconds totalDuration = totalDuration_;
  if (isRunning_) {
    auto currentDuration = std::chrono::steady_clock::now() - startTime_;
    totalDuration += std::chrono::duration_cast<seconds>(currentDuration);
  }
  std::cout << totalDuration << '\n';
}

void Stopwatch::displayLaps() const {
  uint32_t i = 0;
  for (const seconds& lap : laps_)
    std::cout << ++i << ' ' << lap << '\n';
}

std::ostream& operator<<(std::ostream& out, const std::chrono::seconds& duration) {
  using rep = std::chrono::seconds::rep;
  constexpr rep SECONDS_PER_HOUR = 3600;
  constexpr rep SECONDS_PER_MINUTE = 60;

  rep seconds = duration.count();
  rep hours = seconds / SECONDS_PER_HOUR;
  seconds -= hours * SECONDS_PER_HOUR;
  rep minutes = seconds / SECONDS_PER_MINUTE;
  seconds -= minutes * SECONDS_PER_MINUTE;

  out << std::setfill('0') << std::setw(2) << hours << ":"
      << std::setw(2) << minutes << ":"
      << std::setw(2) << seconds;
  return out;
}
