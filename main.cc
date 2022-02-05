#include "foo-cc.h"

#include <iostream>

class Bar {
public:
	void say(std::string const& msg)
	{
		std::cerr << "Bar: " << msg << "\n";
	}
};

int main()
{
	Foo f;
	f.on_a_event([](int arg) { std::cerr << "on_a: " << arg << "\n"; });

	auto b = Bar{};
	f.on_b_event([&b](std::string const& arg) { b.say(arg); });

	f.run();
}
