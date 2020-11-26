CPPFLAGS = -std=c++11 -Wall -Werror -DLOCAL_TEST

# make USE_SOLUTION1=1 test
ifeq ($(USE_SOLUTION1), 1)
	CPPFLAGS += -DSOLUTION1
endif

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test =========="
	@./test < input.txt

clean:
	rm -f test

.PHONY: test all
