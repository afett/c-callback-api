#include "foo.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct foo {
	void (*on_a_cb)(int, void*);
	void *on_a_data;
	void (*on_b_cb)(const char*, void*);
	void *on_b_str;
	void *on_b_data;
};

struct foo *foo_new()
{
	return calloc(1, sizeof(struct foo));
}

void foo_free(struct foo *self)
{
	assert(self);
	free(self->on_b_str);
	free(self);
}

void foo_on_a_event(struct foo *self, void(*cb)(int, void*), void *data)
{
	assert(self);
	self->on_a_cb = cb;
	self->on_a_data = data;
}

void foo_on_b_event(struct foo *self, const char *str, void(*cb)(const char*, void*), void *data)
{
	assert(self);
	assert(str);

	self->on_b_cb = cb;
	free(self->on_b_str);
	self->on_b_str = strdup(str);
	self->on_b_data = data;
}

void foo_run(struct foo *self)
{
	assert(self);
	if (self->on_a_cb) {
		self->on_a_cb(42, self->on_a_data);
	}

	if (self->on_b_cb) {
		self->on_b_cb(self->on_b_str, self->on_b_data);
	}
}
