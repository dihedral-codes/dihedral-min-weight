#include <stdio.h>

void printb(unsigned long long d) {
	int i;
	for (i = 11; i >= 0; i--)
		printf("%d", ((((unsigned long long) 1 << i) & d) ? 1 : 0));
	printf("\n");
}


int main(int argc, char *argv[]) {
  
  int k = 12;
	
	int perm_wt = 7;
	
	unsigned long long perm = ((unsigned long long) 1 << (k - 1)) | (((unsigned long long) 1 << (perm_wt - 1)) - (unsigned long long) 1);
	unsigned long long lastperm = (((unsigned long long) 1 << perm_wt) - (unsigned long long) 1) << (k - perm_wt);
	
  printf("%llx\n", perm);
  printf("%llx\n", lastperm);
	
	printb(perm);
	printb(lastperm);
}
