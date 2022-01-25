#include<bits/stdc++.h>
using namespace std;

#define P 1000000007
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

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B) {
	vector<vector<ll>> C = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % P;
	return C;
}

vector<vector<ll>> power(vector<vector<ll>> M, ll n) {
	vector<vector<ll>> R = {{1, 0}, {0, 1}};
	while (n > 0) {
		if (n & 1)
			R = mul(R, M);
		M = mul(M, M);
		n >>= 1;
	}
	return R;
}


ll fib(ll n) {
	if (n <= 1)
		return n;
	vector<vector<ll>>M = {{1, 1}, {1, 0}};
	return power(M, n)[1][0];
}




int main()
{
	fastio;
	debugMode();
	int t = 1; cin >> t; while (t--)
	{
		ll N, M;
		cin >> N >> M;
		if (N == 0)
			cout << fib(M + 2) - 1 << "\n";
		else if (N == M)
			cout << fib(M) << "\n";
		else
			cout << (fib(M + 2) - 1 - (fib(N + 2 - 1) - 1) + P) % P << "\n";


	}




}
