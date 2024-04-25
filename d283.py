import sys
dp = [1,1];
for i in range(20000):
	dp.append(dp[-1]+dp[-2])
while True:
	try:
		t = int(input())
		print(dp[t-1])
	except EOFError:
		break
