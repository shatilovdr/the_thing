#include <iostream>
#include "Stopwatch.hpp"

int main() {
  Stopwatch stopwatch;
  int choice;
  std::cout << sizeof(std::chrono::seconds) << '\n';
  while (true) {
      std::cout << "\n--- Stopwatch Menu ---\n";
      std::cout << "1. Start Stopwatch\n";
      std::cout << "2. Pause Stopwatch\n";
      std::cout << "3. Resume Stopwatch\n";
      std::cout << "4. Reset Stopwatch\n";
      std::cout << "5. Record Lap\n";
      std::cout << "6. Display Stopwatch\n";
      std::cout << "7. Display Laps\n";
      std::cout << "8. Exit\n";
      std::cout << "Enter your choice: ";
      std::cin >> choice;
      switch (choice) {
      case 1:
          stopwatch.start();
          break;
      case 2:
          stopwatch.pause();
          break;
      case 3:
          stopwatch.resume();
          break;
      case 4:
          stopwatch.reset();
          break;
      case 5:
          stopwatch.lap();
          break;
      case 6:
          stopwatch.display();
          break;
      case 7:
          stopwatch.displayLaps();
          break;
      case 8:
          std::cout << "Exiting program.\n";
          return 0;
      default:
          std::cout << "Invalid choice. Please try again.\n";
      }
  }

  return 0;
}
