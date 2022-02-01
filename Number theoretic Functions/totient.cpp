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

ll phi(ll n) {
	ll Ans = n;
	for (int d : {2, 3, 5}) {
		if (n % d == 0)
			Ans -= Ans / d;
		while (n % d == 0) {
			n /= d;
		}
	}
	vector<int>increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (long long d = 7; d * d <= n; d += increments[i++]) {
		if (n % d == 0)
			Ans -= Ans / d;
		while (n % d == 0) {
			n /= d;
		}
		if (i == 8) i = 0;
	}
	if (n > 1)
		Ans -= Ans / n;
	return Ans;

}

int main() {
	debugMode();
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		cout << phi(n) << "\n";
	}

}

