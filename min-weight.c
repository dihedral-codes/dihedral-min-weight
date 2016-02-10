#include <stdio.h>
#include <stdlib.h>

int k = 48;
unsigned long long *A;
unsigned long long mask;

// Calculates the weight of the row combination iddentified by comb.
// Comb should have a 1 in the i^th position if row i is in the combination.
// Only the first k bits of comb are necessary/used.
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
	}
	
  return wt;

}

// Take a d and load it into A.
// d should be the first row of A, and the other k-1 rows of A will then
// be all of the k-1 other circular shifts of d.
void load_A(unsigned long long d) {
  int i;

  for (i = 0; i < k; i++)
    A[i] = ((d << i) & mask) | (d >> (k - i));
}

// Generate the next permutation lexicographical-wise.
unsigned long long nextperm(unsigned long long perm) {
  // From: https://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
  unsigned int t = perm | (perm - 1); 
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(perm) + 1));  
}

// Loops through all the permutations of perm_wt bits in k positions
// and calculates the weight of each. It keeps track of the minimum one.
int min_wt(int perm_wt) {

  int min = k;
  int wt;
  
	unsigned long long perm = ((unsigned long long) 1 << (k - 1)) | (((unsigned long long) 1 << (perm_wt - 1)) - (unsigned long long) 1);
	unsigned long long lastperm = (((unsigned long long) 1 << perm_wt) - (unsigned long long) 1) << (k - perm_wt);

  while (perm != lastperm) {
    wt = wt_comb(perm);
    if (wt < min)
      min = wt;
		perm = nextperm(perm);
  }
  wt = wt_comb(perm);
  if (wt < min)
    min = wt;

  return min;
}


int main(int argc, char *argv[]) {
  
  A = malloc(sizeof(unsigned long long) * k);

  // Create the mask.
  mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;
 
  unsigned long long d = 0xAA8EAA8EAA8A;
  load_A(d);  

  // Loop through all the possible weight of combinations.
  int perm_wt;
  int all_min_wt = k;
  int this_wt;

  for (perm_wt = 2; perm_wt < k; perm_wt++) {
    this_wt = perm_wt + min_wt(perm_wt);
    if (this_wt < all_min_wt)
    	all_min_wt = this_wt;
  }
	
	printf("%d\n", all_min_wt);

  return 0;
}
