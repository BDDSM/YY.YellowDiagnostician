#include <iostream>
#include "windows.h"
#include <Lmcons.h>

#define INFO_BUFFER_SIZE 32767

int main() {
    SetConsoleCP(1251);

    std::cout << "Some diagnostics..." << std::endl;
    std::cout << std::endl;

    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;
    if(GetComputerName(infoBuf, &bufCharCount)) {
        std::cout << "Computer name: ";
        std::cout << infoBuf;
        std::cout << std::endl;
    }

    char buffer[UNLEN+1];
    DWORD size;
    size=sizeof(buffer);
    if(GetUserName(buffer,&size)){
        std::cout << "User name: ";
        std::cout << buffer;
        std::cout << std::endl;
    }

    std::cout << "Press any key for exit...";
    std::getchar();

    return 0;
}
