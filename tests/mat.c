#include <stdio.h>
#include <stdlib.h>

int perm_wt = 3;
int k = 12;
int *A;
unsigned long long mask;

void printb(unsigned long long d) {
	int i;
	for (i = k - 1; i >= 0; i--)
		printf("%d", ((((unsigned long long) 1 << i) & d) ? 1 : 0));
	printf("\n");
}


int wt_comb(unsigned long long comb) {

  int i;
  int wt;
	unsigned long long v;

  for (i = 0, wt = 0; i < k; i++) {
		v = comb & A[i];
		v ^= v >> 1;
    v ^= v >> 2;
    v = (v & 0x1111111111111111UL) * 0x1111111111111111UL;
    
		if ((v >> 60) & 1)
			wt++;
		
		printb(comb);
		printb(A[i]);
		printf("%d\n", wt);
	}

  return wt;

}

void load_A(unsigned long long d) {
  int i;

  for (i = 0; i < k; i++)
    A[i] = ((d << i) & mask) | (d >> (k - i));
}

int main(int argc, char *argv[]) {

  A = malloc(sizeof(unsigned long long) * k);

  // Create the mask.
  mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;
 
  unsigned long long d = 0x17b;
  load_A(d); 

	wt_comb((unsigned long long) 0xf);

}



