// https://www.spoj.com/problems/DIVSUM/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
#define ff first
#define ss second
#define pb push_back
#define all(v) v.begin(), v.end()

#define fastio   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


ll divSum(ll n) {
	ll Ans = 1;
	int count = 0;
	while (n % 2 == 0) {
		count += 1;
		n /= 2;
	}
	if (count)
		Ans *= (pow(2, count + 1) - 1) / (2 - 1);
	for (int i = 3; i * i <= n; i += 2) {
		count = 0;
		while (n % i == 0) {
			count += 1;
			n /= i;
		}
		if (count)
			Ans *= (pow(i, count + 1) - 1) / (i - 1);
	}
	if (n > 1)
		Ans *= (1 + n);
	return Ans;
}



int main()
{
	fastio;
	debugMode();
	int t = 1, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << divSum(n) - n << "\n";
	}
}
