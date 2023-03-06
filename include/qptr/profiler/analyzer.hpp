///                   __ _ _           
///  _ __  _ __ ___  / _(_) | ___ _ __   
/// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
/// | |_) | | | (_) |  _| | |  __/ |     ---------------------------------
/// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
/// |_|                                
///
/// SPDX-FileCopyrightText: 2023 q-ptr
/// SPDX-License-Identifier: MIT

#pragma once


#include <qptr/profiler/detail/clock.hpp>


namespace qptr::profiler
{

class analyzer
{
public:

	virtual ~analyzer() = default;

	virtual const std::string &get_name() = 0;

	virtual bool begin_profiling() = 0;

	virtual bool end_profiling() = 0;

	virtual bool begin_thread_profiling(size_t thread_id) = 0;

	virtual bool end_thread_profiling(size_t thread_id) = 0;

	//start - when the internal profiler code started in the scope
	//stop  - when the internal profiler code finished in the scope
	virtual bool on_profiling(const char *name, 
	                          const detail::clock::time_point &start, const detail::clock::time_point &stop) = 0;

};

}//namespace qptr::profiler
