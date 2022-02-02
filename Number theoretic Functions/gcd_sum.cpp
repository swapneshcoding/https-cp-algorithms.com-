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



vector<int>Totient;

void Totient_seive(int n = 1e6) {
	Totient.resize(n + 1);
	for (int i = 0; i <= n; i++) Totient[i] = i;
	for (int i = 2; i <= n; i++) {
		if (Totient[i] == i) {
			for (int j = i; j <= n; j += i)
				Totient[j] -= Totient[j] / i;
		}
	}
	return;
}


vector<ll>gcd_sum;
void gcd_sum_seive(int n = 1e6) {
	gcd_sum.resize(n + 1, 0);
	for (int d = 1; d <= n; d++) {
		for (int f = 2 * d; f <= n; f += d)
			gcd_sum[f] += d * Totient[f / d];
	}
	// comment below lines for simple gcd sum
	for (int i = 1; i <= n; i++)
		gcd_sum[i] += gcd_sum[i - 1];
}







ll Solve(int n) {
	return 0;
}

int main()
{
	fastio;
	debugMode();
	Totient_seive();
	gcd_sum_seive();
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		cout << gcd_sum[n] << "\n";
	}
}
