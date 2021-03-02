#include "data-gen.h"

static void* checkMalloc(size_t size) {
	void *res = malloc(sizeof(int[size]));
	if (res == NULL) {
		printf("MALLOC ERROR %d%s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	return res;
}

int* getSortedIntArray(size_t size) {
	int* res = checkMalloc(sizeof(int[size]));
	for (size_t i = 0; i < size; ++i) {
		res[i] = i;
	}
	return res;
}

int* getReverseSortedIntArray(size_t size) {
	int* res = checkMalloc(sizeof(int[size]));
	for (size_t i = 0; i < size; ++i) {
		res[i] = size - (i + 1);
	}
	return res;
}

int* getRandomIntArray(size_t size) {
	srandom(time(0));
	int* res = checkMalloc(sizeof(int[size]));
	for (size_t i = 0; i < size; ++i) {
		res[i] = random();
	}
	return res;
}

