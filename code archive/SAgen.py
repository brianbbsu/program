from random import randrange as rnd

N = int(1e7)

sigma = 26

print "".join([chr(rnd(0,sigma)+ord('a')) for _ in range(N)])
