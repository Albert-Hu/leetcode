CPPFLAGS = -std=c++11 -Wall -Werror -DLOCAL_TEST

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test =========="
	@./test

clean:
	rm -f test

.PHONY: test
