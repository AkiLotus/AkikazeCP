import math

def isqrt(x):
	n = int(x)
	a, b = divmod(n.bit_length(), 2)
	x = 2**(a+b)
	while 1:
		y = (x + n//x)//2
		if y >= x: 
			if x*x == n: return x
			else: return x+1
		x = y
 
def solve(n):
	p = isqrt(n)
	return min(p*p - n + 1, n - (p-1)*(p-1))

inFile = 'INFINITY.INP'
fo = open("INFINITY.OUT", "w")

with open(inFile) as fp:
    M = int(fp.readline())
    while M > 0:
    	M = M-1
    	fo.write(str(solve(int(fp.readline()))))
    	fo.write('\n')