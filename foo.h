#ifndef FOO_H
#define FOO_H

#ifdef __cplusplus
extern "C" {
#endif

struct foo;

struct foo *foo_new();
void foo_free(struct foo*);

void foo_on_a_event(struct foo *, void(*)(int, void*), void*);
void foo_on_b_event(struct foo *, const char*, void(*)(const char*, void*), void*);

void foo_run(struct foo*);

#ifdef __cplusplus
}
#endif

#endif // FOO_H
