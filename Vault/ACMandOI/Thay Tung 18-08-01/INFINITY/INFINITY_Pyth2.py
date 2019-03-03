import math

def isqrt(x):
	return math.ceil(x**0.5)
 
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