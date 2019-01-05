#include <cstdio>

bool IsPrime(int n) {
  int r=1&n,f=1;for(;f++*f< r*n; r=0<n%++f);
  return r>0^4-n>0;
}

int main() {
  int x;
  while (~scanf("%d", &x)) printf("%d\n", (int)IsPrime(x));
}