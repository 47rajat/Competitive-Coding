for t in xrange(int(raw_input())):
    n = int(raw_input())

    array = map(int, raw_input().split())
    array.sort()
    array.reverse()
    subset = 0
    total = 0
    ans = 0

    for a in xrange(n):
        if array[a] < 0:
            if (subset + 1)*(total + array[a]) > subset*total + array[a]:
                subset += 1
                total += array[a]
            else:
                ans += array[a]
        else:
            subset += 1
            total += array[a]
    
    ans += subset*total

    print ans