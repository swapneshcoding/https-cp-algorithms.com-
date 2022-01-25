/*
https://en.wikipedia.org/wiki/Pisano_period

fibonacci modulo (P = 10**9 + 7)
F(0) = 0
F(1) = 1
F(2*P+2 = 2000000016) = 0
F(2*P+3 = 2000000017) = 1
*/

#include<bits/stdc++.h>
using namespace std;

#define P 1000000007
#define ll unsigned long long

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
	debugMode();
	string S;
	ll N;

	cin >> S;
	{
		N = 0;
		for (ll i = 0; i < S.length(); i++)
			N = (N * 10 + (S[i] - '0')) % 2000000016;

		cout << fib(N) << "\n";
	}
}



