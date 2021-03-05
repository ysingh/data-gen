#include "data-gen.h"

static bool validSize(size_t size) {
	if (!size) {
		return false;
	}
	return true;
}

static void swap(int* arr, size_t idx1, size_t idx2) {
	int v1 = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = v1;
}

static  void* checkMalloc(size_t size) {
	if(!validSize(size)) {
		exit(EXIT_FAILURE);
	}
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

int* getNearlySortedIntArray(size_t size) {
	int* res = getSortedIntArray(size);
	srand(0);
	size_t pertubAt = (size_t)log2((double)size);
	size_t randomIndex1 = 0;
	size_t randomIndex2 = 1;
	while (pertubAt < size) {
		printf("RAND IDX1: %zu | RAND IDX2: %zu | PERTUB AT %zu\n", randomIndex1, randomIndex2, pertubAt);
		randomIndex1 = (size_t)(random() % size);
		randomIndex2 = (size_t)(random() % size);
		swap(res, randomIndex1, randomIndex2);
		pertubAt += pertubAt;
	}
	return res;
}

