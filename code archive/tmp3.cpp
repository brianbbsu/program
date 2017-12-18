#include <cstdlib>
#include <cstdio>
int main() { int* c = (int*)malloc(80 << 20); printf("%d\n", c[1]); }
