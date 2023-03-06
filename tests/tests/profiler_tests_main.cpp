///                   __ _ _           
///  _ __  _ __ ___  / _(_) | ___ _ __   
/// | '_ \| '__/ _ \| |_| | |/ _ \ '__|  profiler - simple intrusive C++ profiler
/// | |_) | | | (_) |  _| | |  __/ |     ---------------------------------
/// | .__/|_|  \___/|_| |_|_|\___|_|     https://github.com/q-ptr/profiler
/// |_|                                
///
/// SPDX-FileCopyrightText: 2023 q-ptr
/// SPDX-License-Identifier: MIT

#include <fmt/core.h>
#include <fstream>
#include <json.hpp>
#ifdef QPTR_PROFILER_ENABLED
#include <qptr/profiler/profile.hpp>
#include <qptr/profiler/analyzers/basic/analyzer.hpp>
#include <qptr/profiler/analyzers/basic/json_output.hpp>
#endif


bool load_json(const char *path, nlohmann::json &data)
{
	QPTR_PROF()

	try
	{
		std::ifstream f(path);
		
		data = nlohmann::json::parse(f);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_string(const nlohmann::json &data, std::string &str)
{
	QPTR_PROF()

	try
	{
		str = data.dump();

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_bjdata(const nlohmann::json &data, std::vector<std::uint8_t> &bjdata)
{
	QPTR_PROF()

	try
	{
		bjdata = nlohmann::json::to_bjdata(data);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_bson(const nlohmann::json &data, std::vector<std::uint8_t> &bson)
{
	QPTR_PROF()

	try
	{
		bson = nlohmann::json::to_bson(data);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_cbor(const nlohmann::json &data, std::vector<std::uint8_t> &cbor)
{
	QPTR_PROF()

	try
	{
		cbor = nlohmann::json::to_cbor(data);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_msgpack(const nlohmann::json &data, std::vector<std::uint8_t> &msgpack)
{
	QPTR_PROF()

	try
	{
		msgpack = nlohmann::json::to_msgpack(data);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

bool to_ubjson(const nlohmann::json &data, std::vector<std::uint8_t> &ubjson)
{
	QPTR_PROF()

	try
	{
		ubjson = nlohmann::json::to_ubjson(data);

		return true;
	}
	catch (...)
	{
		//
	}

	return false;
}

void test()
{
	QPTR_PROF()

	nlohmann::json              data;
	std::string                 str;
	std::vector<std::uint8_t>   bjdata;
	std::vector<std::uint8_t>   bson;
	std::vector<std::uint8_t>   cbor; 
	std::vector<std::uint8_t>   msgpack;
	std::vector<std::uint8_t>   ubjson;

	//if (load_json("d:\\canada.json", data))
	if (load_json("d:\\twitter.json", data))
	{
		(void) to_string(data, str);
		(void) to_bjdata(data, bjdata);
		(void) to_bson(data, bson);
		(void) to_cbor(data, cbor);
		(void) to_cbor(data, msgpack);
		(void) to_cbor(data, ubjson);
	}
}

int main()
{
#ifdef QPTR_PROFILER_ENABLED
	qptr::profiler::profile::enable(std::make_shared<qptr::profiler::analyzers::basic::analyzer>(
	                                std::make_shared<qptr::profiler::analyzers::basic::json_output>("profiling.json")));
#endif

	test();

	return 0;
}
