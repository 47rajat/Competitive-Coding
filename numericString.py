s = raw_input()

k, b, m = map(int, raw_input().split())

base = []
value = 1
for i in xrange(k):
    base.append(value)
    value = (value*b) % m
ans = 0
value = 0
for i in xrange(k):
    value += int(s[i])*base[-i-1]
ans = value % m

# print 'ans = {}'.format(ans)
for i in xrange(k, len(s)):
    # using (b%m) instead of base[1] to avoid index out of range error for case k = 1.
    value = (value - int(s[i-k])*base[-1])*(b%m) + int(s[i])
    ans += value % m
    # print 'ans = {}'.format(ans)

print ans

