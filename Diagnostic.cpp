#include "Diagnostic.h"

namespace yy
{	
	std::string get_host()
	{
        char* temp = 0;
        std::string computerName;

#if defined(WIN32) || defined(_WIN32) || defined(_WIN64)
        temp = getenv("COMPUTERNAME");
        if (temp != 0) {
            computerName = temp;
            temp = 0;
        }
#else
        temp = getenv("HOSTNAME");
        if (temp != 0) {
            computerName = temp;
            temp = 0;
        }
        else {
            temp = new char[512];
            if (gethostname(temp, 512) == 0) { // success = 0, failure = -1
                computerName = temp;
            }
            delete[]temp;
            temp = 0;
        }
#endif

        return computerName;
	}

    std::string get_user()
    {
        std::string username;

#ifdef WIN32
        char buffer[UNLEN + 1];
        DWORD size;
        size = sizeof(buffer);
        if (GetUserNameA(buffer, &size)) {
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

	int get_process_id()
	{
        int process_id = -1;

#ifdef WIN32
        DWORD procId;
        procId = GetCurrentProcessId();
        process_id = procId;
#endif

#if defined( __linux__ )
        processId = ::getpid();
#endif

        return process_id;
    }

	int get_thread_id()
	{
        int thread_id = -1;
		
	    thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());

        return thread_id;
    }
}