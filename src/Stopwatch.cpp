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

void Stopwatch::display() const {
  seconds totalDuration = totalDuration_;
  if (isRunning_) {
    auto currentDuration = std::chrono::steady_clock::now() - startTime_;
    totalDuration += std::chrono::duration_cast<seconds>(currentDuration);
  }
  std::cout << totalDuration << '\n';
}

std::ostream& operator<<(std::ostream& out, std::chrono::seconds& duration) {
  std::chrono::hours hours = std::chrono::duration_cast<std::chrono::hours>(duration);
  duration -= hours;
  std::chrono::minutes minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
  duration -= minutes;

  out << std::setfill('0') << std::setw(2) << hours.count() << ":"
      << std::setw(2) << minutes.count() << ":"
      << std::setw(2) << duration.count();

  return out;
}
