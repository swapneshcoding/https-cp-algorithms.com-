#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

unordered_map<int, bool>Paul;

void Search(void) {
	int n = 1e7;
	for (int i = 1; i * i * i * i < n; i++) {
		for (int j = 1; j * j + i * i * i * i < n; j++)
			Paul[j * j + i * i * i * i] = true;
	}
}
vector<bool>isPrime;

void Seive(void) {
	int n = 1e7;
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

void find(void) {
	int n = 1e7;
	Count.resize(n + 1);
	Count[0] = Count[1] = 0;
	for (int i = 2; i < n; i++)
		if (isPrime[i] and Paul.find(i) != Paul.end())
			Count[i] = 1 + Count[i - 1];
		else
			Count[i] = Count[i - 1];
}



int main() {
	debugMode();
	Search();
	Seive();
	find();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << Count[n] << "\n";
	}
  return 0;
}

