T = int(input())

while T > 0:
	n = int(input())
	if n % 2 != 0:
		print('0')
	else:
		p1 = 1; p2 = 1; p3 = 1
		for i in range(1, n+1):
			p1 *= i
		for i in range(1, n//2+2):
			p2 *= i
		for i in range(1, n//2+1):
			p3 *= i
		ans = p1 // p2 // p3
		print(ans)
	T -= 1