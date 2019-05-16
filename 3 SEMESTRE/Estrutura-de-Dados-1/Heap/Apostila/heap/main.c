#include "heap_min.h"
#include "heap_max.h"
#include <stdio.h>

int main()
{
	int nMin;
	printf("Informe o numero de elementos do vetor:\n>>>> ");
	scanf(" %d", &nMin);
	int hMin[nMin], hMax[nMin], i, nMax = nMin;
	for (i = 0; i < nMax; i++) {
        scanf(" %d", &hMin[i]);
        hMax[i] = hMin[i];
	}
	make_heap_min(hMin, nMin);
	make_heap_max(hMax, nMax);
	printf("Heap Minimo: [%d", rem_heap_min(hMin, &nMin));
	while (nMin > 0) {
		printf(", %d", rem_heap_min(hMin, &nMin));
	}
	printf("]\n");
	printf("---------------------------------\n");
	printf("Heap Maximo: [%d", rem_heap_max(hMax, &nMax));
	while (nMax > 0) {
		printf(", %d", rem_heap_max(hMax, &nMax));
	}
	printf("]\n");
	return 0;
}
