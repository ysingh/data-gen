CFLAGS :=-I. -Ilib/ -Isrc/ -Wall -Wpedantic -Werror -Wextra -Wshadow
VALGRIND_FLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind.out
ASAN_COMPILER_FLAGS := -g -fsanitize=address,undefined,leak,integer -fno-omit-frame-pointer -fsanitize-address-use-after-scope
ASAN_ENV_FLAGS := strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1:detect_leaks=1

all: test data-gen.o

set-asan-env:
	export ASAN_OPTIONS=${ASAN_ENV_FLAGS}

clean: set-asan-env
	rm -rf *.o *.gch *.out

data-gen.o: src/data-gen.c src/data-gen.h 
	clang ${CFLAGS} ${ASAN_COMPILER_FLAGS} -c src/data-gen.c

unity.o: 
	clang -c test/lib/unity.c -o unity.o

test: data-gen.o unity.o
	ruby ../../Unity/auto/generate_test_runner.rb test/test.c
	mv test/test_Runner.c ./
	clang -I./test/lib -I./src ${CLFAGS} ${ASAN_COMPILER_FLAGS} test_Runner.c test/lib/unity.c src/data-gen.c test/test.c
	./a.out

valgrind: clean
	clang ${CFLAGS} -c data-gen.c
	clang ${CFLAGS} -o test test.c data-gen.o
	ruby ../../../Unity/auto/generate_test_runner.rb test.c
	
