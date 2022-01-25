#include<bits/stdc++.h>
using namespace std;

#define P 1000000007
#define ll unsigned long long


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
	ll N;
	cin >> N;
	cout << fib(N) << "\n";
}
