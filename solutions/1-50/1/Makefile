CPPFLAGS := -std=c++11 -Wall -Werror -DLOCAL_TEST

ifeq ($(USE_BRUTE_FORCE), 1)
	CPPFLAGS += -DBRUTE_FORCE
else
ifeq ($(USE_HASH), 1)
	CPPFLAGS += -DUSE_HASH
endif
endif

source = $(wildcard *.cpp)

test: $(source)
	g++ $(CPPFLAGS) -o $@ $^
	@echo "========== Run Test =========="
	@./test < input.txt

clean:
	rm -f test

.PHONY: test
