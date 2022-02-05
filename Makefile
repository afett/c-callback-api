CFLAGS=-g
CXXFLAGS=-g

test_foo: main.o foo-cc.o foo.o
	$(CXX) -o $@ $^

clean:
	rm -rf *.o test_foo
