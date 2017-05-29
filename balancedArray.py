n = int(raw_input())

array = map(int, raw_input().split())

sum1 = sum(array[:n/2])
sum2 = sum(array[n/2:])

print abs(sum1 - sum2)