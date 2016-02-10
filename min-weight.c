#include <stdio.h>

int k = 48;
unsigned long long A[k];
unsigned long long mask;

// Calculates the weight of the row combination iddentified by comb.
// Comb should have a 1 in the i^th position if row i is in the combination.
// Only the first k bits of comb are necessary/used.
int wt_comb(unsigned long long comb) {

  int i;
  int wt;

  for (i = 0, wt = 0; i < k; i++)
    wt = wt + ((comb & A[i]) ? 1 : 0);

  return wt;

}

// Take a d and load it into A.
// d should be the first row of A, and the other k-1 rows of A will then
// be all of the k-1 other circular shifts of d.
void load_A(unsigned long long d) {
  int i;

  for (i = 0; i < k; i++)
    A[i] = ((d << i) | ( d >> ((-i) & mask)));
}


// Loops through all the permutations of perm_wt bits in k positions
// and calculates the weight of each. It keeps track of the minimum one.
int min_wt(int perm_wt) {

  int min = k;
  int wt;
  unsigned long long perm = ((unsigned long long) 1 << perm_wt) - (unsigned long long) 1;

  while (perm = nextperm(perm)) {
    wt = wt_comb(perm);
    if (wt < min)
      min = wt;
  }

  return min;
}

// Generate the next permutation lexicographical-wise.
unsigned long long nextperm(unsigned long long perm) {
  // From: https://graphics.stanford.edu/~seander/bithacks.html#NextBitPermutation
  unsigned int t = perm | (perm - 1); 
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));  
}

int main(int argc, char *argv[]) {
  // Create the mask.
  if (k > 63)
    mask = (unsigned long long) -1;
  else
    mask = mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;
 
  // Loop through all the possible weight of combinations.
  int perm_wt;
  int all_min_wt = k;
  int this_wt;

  for (perm_wt = 2; perm_wt <= k; perm_wt++) {
    this_wt = min_wt(perm_wt);
    if (this_wt < all_min_wt)
      all_min_wt = this_wt;
  }






  return 0;
}
