#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>

#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <cstring>

#include <chrono>
#include <type_traits>
#include <algorithm>
#include <thread>

// #include <system/types.hpp>
// #include <system/time.hpp>

#include "include/cef_app.h"

namespace thread
{
    inline void sleep(const int time) noexcept
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
}