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


#include <qptr/profiler/detail/event.hpp>


namespace qptr::profiler::detail
{

struct events_t final
{
	events_t   *prev_;
	events_t   *next_;
	size_t     total_count_;
	size_t     used_count_;
	event_t    events_[1];

	inline static events_t *create(size_t total_count)
	{
		if (0 == total_count)
		{
			return nullptr;
		}
		else
		{
			auto   events = (events_t *)std::malloc(sizeof(events_t) + sizeof(event_t) * (total_count - 1));

			if (nullptr == events)
			{
				return nullptr;
			}

			events->prev_        = nullptr;
			events->next_        = nullptr;
			events->total_count_ = total_count;
			events->used_count_  = 0;

			return events;
		}
	}

	inline void destroy()
	{
		std::free(this);
	}
};

}//namespace qptr::profiler::detail
