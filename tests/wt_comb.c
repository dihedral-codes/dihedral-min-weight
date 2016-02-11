#include <stdio.h>
#include <stdlib.h>

int k = 48;
unsigned long long *A;
unsigned long long mask;

void load_A(unsigned long long d) {
  int i;

  for (i = 0; i < k; i++)
    A[i] = ((d << i) & mask) | (d >> (k - i));
}

int wt_comb(unsigned long long comb) {

  int i;
  int wt;
	unsigned long long v;

  for (i = 0, wt = 0; i < k; i++) {
		if (__builtin_popcountll(comb & A[i]) & ((unsigned long long) 1))
			wt++;
	}
	
  return wt;

}


int main(int argc, char *argv[]) {
  
	int i = 0;
	unsigned long long x;
	
  A = malloc(sizeof(unsigned long long) * k);

  // Create the mask.
  mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;
 
  unsigned long long d = 0xAA8EAA8EAA8A;
  load_A(d);
	
	for (x = 0xff; x < 0xffffff; x++)
		i += wt_comb(0xf0f0e);


	return 1;
	
}
