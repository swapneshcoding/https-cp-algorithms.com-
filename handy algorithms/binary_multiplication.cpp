#include<bits/stdc++.h>
using namespace std;
inline void debugMode() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}




template<typename T>
T binary_multiplication(T a, T b, T mod) {
	T res = 0;
	while (b) {
		if (b & 1)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}




int main() {
	debugMode();
	cout << binary_multiplication<unsigned long long>(11111111111111111, 11111111111111111, ULLONG_MAX);

}

