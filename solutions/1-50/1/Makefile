CPPFLAGS := -std=c++11 -Wall -Werror -DLOCAL_TEST

# make USE_HASH=1 test
ifeq ($(USE_HASH), 1)
	CPPFLAGS += -DUSE_HASH
endif

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test =========="
	@./test < input.txt

clean:
	rm -f test

.PHONY: test
