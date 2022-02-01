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

void seive(ll n) {
	int count = 0;

	for (int d : {2, 3, 5}) {
		count = 0;
		while (n % d == 0) {
			count += 1;
			n /= d;
		}
		if (count)
			cout << d << "^" << count << " ";
	}

	vector<int>increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (long long d = 7; d * d <= n; d += increments[i++]) {
		count = 0;
		while (n % d == 0) {
			count += 1;
			n /= d;
		}
		if (count)
			cout << d << "^" << count << " ";

		if (i == 8) i = 0;
	}
	if (n > 1)
		cout << n << "^" << 1 << " ";
	return;
}


int main() {
	debugMode();
	ll n;
	while (cin >> n) {
		if (n == 0)
			break;
		seive(n);
		cout << "\n";
	}

}

