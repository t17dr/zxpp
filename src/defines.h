#ifndef DEFINES_H
#define DEFINES_H

// Otherwise windows headers define a max() macro that "overrides"
// std::numeric_limits<INT>::max() and causes a compile error
#define NOMINMAX

// Disable assert in release
#ifndef _DEBUG
    #define NDEBUG
#endif

#endif

// Choose file dialog for the platform
#ifdef _WIN32
    #define NOC_FILE_DIALOG_WIN32
#endif

#ifdef __gnu_linux__
    #define NOC_FILE_DIALOG_GTK
#endif

#define NOC_FILE_DIALOG_IMPLEMENTATION

#define NUM_INSTRUCTIONS 2816

// Allow non-_s microsoft's functions
#ifdef _MSC_VER
    #define _CRT_SECURE_NO_WARNINGS
    #pragma warning(disable:4996)
#endif