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


#include <qptr/profiler/detail/thread_entries.hpp>
#include <qptr/profiler/detail/global_profiler.hpp>
#include <thread>
#include <cstdint>


namespace qptr::profiler::detail
{

class thread_profiler final
{
public:

	inline ~thread_profiler()
	{
		if (nullptr != thread_entries_)
		{
			global_profiler_.end_thread(thread_entries_);
			thread_entries_ = nullptr;
		}
	}

	inline bool add(const char *scope_name)
	{
		auto   start = clock::now();

		if (!global_profiler_.is_enabled())
		{
			return false;
		}

		if (nullptr == thread_entries_)
		{
			if (nullptr == (thread_entries_ = thread_entries_t::create(global_profiler_.get_events_pre_alloc_count())))
			{
				return false;
			}
			global_profiler_.begin_thread();
		}

		auto   event = thread_entries_->get_next_event(global_profiler_.get_events_pre_alloc_count());

		if (nullptr == event)
		{
			return false;
		}

		event->name_  = scope_name;
		event->start_ = start;
		event->stop_  = clock::now();

		return true;
	}

private:

	thread_entries_t   *thread_entries_ = nullptr;

};

thread_local  thread_profiler   thread_profiler_;

}//namespace qptr::profiler::detail