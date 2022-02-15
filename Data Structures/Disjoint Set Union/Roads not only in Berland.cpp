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



vector<int>parent;
vector<int>Size;

int find(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}


void merge(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (Size[a] < Size[b])
		swap(a, b);
	parent[b] = a;
	Size[a] += Size[b];
}



int main()
{
	fastio;
	debugMode();
	// int t=1;cin>>t;while(t--)
	{

		int n;
		cin >> n;
		parent.resize(n + 1);
		Size.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			Size[i] = 1;
		}

		vector<pair<int, int>>close; // close unnecessary roads 
		vector<pair<int, int>>make;  // these roads are not connected
		// size(close) = size(make) because a connected tree has atmost n-1 edges

		int x, y;
		for (int i = 1; i < n; i++) {
			cin >> x >> y; // a road
			if (find(x) == find(y)) {// there is already an alternative road
				close.push_back(make_pair(x, y));
			}
			else
				merge(x, y); 
		}

		for (int i = 2; i <= n; i++) {
			if (find(i) == find(1)) // already connected by a road
				continue;
			else {
				merge(i, 1);
				make.push_back(make_pair(i, 1));
			}
		}

		cout << make.size() << "\n";;
		for (int i = 0; i < make.size(); i++) { // close a road and make a road
			cout << close[i].first << " " << close[i].second << " " << make[i].first << " " << make[i].second << "\n";
		}



	}


}
