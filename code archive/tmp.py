import random

W = 12
N = 50000
M = 50000

print("{} {} {}".format(W,N,M))

for _ in range(N):
    x = random.randint(0,2**W - 1)
    print("{} ".format(x),end="")

print()

for _ in range(M):
    print("".join(random.choices(["A","O","X","a","o","x"],k=W)))
