mod = 1000000007

def f(x,y,z):
    if x > y or z > y:
        return 0
    else:
        return (x+y)*(y+z)

for t in xrange(int(raw_input())):
    p, q, r = map(int, raw_input().split())

    a = map(int, raw_input().split())
    b = map(int, raw_input().split())
    c = map(int, raw_input().split())


    a.sort()
    b.sort()
    c.sort()
    ans = 0

    i = 0
    j = 0
    k = 0

    x = 0
    z = 0
    while j < q:
        y = b[j]

        while i < p and a[i] <= y:
            x = (x + a[i]) % mod
            i += 1
        
        while k< r and c[k] <= y:
            z = (z + c[k]) % mod
            k += 1
        
        ans = (ans +(k*x*y) % mod + (i*y*z) % mod + (x*z) % mod + (i*k*y*y) % mod) % mod 

        j += 1
    
    print ans % mod
