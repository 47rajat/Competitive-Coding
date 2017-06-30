import math
def compute():
    ans = 10 ** 4009
    total = 0
    for i in xrange(20):
        total += ans/math.factorial(i)
    
    return total

e = compute()

print long((e*3)/10**4009)
print float(e)/(e-1)