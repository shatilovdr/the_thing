#ifndef STOPWATCH_HPP_
#define STOPWATCH_HPP_

#include <vector>
#include <chrono>

class Stopwatch {
 public:
  Stopwatch();
  Stopwatch(const Stopwatch& other)            = delete;
  Stopwatch& operator=(const Stopwatch& other) = delete;

  ~Stopwatch() = default;

  void start();
  void pause();
  void resume();
  void reset();
  void display() const;


 private:
  using timepoint = std::chrono::steady_clock::time_point;
  using seconds = std::chrono::seconds;

  bool                  isRunning_;
  seconds               totalDuration_;
  timepoint             startTime_;
  std::vector<seconds>  laps_;

};

std::ostream& operator<<(std::ostream& os, std::chrono::seconds& duration);

#endif