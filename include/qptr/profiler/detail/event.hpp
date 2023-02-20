//                   __ _ _           
//  _ __  _ __ ___  / _(_) | ___ _ __   
// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
// | |_) | | | (_) |  _| | |  __/ |     ---------------------------------
// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
// |_|                                
//
// SPDX-FileCopyrightText: 2023 qptr
// SPDX-License-Identifier: MIT

#pragma once


#include <qptr/profiler/detail/clock.hpp>
#include <cstdint>


namespace qptr::profiler::detail
{

struct event_t final
{
	const char          *name_;
	clock::time_point   start_;
	clock::time_point   stop_;
};

}//namespace qptr::profiler::detail
