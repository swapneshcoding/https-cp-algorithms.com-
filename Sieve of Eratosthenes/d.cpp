#include<bits/stdc++.h>
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
	int n = 1e6;
	isPrime.resize(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int j = 2 * 2; j <= n; j += 2) isPrime[j] = false;
	for (int j = 3 * 3; j <= n; j += 3) isPrime[j] = false;
	for (int i = 1;; i += 1) {
		if ((6 * i - 1) * (6 * i - 1) > n)
			break;
		if (isPrime[6 * i - 1])
			for (int j = (6 * i - 1) * (6 * i - 1); j <= n; j += 2 * (6 * i - 1)) isPrime[j] = false;
		if ((6 * i + 1) * (6 * i + 1) > n)
			break;
		if (isPrime[6 * i + 1])
			for (int j = (6 * i + 1) * (6 * i + 1); j <= n; j += 2 * (6 * i + 1)) isPrime[j] = false;
	}
}

vector<int>Count;

bool afraid(int n) {
	int x = pow(10, int(log10(n)));
	int y = n % x;

	if (y != n % (x / 10) and Count[y] != Count[y - 1])
		return true;
	else
		return false;
}

void Find(void) {
	int n = 1e6;
	Count.resize(n, 0);
	Count[0] = Count[1] = 0;
	Count[2] = 1;
	Count[3] = Count[4] = 2;
	Count[5] = Count[6] = 3;
	Count[7] = Count[8] = Count[9] = 4;
	for (int i = 10; i < n; i++) {
		if (isPrime[i] and afraid(i))
			Count[i] = Count[i - 1] + 1;
		else
			Count[i] = Count[i - 1];
	}
	return;
}


int main()
{
	fastio;
	debugMode();
	Seive();
	Find();

	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << Count[n] << "\n";
	}
	return 0;
}
