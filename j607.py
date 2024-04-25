def f(k):
	k = str(k)
	k = k.split(',')
	small = int(k[0])
	big = int(k[0])
	for i in k:
		i = eval(i)
		small = min(small,i)
		big = max(big,i)
	return big-small


s = input()
s = s.replace("f(","f(\"")

for _ in range(200):
	d = -1;
	c = 0
	for i in range(len(s)):
		if d == -1 and i+2<=len(s) and s[i:i+2] == 'f(' and c == _:
			d = 0
			i += 1
		elif d == -1 and s[i:i+2] == 'f(':
			c += 1
			continue
		elif d == -1:
			continue
		elif s[i:i+1] == '(':
			d += 1
		elif s[i:i+1] == ')':
			d -= 1
			if d == 0:
				s = s[:i]+'\"'+s[i:]
				break
print(eval(s))
