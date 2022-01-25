#include<iostream>
#include<vector>
using namespace std;

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

vector<bool> Seive_of_Eratosthenes(int n) {
	vector<bool>isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;
	for (int j = 2 * 2; j <= n; j += 2) isPrime[j] = false;
	for (int j = 3 * 3; j <= n; j += 3) isPrime[j] = false;
	for (int i = 1;; i += 1) {
		if ((6 * i - 1) * (6 * i - 1) > n)
			break;
		if (isPrime[6 * i - 1])
			for (int j = (6 * i - 1) * (6 * i - 1); j <= n; j += 6 * i - 1) isPrime[j] = false;
		if ((6 * i + 1) * (6 * i + 1) > n)
			break;
		if (isPrime[6 * i + 1])
			for (int j = (6 * i + 1) * (6 * i + 1); j <= n; j += 6 * i + 1) isPrime[j] = false;
	}
	return isPrime;
}


int main() {
	debugMode();
	vector<bool>isPrime = Seive_of_Eratosthenes(1e8);
	cout << 2 << "\n";
	for (int i = 3, n = 1; i < isPrime.size(); i++) {
		if (isPrime[i]) {
			n += 1;
			if (n  == 101) {
				cout << i << "\n";
				n = 1;
			}
		}
	}


}

