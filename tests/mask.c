#include <stdio.h>

int perm_wt = 3;
int k = 8;

void printb(unsigned long long d) {
	int i;
	for (i = k - 1; i >= 0; i--)
		printf("%d", ((((unsigned long long) 1 << i) & d) ? 1 : 0));
	printf("\n");
}

int main(int argc, char *argv[]) {

	unsigned long long mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;

	printf("%llx\n", mask);
  printb(mask);  
}

