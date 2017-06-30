for t in xrange(int(raw_input())):
    u, v = map(int, raw_input().split())

    ans = (u+v)*(u+v+1)
    ans /= 2

    ans += u+1

    print ans