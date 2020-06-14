#include "Diagnostic.h"

namespace yy
{	
	std::string GetHost()
	{
        std::string hostname;
		
#ifdef WIN32
        TCHAR  infoBuf[16384];
        DWORD  bufCharCount = 16384;
		if (GetComputerName(infoBuf, &bufCharCount)) {
            hostname = infoBuf;
        }
#endif
		
#if defined( __linux__ )
        gethostname(hostname, HOST_NAME_MAX);
#endif

        return hostname;
	}

    std::string GetUser()
    {
        std::string username;

#ifdef WIN32
        char buffer[UNLEN + 1];
        DWORD size;
        size = sizeof(buffer);
        if (GetUserName(buffer, &size)) {
            username = buffer;
        }
#endif
		
#if defined( __linux__ )
        char valueUsername[LOGIN_NAME_MAX];
        getlogin_r(valueUsername, LOGIN_NAME_MAX);
        username = valueUsername;
#endif

        return username;
    }

    int GetProcessId()
    {
        int processId;

#ifdef WIN32
        DWORD procId;
        procId = GetCurrentProcessId();
        processId = procId;
#endif

#if defined( __linux__ )
        processId = ::getpid();
#endif

        return processId;
    }

    int GetThreadId()
    {
        int threadId;

        threadId = std::hash<std::thread::id>{}(std::this_thread::get_id());

        return threadId;
    }
}