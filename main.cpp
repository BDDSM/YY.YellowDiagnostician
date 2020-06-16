#include <iostream>
#include "Diagnostic.h"

int main() {

    std::cout << "Some diagnostics..." << std::endl;
    std::cout << std::endl;

    std::cout << "Computer name: ";
    std::cout << yy::get_host();
    std::cout << std::endl;

    std::cout << "User name: ";
    std::cout << yy::get_user();
    std::cout << std::endl;

    std::cout << "Process ID: ";
    std::cout << yy::get_process_id();
    std::cout << std::endl;

    std::cout << "Thread ID: ";
    std::cout << yy::get_thread_id();
    std::cout << std::endl;

    std::cout << "Press any key for exit...";
    std::getchar();

    return 0;
}
