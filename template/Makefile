CPPFLAGS = -std=c++11 -DLOCAL_TEST

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test ==========\n"
	./test

clean:
	rm -f test

.PHONY: test
