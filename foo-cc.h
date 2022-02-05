#ifndef FOO_CC_H
#define FOO_CC_H

#include <memory>
#include <functional>
#include <string>

struct foo;

class Foo {
public:
	Foo();
	Foo(Foo &&) = default;
	Foo & operator=(Foo &&) = default;
	~Foo();

	void on_a_event(std::function<void(int)> const&);
	void on_b_event(std::string const&, std::function<void(std::string const&)> const&);
	void run();

private:
	Foo(Foo const&) = delete;
	Foo & operator=(Foo const&) = delete;

	static void on_a_handler(int, void*);
	static void on_b_handler(const char*, void*);

	std::unique_ptr<foo, void(*)(foo*)> raw_;
	std::function<void(int)> on_a_cb_;
	std::function<void(std::string const&)> on_b_cb_;
};

#endif // FOO_CC_H
