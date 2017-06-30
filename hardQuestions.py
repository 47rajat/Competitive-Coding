n = int(raw_input())

vi = raw_input()
ca = raw_input()

total = 0
for v,c in zip(vi,ca):
    if not v == c and not v == '.':
        total += 1

print(total)