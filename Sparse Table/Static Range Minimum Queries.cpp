// https://cses.fi/problemset/task/1647

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


const ll MAX_N = 2 * 100005 + 10;
const ll LOG = 25;
ll arr[MAX_N];
ll sTable[MAX_N][LOG];
ll bin_log[MAX_N];



ll Query(ll L, ll R) {
	if (L == R)
		return sTable[L][0];
	ll interval = R - L + 1;
	ll j = bin_log[interval];
	return min(sTable[L][j], sTable[R - (1 << j) + 1][j]);
}

int main() {
	debugMode();

	bin_log[1] = 0;
	for (ll i = 2; i < MAX_N; i++)
		bin_log[i] = bin_log[i / 2] + 1;


	ll n, q;
	cin >> n;
	cin >> q;;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		sTable[i][0] = arr[i];
	}

	for (ll j = 1; j < LOG; j++)
		for (ll i = 0; i + (1 << j) - 1 < n; i++)
			sTable[i][j] = min(sTable[i][j - 1], sTable[i + (1 << (j - 1))][j - 1]);


	// for (int j = 0; j < 3; j++) {
	// 	for (int i = 0; i + (1 << j) - 1 < n; i++)
	// 		cout << sTable[i][j] << " ";
	// 	cout << "\n";
	// }


	ll L, R;
	// cin >> q;
	while (q--) {
		cin >> L >> R;
		cout << Query(L - 1, R - 1) << "\n";
	}
}

