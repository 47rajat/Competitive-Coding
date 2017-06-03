n, x = map(int, raw_input().split())

location = map(int, raw_input().split())

speeds = map(int, raw_input().split())

ans = [0 for i in xrange(n)]
for i in xrange(n):
    ans[i] = (abs(location[i] - x)/speeds[i], i)

ans.sort()

if len(ans) == 1 or ans[0][0] < ans[1][0]:
    print ans[0][1]
else:
    print -1