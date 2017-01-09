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