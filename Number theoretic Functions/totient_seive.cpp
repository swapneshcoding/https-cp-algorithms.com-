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

vector<int> totient_seive(int n) {
	vector<int> Seive(n + 1);
	Seive[0] = 0;
	Seive[1] = 1;
	for (int i = 2; i <= n; i++) Seive[i] = i;

	for (int i = 2; i <= n; i++) {
		if (Seive[i] == i) {
			for (int j = i; j <= n; j += i)
				Seive[j] -= Seive[j] / i;
		}
	}
	return Seive;
}

int main() {
	debugMode();

	auto V = totient_seive(10);
	for (int i = 1; i <= 10; i++)
		cout << "phi(" << i << ") = " << V[i] << "\n";
}

