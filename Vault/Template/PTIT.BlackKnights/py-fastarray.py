def readArray():
	line = input() + ' '
	a = []
	num = 0
	for c in line:
		if c == ' ':
			a.append(num)
			num = 0
		else:
			num = num * 10 + (ord(c) - 48)
	return a