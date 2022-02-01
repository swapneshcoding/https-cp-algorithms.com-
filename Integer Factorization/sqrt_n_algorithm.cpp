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


vector<long long> Factorize(long long n) {
	vector<long long>Factors;
	for (int d : {2, 3, 5}) {
		while (n % d == 0) {
			Factors.push_back(d);
			n /= d;
		}
	}
	vector<int>increments = {4, 2, 4, 2, 4, 6, 2, 6};
	int i = 0;
	for (long long d = 7; d * d <= n; d += increments[i++]) {
		while (n % d == 0) {
			Factors.push_back(d);
			n /= d;
		}
		if (i == 8) i = 0;
	}
	if (n > 1)
		Factors.push_back(n);
	return Factors;
}


int main() {
	debugMode();
	for (auto x : Factorize(24))
		cout << x << " ";
}

