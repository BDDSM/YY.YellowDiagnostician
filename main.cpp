#include <iostream>
#include "lib/Diagnostic.h"

int main() {

    std::cout << "Some diagnostics..." << std::endl;
    std::cout << std::endl;

    std::cout << "Computer name: ";
    std::cout << yy::GetHost();
    std::cout << std::endl;

    std::cout << "User name: ";
    std::cout << yy::GetUser();
    std::cout << std::endl;

    std::cout << "Process ID: ";
    std::cout << yy::GetProcessId();
    std::cout << std::endl;

    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Thread ID: ";
    std::cout << yy::GetThreadId();
    std::cout << std::endl;

    std::cout << "Press any key for exit...";
    std::getchar();

    return 0;
}
