#include <iostream>
#include <thread>
#include <string>

#if defined( __linux__ ) || defined(__APPLE__)
#include <unistd.h>
#include <pwd.h>
#include <limits.h>
#endif

#ifdef WIN32
#include "windows.h"
#include <Lmcons.h>
#endif

#define INFO_BUFFER_SIZE 32767

#ifdef WIN32
#pragma setlocale("ru-RU" )
#endif

int main() {

    std::cout << "Some diagnostics..." << std::endl;
    std::cout << std::endl;

#ifdef WIN32
    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;
    if(GetComputerName(infoBuf, &bufCharCount)) {
        std::cout << "Computer name: ";
        std::cout << infoBuf;
        std::cout << std::endl;
    }
#endif
#if defined( __linux__ )
    char hostname[HOST_NAME_MAX];
    gethostname(hostname, HOST_NAME_MAX);
    std::cout << "Computer name: ";
    std::cout << hostname;
    std::cout << std::endl;
#endif

#ifdef WIN32
    char buffer[UNLEN+1];
    DWORD size;
    size=sizeof(buffer);
    if(GetUserName(buffer,&size)){
        std::cout << "User name: ";
        std::cout << buffer;
        std::cout << std::endl;
    }
#endif
#if defined( __linux__ )
    char username[LOGIN_NAME_MAX];
    getlogin_r(username, LOGIN_NAME_MAX);
    std::cout << "User name: ";
    std::cout << username;
    std::cout << std::endl;
#endif

#ifdef WIN32
    DWORD procId;
    procId = GetCurrentProcessId();
    std::cout << "Process ID: ";
    std::cout << procId;
    std::cout << std::endl;
#endif
#if defined( __linux__ )
    std::cout << "Process ID: ";
    std::cout << ::getpid();
    std::cout << std::endl;
#endif

    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Thread ID: ";
    std::cout << this_id;
    std::cout << std::endl;

    std::cout << "Press any key for exit...";
    std::getchar();

    return 0;
}
