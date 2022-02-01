#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned ll
inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

ull mulmod(ull a, ull b, ull mod) {
	ull r = 0;
	while (b) {
		if (b & 1)
			r = (r + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return r;
}

ull gcd(ull a, ull b) {
	return !b ? a : gcd(b, a % b);
}

ull modexp(ull base, ull e, ull mod) {
	ull r = 1;
	while (e) {
		if (e & 1)
			r = mulmod(r, base, mod);
		base = mulmod(base, base, mod);
		e >>= 1;
	}
	return r;
}

bool isComposite(ull n, ull a, ull d, ull s) {
	ull x = modexp(a, d, n);
	if (x == 1 || x == n - 1)
		return false;

	for (ull r = 1; r < s; r++) {
		x = mulmod(x, x, n);
		if (x == n - 1)
			return false;
	}
	return true;
}


bool MillerRabin_isPrime(ull n) {
	if (n < 2)
		return false;
	ull s = 0;
	ull d = n - 1;
	while ((d & 1) == 0) {
		s += 1;
		d >>= 1;
	}
	for (ull a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (isComposite(n, a, d, s))
			return false;
	}
	return true;
}

map<ull, ull>Map;

ull PollardRho(ull n) {
	if (n % 2 == 0)
		return 2;
	ull x = rand() % n + 1;
	ull c = rand() % n + 1;
	ull y = x;
	ull g = 1;

	// fn is f(x) = x*x + c
	while (g == 1) {
		x = (mulmod(x, x, n) + c + n) % n;
		y = (mulmod(y, y, n) + c + n) % n;
		y = (mulmod(y, y, n) + c + n) % n;

		g = gcd((y - x > 0 ? y - x : x - y), n);
	}
	return g;
}

void factorize(ull n) {
	if (n == 1)
		return;
	if (MillerRabin_isPrime(n)) {
		Map[n]++;
		return;
	}
	ull divisor = PollardRho(n);
	factorize(divisor);
	factorize(n / divisor);
}





int main() {
	debugMode();
	ull n;
	while (cin >> n) {
		if (n == 0)
			break;
		Map.clear();
		if (n == 1) {
			cout << "1^1\n";
			continue;
		}
		factorize(n);
		for (auto it : Map) {
			cout << it.first << "^" << it.second << " ";
		}
		cout << "\n";
	}

}










/*
# with open('output.txt','w'):
# 	pass
# def printf(*args):
# 	print(*args,file = open('output.txt','a'))

from random import random

def mulmod(a,b,mod):
	res = 0
	while b:
		if b&1:
			res = (res+a)%mod
		a = (a+a)%mod
		b>>=1
	return res


def gcd(a,b):
	while b:
		a, b= b,a%b
	return a


def binexpo(base,e,mod):
	res = 1
	while e:
		if e&1:
			res = (res*base)%mod
			# res = mulmod(res,base,mod)
		base = (base*base)%mod
		# base = mulmod(base,base,mod)
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


def MillerRabin_isPrime(n):
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



def PollardRho(n):
	if n&1==0: # n%2==0
		return 2
	x = int(random()*(n-1)+1)
	c = int(random()*(n-1)+1)
	y = x
	g = 1
	while g==1:
		# x = (mulmod(x,x,n) + c + n)%n
		# y = (mulmod(y,y,n) + c + n)%n
		# y = (mulmod(y,y,n) + c + n)%n
		x = (x*x + c + n)%n
		y = (y*y + c + n)%n
		y = (y*y + c + n)%n
		g = gcd(abs(x-y),n)
	return g

Map = dict()

def factorize(n):
	if n==1:
		return
	if MillerRabin_isPrime(n):
		Map[n] = Map.get(n,0)+1
	divisor = PollardRho(n)
	factorize(divisor)
	factorize(n//divisor)
	return



while True:
	n = int(input())
	if n==0:
		break
	Map.clear()
	if n==1:
		print("1^1")
		continue
	factorize(n)
	for d in Map:
		print(d,'^',Map[d],sep='',end=' ')
	print()


*/
