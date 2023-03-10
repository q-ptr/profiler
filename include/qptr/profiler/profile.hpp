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


#include <qptr/profiler/detail/global_profiler.hpp>
#include <qptr/profiler/detail/scope_helper.hpp>
#include <qptr/profiler/analyzer.hpp>
#include <memory>


#ifdef QPTR_PROFILER_ENABLED
	#define QPTR_PROF_SCOPE(name)      qptr::profiler::detail::scope_helper   __qpr_profiler_scope__(name "");
	#define QPTR_PROF()                qptr::profiler::detail::scope_helper   __qpr_profiler_scope__(__FUNCTION__);
#else
	#define QPTR_PROF_SCOPE(name)
	#define QPTR_PROF()
#endif


namespace qptr::profiler
{

class profile final
{
public:

	static bool is_enabled()
	{
		return detail::global_profiler_.is_enabled();
	}

	static void enable(std::shared_ptr<analyzer> analyzer)
	{
		return detail::global_profiler_.enable(analyzer);
	}

private:

	profile() = default;

	~profile() = default;
};

}//namespace qptr::profiler

