#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

enum class ProcessStatus { SUSPENDED, RUNNING };
std::ostream &operator<<(std::ostream &os, const ProcessStatus &status) {
  if (status == ProcessStatus::SUSPENDED) {
      os << "suspended";
  } else if (status == ProcessStatus::RUNNING) {
    os << "running";
  }
  return os;
}

enum class Platform { P_32_BIT, P_64_BIT };
std::ostream &operator<<(std::ostream &os, const Platform &status) {
  if (status == Platform::P_32_BIT) {
    os << "32-bit";
  } else if (status == Platform::P_64_BIT) {
    os << "64-bit";
  }
  return os;
}

struct ProcessInfo {
  int id;
  std::string name;
  ProcessStatus status;
  std::string account;
  size_t memory;
  Platform platform;
};

void PrintProcesses(std::vector<ProcessInfo> processes) {
  std::sort(processes.begin(), processes.end(),
            [](const ProcessInfo &p1, const ProcessInfo &p2) {
              return p1.name < p2.name;
            });
  for (const auto process : processes) {
    std::cout << std::left << std::setw(20) << std::setfill(' ')
              << process.name;
    std::cout << std::left << std::setw(8) << std::setfill(' ') << process.id;
    std::cout << std::left << std::setw(12) << std::setfill(' ')
              << process.status;
    std::cout << std::left << std::setw(15) << std::setfill(' ')
              << process.account;
    std::cout << std::left << std::setw(10) << std::setfill(' ')
              << (int)process.memory / 1024;
    std::cout << std::left << ' ' << process.platform;
    std::cout << std::endl;
  }
}

int main() {
    std::vector<ProcessInfo> processes {
        {512, "cmd.exe", ProcessStatus::RUNNING, "SYSTEM", 148293, Platform::P_64_BIT},
        {1044, "chrome.exe", ProcessStatus::RUNNING, "marius.bancila", 25180454, Platform::P_32_BIT},
        {7108, "explorer.exe", ProcessStatus::RUNNING, "SYSTEM", 2952943, Platform::P_64_BIT},
        {10100, "chrome.exe", ProcessStatus::RUNNING, "marius.bancila", 227756123, Platform::P_32_BIT},
        {22456, "skype.exe", ProcessStatus::SUSPENDED, "marius.bancila", 16870123, Platform::P_64_BIT},
    };
    PrintProcesses(processes);
    return 0;
}