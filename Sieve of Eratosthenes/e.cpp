#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define ll long long

#define fastio   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<bool> isPrime;
void Seive(void) {
	int n = 1e8, k;
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int j = 2 * 2; j <= n; j += 2) isPrime[j] = false;
	for (int j = 3 * 3; j <= n; j += 3) isPrime[j] = false;
	for (int i = 1;; i += 1) {
		k = (6 * i - 1);
		if (k * k > n)
			break;
		if (isPrime[k])
			for (int j = k * k; j <= n; j += 2 * k) isPrime[j] = false;
		k += 2;
		if (k * k > n)
			break;
		if (isPrime[k])
			for (int j = k * k; j <= n; j += 2 * k) isPrime[j] = false;
	}
}



vector<int>Tri;

void Triangle(void) {
	int n = 1e8 + 1;
	Tri.reserve(1e7);
	for (int i = 2; i < n; i++)
		if (isPrime[i])
			Tri.push_back(i);
}



int main()
{
	fastio;
	debugMode();
	Seive();
	Triangle();


	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (!isPrime[n]) {
			cout << -1 << "\n";
			continue;
		}
		int m = lower_bound(Tri.begin(), Tri.end(), n) - Tri.begin();
		int x = (-1 + pow(1 + 8 * m, 0.5)) / 2;
		if ((x + 1) * (x + 2) / 2 < m)
			x += 1;
		if ((x + 1) * (x + 2) / 2 < m)
			x += 1;
		if ((x + 1) * (x + 2) / 2 < m)
			x += 1;
		cout << x + 1 << " " << m + 1 - x*(x + 1) / 2 << "\n";
	}
	return 0;
}
