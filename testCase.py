import random

n = random.randint(1,10**5)

print n

for  i in xrange(n):
    print random.randint(2,10**6),

print

q = random.randint(1,10**5)

print q

for i in xrange(q):
    l = random.randint(1,n)
    r = random.randint(1,n)
    x = random.randint(1,10**6)
    y = random.randint(1,10**6)

    print min(l,r), max(l,r), min(x,y),max(x,y)
