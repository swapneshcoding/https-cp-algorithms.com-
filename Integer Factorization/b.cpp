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

int fermat(int n) {
	int a = ceil(sqrt(n));
	int b2 = a * a - n;
	int b = int(sqrt(b2));
	while (b * b != b2) {
		a = a + 1;
		b2 = a * a - n;
		b = int(sqrt(b2));
	}
	
	return a - b;
}

int main() {
	debugMode();
	cout << fermat(24);

}

