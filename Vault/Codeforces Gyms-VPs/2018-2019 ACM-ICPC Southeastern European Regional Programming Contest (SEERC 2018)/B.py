import sys

a, b, c, n = map(int, sys.stdin.readline().split())

ans = 0
Mod = 2 ** 64

if n % 2 == 0:
    ans += (n / 2) * (n / 2 + 1)
    ans -= 2
    ans += n - 2
else:
    ans += (n / 2) * (n / 2 + 1)

ans *= n

if a == b and b == c:
    ans /= 6
elif a == b or b == c or c == a:
    ans /= 2

print ans % Mod