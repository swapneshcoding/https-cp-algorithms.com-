#include<iostream>
#include<vector>
using namespace std;

vector<bool> Seive_of_Eratosthenes(int n) {
	vector<bool>isPrime(n + 1, true);
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
	return isPrime;
}


int main() {
	vector<bool>isPrime = Seive_of_Eratosthenes(1e9 + 7);
	cout << "isPrime.size(): " << isPrime.size() << "\n";
	cout << "isPrime[1e9+7]: " << isPrime[1e9 + 7] << "\n";
}

/*
output:
isPrime.size(): 1000000008
isPrime[1e9+7]: 1
[Finished in 72.1s]
*/
