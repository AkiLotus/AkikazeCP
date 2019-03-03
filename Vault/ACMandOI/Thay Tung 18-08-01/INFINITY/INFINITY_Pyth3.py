import math

def isqrt(x):
	lo = 1
	hi = x
	while lo < hi:
		mid = (lo + hi) >> 1
		if mid*mid < x:
			lo = mid+1
		else:
			hi = mid
	return lo
 
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