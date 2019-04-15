#!/usr/bin/env python3

from math import gcd

T = int(input())

for kz in range(1, T + 1):
    n, l = [int(x) for x in input().split()]
    d = [int(x) for x in input().split()]
    dt = []
    for i in range(l - 1):
        if d[i] != d[i+1]:
            g = gcd(d[i], d[i+1])
            dt = [g]
            lst = g
            for j in range(i, -1, -1):
                lst = d[j] / lst
                dt.insert(0, lst)
            lst = g
            for j in range(i + 1, l):
                lst = d[j] / lst
                dt.append(lst)
            break
    mp = {x: chr(i + ord('A')) for i, x in enumerate(sorted(set(dt)))}
    assert len(mp) == 26
    print("Case #{}: {}".format(kz, "".join(list(map(lambda x:mp[x], dt)))))