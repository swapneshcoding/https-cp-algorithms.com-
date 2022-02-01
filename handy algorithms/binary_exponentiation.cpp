#include<bits/stdc++.h>
using namespace std;
inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}


template<typename T>
T binary_exponentiation(T a, T b, T mod) {
	T res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}


int main() {
	debugMode();
	cout << binary_exponentiation<unsigned long long>(2, 3, 10);
}

