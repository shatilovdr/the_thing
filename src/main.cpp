#include <iostream>
#include "Stopwatch.hpp"

int main() {
  Stopwatch stopwatch;
  int choice;

  while (true) {
      std::cout << "\n--- Stopwatch Menu ---\n";
      std::cout << "1. Start Stopwatch\n";
      std::cout << "2. Pause Stopwatch\n";
      std::cout << "3. Resume Stopwatch\n";
      std::cout << "4. Reset Stopwatch\n";
      std::cout << "5. Display Stopwatch\n";
      std::cout << "6. Exit\n";
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
          stopwatch.display();
          break;
      case 6:
          std::cout << "Exiting program.\n";
          return 0;
      default:
          std::cout << "Invalid choice. Please try again.\n";
      }
  }

  return 0;
}
