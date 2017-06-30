import math
 
p = [0,1,2]
q = [0,1,3]
 
def Sa(b, n, m):
    res = m * b * p[n]
    if (n & 1):
        res += (b * p[n] * q[n] -q[n] +p[n] - 1) * b // 2
    else:
        res += (b * p[n] * q[n] -q[n] +p[n] + 1) * b // 2
    return res
 
a = [0,1,2]
for i in range(1,1500):
    a.append(1)
    a.append(1)
    a.append(2*(i+1))
 
for i in range(3,4005):
    p.append(a[i] * p[i-1] + p[i-2])
    q.append(a[i] * q[i-1] + q[i-2])
n = int(input())
res = n * (n + 1)
 
for i in range(4000,0,-1):
    if(q[i] <= n and n < q[i+1] ):
        if(q[i] == n):
            res += Sa(1, i, 0)
            n = 0
        else:
            b = int(n/q[i])
            m = n % q[i]
            res += Sa(b, i, m)
            n = m
print (res) 