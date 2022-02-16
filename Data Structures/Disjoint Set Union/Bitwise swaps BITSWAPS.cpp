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


class Disjoint_Set_Union {
private:
	vector<int>Parent;
	vector<int>Size;
	int n;
public:
	Disjoint_Set_Union(int nn) {
		n = nn;
		Parent.resize(n + 1);
		Size.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			Parent[i] = i;
			Size[i] = 1;
		}
	}

	int Find(int x) {
		while (Parent[x] != x) {
			Parent[x] = Parent[Parent[x]];
			x = Parent[x];
		}
		return x;
	}

	void Union(int x, int y) {
		int a = Find(x);
		int b = Find(y);
		if (a == b)
			return;
		if (Size[a] < Size[b])
			swap(a, b);
		Parent[b] = a;
		Size[a] += Size[b];
	}
};




int main()
{
	fastio;
	debugMode();
	int t = 1; cin >> t; while (t--)
	{
		Disjoint_Set_Union DSU(31);
		int n;
		cin >> n;
		vector<int>arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector<int>SortedArr(arr.begin(), arr.end());
		sort(SortedArr.begin(), SortedArr.end());

		for (int i = 0; i < n; i++)
			for (int j = 0; j <= 31; j++)
				for (int k = 0; k <= 31; k++)
					if ((arr[i] & (1ll << j)) and (arr[i] & (1ll << k)))
						DSU.Union(j, k);

		bool Possible = true;
		for (int i = 0; i < n; i++) {
			bool canSwap = false;
			for (int j = 0; j <= 31; j++) {
				for (int k = 0; k <= 31; k++) {
					if (DSU.Find(j) == DSU.Find(k) and (arr[i] & (1ll << j)) and (SortedArr[i] & (1ll << k))) {
						canSwap = true;
						break;
					}
				}
			}
			if (!canSwap) {
				Possible = false;
				break;
			}
		}

		cout << (Possible ? "YES\n" : "NO\n");
	}
}
