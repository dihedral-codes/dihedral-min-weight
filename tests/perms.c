#include <stdio.h>

int perm_wt = 3;
int k = 8;

void printb(unsigned long long d) {
	int i;
	for (i = k - 1; i >= 0; i--)
		printf("%d", ((((unsigned long long) 1 << i) & d) ? 1 : 0));
	printf("\n");
}

unsigned long long next_perm(unsigned long long perm) {
  unsigned int t = perm | (perm - 1); 
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(perm) + 1));  
}

int main(int argc, char *argv[]) {

	unsigned long long perm = ((unsigned long long) 1 << (k - 1)) | (((unsigned long long) 1 << (perm_wt - 1)) - (unsigned long long) 1);
	unsigned long long lastperm = (((unsigned long long) 1 << perm_wt) - (unsigned long long) 1) << (k - perm_wt);
  
  printf("%llx\n", perm);
  while (perm != lastperm) {
    printb(perm);
		perm = next_perm(perm);
  }
  printb(perm);  
}