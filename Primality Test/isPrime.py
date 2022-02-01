# with open('output.txt','w'):
# 	pass
# def printf(*args):
# 	print(*args,file = open('output.txt','a'))



def binexpo(base,e,mod):
	res = 1
	while e:
		if e&1:
			res = (res*base)%mod
		base = (base*base)%mod
		e>>=1
	return res


def is_composite(n,a,d,s):
	x = binexpo(a,d,n)
	if x==1 or x==n-1:
		return False
	for r in range(1,s):
		x = (x*x)%n
		if x==n-1:
			return False
	return True


def MillerRabin(n):
	if n<2:
		return False
	s = 0
	d = n-1
	while d&1==0:
		d>>=1
		s+=1
	for a in [2,3,5,7,11,13,17,19,23,29,31,37]:
		if n==a:
			return True
		if is_composite(n,a,d,s):
			return False
	return True

for _ in range(int(input())):
	n = int(input())
	print(["NO","YES"][MillerRabin(n)])
