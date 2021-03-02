#include "unity.h"
#include "data-gen.h"

#define ARRSIZE 40000;

void testGetRandomIntArray(void) {
	srand(time(0));
	
	int expected[ARRSIZE];
	for (size_t i = 0; i < ARRSIZE; ++i) {
		expected[i] = random();
	}

	int* actual = getRandomIntArray(ARRSIZE);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRSIZE);

	free(actual);
}

void testGetSortedIntArray(void) {
	int expected[ARRSIZE];
	for (size_t i = 0; i < ARRSIZE; ++i) {
		expected[i] = i;
	}

	int* actual = getSortedIntArray(ARRSIZE);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRSIZE);

	free(actual);
}

void testGetReverseSortedIntArray(void) {
	int expected[ARRSIZE];
	for (size_t i = 0, j = ARRSIZE - 1; i < ARRSIZE; ++i, --j) {
		expected[i] = j;
	}

	int* actual = getReverseSortedIntArray(ARRSIZE);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRSIZE);

	free(actual);
}
