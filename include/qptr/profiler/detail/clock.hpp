///                   __ _ _           
///  _ __  _ __ ___  / _(_) | ___ _ __   
/// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
/// | |_) | | | (_) |  _| | |  __/ |     ----------------------------------------
/// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
/// |_|                                
///
/// SPDX-FileCopyrightText: 2023 q-ptr
/// SPDX-License-Identifier: MIT

#pragma once


#include <cstdint>
#include <chrono>


namespace qptr::profiler::detail
{

using clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady, 
                                 std::chrono::high_resolution_clock, 
                                 std::chrono::steady_clock>;

}//namespace qptr::profiler::detail
