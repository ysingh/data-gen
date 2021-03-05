#include "unity.h"
#include "data-gen.h"

#define ARRSIZE 2009000

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
	for (int i = 0, j = ARRSIZE - 1; i < ARRSIZE; ++i, --j) {
		expected[i] = j;
	}

	int* actual = getReverseSortedIntArray(ARRSIZE);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRSIZE);

	free(actual);
}

void testGetNearlySortedIntArray(void) {
	int expected[ARRSIZE];
	for (int i = 0; i < ARRSIZE; ++i) {
		expected[i] = i;
	}
	srand(0);
	size_t pertubAt = (size_t)log2((double)ARRSIZE);
	size_t randomIndex1 = 0;
	size_t randomIndex2 = 1;
	while (pertubAt < ARRSIZE) {
		randomIndex1 = (size_t)(random() % ARRSIZE);
		randomIndex2 = (size_t)(random() % ARRSIZE);
		int val = expected[randomIndex1];
		expected[randomIndex1] = expected[randomIndex2];
		expected[randomIndex2] = val;
		pertubAt += pertubAt;
	}
	int* actual = getNearlySortedIntArray(ARRSIZE);
	//for (int i = 0; i < ARRSIZE; ++i) {
	//	printf("%d\n", actual[i]);
	//}
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRSIZE);

	free(actual);
}
