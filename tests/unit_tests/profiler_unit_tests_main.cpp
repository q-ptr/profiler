///                   __ _ _           
///  _ __  _ __ ___  / _(_) | ___ _ __   
/// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
/// | |_) | | | (_) |  _| | |  __/ |     ----------------------------------------
/// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
/// |_|                                
///
/// SPDX-FileCopyrightText: 2023 q-ptr
/// SPDX-License-Identifier: MIT

#include <catch_amalgamated.hpp>


int main(int argc, char *argv[])
{
	int   nResult = Catch::Session().run(argc, argv);

	return nResult;
}

TEST_CASE("predef", "[predef]")
{
	REQUIRE(1 == 1);

	SECTION("test_section")
	{
		REQUIRE(1 == sizeof(uint8_t));
	}
}
