def popcount(x):
	return bin(x).count('1')

N = int(input())
x = int(input(), 2)
M = int(input())
ones = popcount(x)

for i in range(M):
	k = int(input())
	x += 1<<k
	new_ones = popcount(x)
	ans = 0
	if new_ones == ones+1:
		ans = 1
	else:
		ans = ones - new_ones + 2
	print(ans)
	ones = new_ones
print(bin(x)[2:])