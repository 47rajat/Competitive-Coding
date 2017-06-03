'''
THE SOLUTION IS CORRECT BUT DOESN'T PASSES ALL TEST CASE,  BECAUSE PYTHON (FUCKING PYTHON)
FOR C++ IMPLEMENTATION SEE .cpp FILE WITH THE SAME NAME
 
This problem uses a combination of Dynamic Programming and Fast matrix multiplication
to solve the problem. 
The final solution is obtained using the relation:
    T(sum) = T(sum-1)*Q

    where T(s) is an 1 x m^2 matrix.
    and Q is a m^2 x m^2 matrix.
'''

MOD = 10**9 + 9
# method used for multiplying two m^2 x m^2 matrix
def multiply(a,b, m):
    temp = [[0 for i in xrange(m**2+1)] for j in xrange(m**2+1)]

    for i in xrange(1, m**2+1):
        for j in range(1, m**2+1):
            for k in range(1, m**2+1):
                temp[i][j] += (a[i][k]*b[k][j]) % MOD
    return temp

s, m, d = map(int, raw_input().split())


'''
This table is used to obtain the first m^2 elements for finding the answer.
    table[i][j] is the number of possible ways for getting a list of number with sum
    equal i and last number of list being j
'''
table = [[0 for j in xrange(m+1)] for i in xrange(m+1)]

for i in xrange(1, m+1):
    for j in xrange(1, m+1):
        # print i, j
        if j > i:
            table[i][j] = 0
        elif i == j:
            table[i][j] = 1
        else:
            lower = max(j-d, 1)
            higher = min(m, j+d, i)

            for p in range(lower, higher+1):
                table[i][j] += table[i-j][p] % (10 ** 9 + 9)

# if s < m then answer is in the table itself

if s <= m:
    print sum(table[s])
else:
    # converting table in vector
    x = [0]
    
    for i in xrange(1, m+1):
        for j in xrange(1, m+1):
            x.append(table[i][j])
    
    '''
    Using the relation T(s) = T(s-1)*Q and T(1) = x the final solution will be
    given by x*(Q^(s-m)) 
    where Q is the matrix which when multiplied by the vector `x` gives a 1 x m^2
    matrix in which the last m elements represent the row table[s] and the sum of
    those m elements will be the answer.
    '''
    # computing Q
    q = [[0 for i in xrange(m**2+1)] for j in xrange(m**2+1)]

    for i in xrange(1, m**2 + 1):
        for j in xrange(1, m**2 + 1):
            if i <= m**2 - m:
                q[i][i+m] = 1
            
            if i > m**2 - m:
                idx = i - m**2 + m
                col = 0
                for k in xrange(-idx*m, (-idx + 1)*m):
                    col += 1
                    if abs(col - idx) <=d:
                        q[i][k] = 1
                    else:
                        q[i][k] = 0

    
    # for i in q[1:]:
    #     print i[1:]

    # identity matrix used for computing Q^(s-m) using modular exponentiation
    # see Geeks for geeks for more detail on the method.

    result = [[1 if i == j else 0 for i in xrange(m**2+1)] for j in xrange(m**2+1)]

    # for r in result[1:]:
    #     print r[1:]


    power = s - m

    while power > 0:
        if power & 1:
            result = multiply(result, q, m)
        
        power /= 2
        q = multiply(q,q, m)
    
    total = 0
    for i in xrange(-m, 0):
        total += sum([a*b for a, b in zip(x, result[i])]) % MOD
    
    print total % MOD

