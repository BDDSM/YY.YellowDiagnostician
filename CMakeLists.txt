cmake_minimum_required(VERSION 3.16)
project(YY_DiagnosticAppExtended)

set(CMAKE_CXX_STANDARD 14)

add_executable(YY_DiagnosticAppExtended main.cpp lib/Diagnostic.cpp lib/Diagnostic.h)

add_library(YY_Diagnostic lib/Diagnostic.cpp lib/Diagnostic.h)