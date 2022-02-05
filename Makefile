CFLAGS=-g -Wall -Werror
CXXFLAGS=-g -Wall -Werror

test_foo: main.o foo-cc.o foo.o
	$(CXX) -o $@ $^

clean:
	rm -rf *.o test_foo
