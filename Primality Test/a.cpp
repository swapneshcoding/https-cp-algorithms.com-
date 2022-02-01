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

ull mul(ull a, ull b, ull mod) {
	ull r = 0;
	if (a > b) {
		ull temp = a;
		a = b;
		b = temp;
	}
	a %= mod;

	while (b) {
		if (b & 1)
			r = (r + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return r;
}

ull binpower(ull base, ull e, ull mod) {
	ull r = 1;
	base %= mod;
	while (e) {
		if (e & 1)
			// r = (r * base) % mod;
			r = mul(r, base, mod);
		// base = (base * base) % mod;
		base = mul(base, base, mod);
		e >>= 1;
	}
	return r;
}

bool check_composite(ull n, int a, ull d, int s) {
	ull x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		// x = (x * x) % n;
		x = mul(x, x, n);
		if (x == n - 1)
			return false;
	}
	return true;
}

bool MillerRabin(ull n) {
	if (n < 2) return false;
	int s = 0;
	ull d = n - 1;
	while ((d & 1) == 0) {
		d >>= 1;
		s += 1;
	}

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
		if (n == a)
			return true;
		if (check_composite(n, a, d, s))
			return false;
	}
	return true;
}

void check(ull n) {
	cout << n << " is " << (MillerRabin(n) == 1 ? "" : "Not ") << "Prime" << "\n";
	return;
}






int main() {
	debugMode();
	// int t;
	// cin >> t;
	// ll n;
	// while (t--) {
	// 	cin >> n;
	// 	if (MillerRabin(n))
	// 		cout << "YES\n";
	// 	else
	// 		cout << "NO\n";
	// }
	check(1111111111111111111);
}

