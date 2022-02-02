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

void totient_seive(int n = 1e6) {
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

vector<ll> d_phid_sum;

void d_phid_sum_function(int n = 1e6) {
	d_phid_sum.resize(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i)
			d_phid_sum[j] += 1ll * Totient[i] * i;
	}
	return;
}

ll lcmSum_neive(ll n) {
	ll Ans = 0;
	for (ll i = 1; i <= n; i++)
		Ans += i / __gcd(i, n);
	return Ans * n;
}

void Assert(ll n) {
	ll Ans = d_phid_sum[n];
	Ans = (Ans + 1) * n / 2;
	// cout << Ans << " " << lcmSum_neive(n) << "\n";
	assert(Ans == lcmSum_neive(n));
	cout << "Success!!!\n";
}


int main() {
	fastio;
	debugMode();
	totient_seive();
	d_phid_sum_function();
	// Assert(1e6);
	int t, n;
	// cin >> t;
	scanf("%d", &t);
	while (t--) {
		// cin >> n;
		scanf("%d", &n);
		ll Ans = d_phid_sum[n];
		Ans = (1 + Ans) * n / 2;
		// cout << Ans << "\n";
		printf("%lld\n", Ans);
	}
}
