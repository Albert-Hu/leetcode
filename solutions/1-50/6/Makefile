CPPFLAGS = -std=c++11 -Wall -Werror -DLOCAL_TEST

ifeq ($(SIMULATE), 1)
# make clean test SIMULATE=1
	CPPFLAGS += -DSIMULATE
endif

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test =========="
	@./test < input.txt

clean:
	rm -f test

.PHONY: test
