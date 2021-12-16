#include <iostream>
#include <string_view>
#include <boost/core/detail/string_view.hpp>
#include <boost/url/src.hpp>

int main()
{
	std::string_view sv("www.google.com");

	auto res = boost::urls::parse_uri(sv);

	return 0;
}
