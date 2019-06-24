#!/usr/bin/env python3

T = int(input())

for kz in range(T):
    print("Case #{}: ".format(kz + 1), end="")
    s = input()
    if eval(s.replace("x", "0").replace("X", "1")) != eval(s.replace("x", "1").replace("X", "0")):
        print("1")
    else:
        print("0")