PREFIX ?= /usr/local
INCLUDE_DIR = $(PREFIX)/include
LIB_DIR = $(PREFIX)/lib

LIB = libztring.a
HEADER = ztring.h

CFLAGS = -g -Wall -std=gnu11 -fPIC
LDFLAGS =
LDLIBS =

SOURCES = ztring.c
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

COVERAGE_RM_SUITES = $(patsubst spec/%.c, %.gc*, $(wildcard spec/*.c))

.PHONY: release install uninstall test valgrind style clean

test: CFLAGS += --coverage

$(LIB): $(OBJECTS)
	ar -rcs $@ $^

release: CFLAGS = -std=gnu11 -Os -march=native -Wall -Wextra -Wpedantic -Wstrict-overflow -fno-strict-aliasing
release: $(LIB)

SPECK_CFLAGS = -I.
SPECK_LDFLAGS = -L.
SPECK_LIBS = -lztring
-include speck/speck.mk
test: SPECK_CFLAGS += --coverage
test: $(SPECK) $(LIB) $(SUITES)
	@$(SPECK)
	@rm -f $(COVERAGE_RM_SUITES)

valgrind: $(SPECK) $(LIB) $(SUITES)
	@valgrind --suppressions=valgrind.supp --leak-check=full --error-exitcode=1 $(SPECK)

coverage: test
	@gcov -lp $(SOURCES)

install: release
	mkdir -p $(INCLUDE_DIR)
	mkdir -p $(LIB_DIR)
	install -m 644 $(LIB) $(LIB_DIR)/$(LIB)
	install -m 644 $(HEADER) $(INCLUDE_DIR)/$(HEADER)

uninstall:
	rm -f $(LIB_DIR)/$(LIB)
	rm -f $(INCLUDE_DIR)/$(HEADER)

style:
	astyle -A3s4SpHk3jn *.c *.h spec/*.c

clean:
	rm -f $(LIB) $(OBJECTS)
	rm -rf *.dSYM spec/*.dSYM *.gc*
	rm -f spec/*.so
