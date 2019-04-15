#!/usr/bin/env python3

T = int(input())

for kz in range(1, T + 1):
    n = int(input())
    nn, tt, bs = n, 0, 1
    while n:
        if n % 10 == 4:
            tt += bs
            nn -= bs
        n = n // 10
        bs *= 10
    print("Case #{}: {} {}".format(kz, nn, tt))