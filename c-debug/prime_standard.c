/* prime-number finding program
Originally by Norman Matloff, UC Davis
http://wwwcsif.cs.ucdavis.edu/~davis/40/gdb_Tutorial.htm
Modified by Mark Ardis, RIT, 11/1/2006

Will report a list of all primes which are less than
or equal to the user-supplied upper bound.
WARNING: There are bugs in this program! */

#include <stdio.h>

int prime[15];  /* Prime[i] will be 1 if i is prime, 0 otherwise */
int upper_bound; /* check all numbers up through this one for primeness */

void check_prime(int k, int prime[]) {
  int j;

  /* the plan:  see if J divides K, for all values J which are
  themselves prime (no need to try J if it is nonprime), and
  less than or equal to sqrt(K) (if K has a divisor larger
  than this square root, it must also have a smaller one,
  so no need to check for larger ones) */
 
  j = 2;
  while (j * j <= k) {
    if (prime[j] == 1){
      if (k % j == 0)  {
        prime[k] = 0;
        return;
      } /* if (K % J == 0) */
    } /* if (Prime[J] == 1) */
    j++;
  } /* while (1) */

  /* if we get here, then there were no divisors of K, so it is prime */
  prime[k] = 1;

}  /* CheckPrime() */

int main() {
  int i;

  printf("Enter upper bound:\n");
  scanf("%d", &upper_bound);
  upper_bound = 50 ;
  prime[1] = 1;
  prime[2] = 1;
  for (i = 3; i <= upper_bound; i += 2) {
    check_prime(i, prime);
    if (prime[i]) {
      printf("%d is a prime\n", i);
    } /* if (Prime[i]) */
  } /* for (i = 3; i <= UpperBound; i += 2) */
  return 0;
} /* main() */
