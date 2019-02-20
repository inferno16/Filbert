#pragma once

#ifdef FLB_WINDOWS
#include <Windows.h>
#endif // FLB_WINDOWS

#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <memory>
#include <functional>
#include <math.h>
#include <utility>
#include <algorithm>
#include <numeric>

#include "Log.h"

namespace Filbert
{
	typedef uint8_t  ui8;
	typedef uint16_t ui16;
	typedef uint32_t ui32;
	typedef uint64_t ui64;
	typedef int8_t  i8;
	typedef int16_t i16;
	typedef int32_t i32;
	typedef int64_t i64;
	typedef const ui8  cui8;
	typedef const ui16 cui16;
	typedef const ui32 cui32;
	typedef const ui64 cui64;
	typedef const i8  ci8;
	typedef const i16 ci16;
	typedef const i32 ci32;
	typedef const i64 ci64;
}