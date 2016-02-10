#include <stdio.h>
#include <stdlib.h>

int k = 48;
unsigned long long *A;
unsigned long long mask;

void load_A(unsigned long long d) {
  int i;

  for (i = 0; i < k; i++)
    A[i] = ((d << i) | ( d >> ((-i) & mask)));
}

int main(int argc, char *argv[]) {
  
  A = malloc(sizeof(unsigned long long) * k);

  // Create the mask.
  if (k > 63)
    mask = (unsigned long long) -1;
  else
    mask = ((unsigned long long) 1 << k) - (unsigned long long) 1;
 
  unsigned long long d = 0x111111111111;

  load_A(d);
	
	int i;
  
	for (i = 0; i < k; i++)
		printf("%llx\n", A[i]);  
}
