#include "foo-cc.h"
#include "foo.h"

#include <cassert>
#include <stdexcept>

Foo::Foo()
:
	raw_{::foo_new(), &::foo_free},
	on_a_cb_{},
	on_b_cb_{}
{
	if (!raw_) {
		throw std::bad_alloc();
	}

	foo_on_a_event(raw_.get(), &Foo::on_a_handler, this);
	foo_on_b_event(raw_.get(), &Foo::on_b_handler, this);
}

Foo::~Foo() = default;

void Foo::on_a_event(std::function<void(int)> const& cb)
{
	on_a_cb_ = cb;
}

void Foo::on_b_event(std::function<void(std::string const&)> const& cb)
{
	on_b_cb_ = cb;
}

void Foo::on_a_handler(int arg, void *data)
{
	auto self = static_cast<Foo*>(data);
	assert(self);
	if (self->on_a_cb_) {
		self->on_a_cb_(arg);
	}
}

void Foo::on_b_handler(const char *arg, void *data)
{
	auto self = static_cast<Foo*>(data);
	assert(self);
	if (self->on_b_cb_) {
		self->on_b_cb_(arg ? std::string{arg} : std::string{});
	}
}

void Foo::run()
{
	assert(raw_);
	::foo_run(raw_.get());
}
