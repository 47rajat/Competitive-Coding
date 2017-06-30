for t in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())

    array = []
    for i in xrange(n):
        temp = map(int, raw_input().split())
        array.append(temp)

    ans = 0
    for i in xrange(n):
        for j in xrange(i+1, n):
            if array[i][0] + array[j][0] >= k:
                if sum([max(a,b) for a, b in zip(array[i][1:], array[j][1:])])
                    ans +=1 

    print ans
