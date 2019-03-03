import sys

m, n = map(int, sys.stdin.readline().split())

minimumInCol = []
maximumInCol = []
minimumInRow = []
maximumInRow = []
invalid = False

for i in range(0, m):
    minimumInCol.append(m)
    maximumInCol.append(-1)
    minimumInRow.append(n)
    maximumInRow.append(-1)

board = []

for i in range(0, m):
    input = list(sys.stdin.readline())
    input.pop()
    for j in range(0, n):
        if invalid:
            break
        if input[j] == 'R':
            for i_ in range(i, m):
                if maximumInRow[i_] == -1:
                    maximumInRow[i_] = j
            for j_ in range(j, n):
                if maximumInCol[j_] == -1:
                    maximumInCol[j_] = i
        elif input[j] == 'B':
            for i_ in range(0, i+1):
                if maximumInRow[i_] <= j and maximumInRow[i_] != -1:
                    print "invalid at:"
                    print i,j
                    print "invalid caused by i = ", i_
                    invalid = True
                    break
                else:
                    minimumInRow[i_] = j
            for j_ in range(0, j+1):
                if maximumInCol[j_] <= i and maximumInCol[j_] != -1:
                    print "invalid at:"
                    print i,j
                    print "invalid caused by j = ", j_
                    invalid = True
                    break
                else:
                    minimumInCol[j_] = i
    board.append(input)

if invalid:
    print 0
else:
    print minimumInRow
    print maximumInRow
    print minimumInCol
    print maximumInCol
    print board