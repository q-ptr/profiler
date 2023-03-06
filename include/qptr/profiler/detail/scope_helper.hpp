///                   __ _ _           
///  _ __  _ __ ___  / _(_) | ___ _ __   
/// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
/// | |_) | | | (_) |  _| | |  __/ |     ---------------------------------
/// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
/// |_|                                
///
/// SPDX-FileCopyrightText: 2023 q-ptr
/// SPDX-License-Identifier: MIT


#include <qptr/profiler/detail/thread_profiler.hpp>


namespace qptr::profiler::detail
{

class scope_helper final
{
public:

	inline explicit scope_helper(const char *name)
	{
		thread_profiler_.add(name);
	}

	inline ~scope_helper()
	{
		thread_profiler_.add(nullptr);
	}
};

}//namespace qptr::profiler::detail
