n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
a.reverse()
b.sort()

sol = []
for i in range(n):
    sol.append(a[i] * b[i])

print(sum(sol))