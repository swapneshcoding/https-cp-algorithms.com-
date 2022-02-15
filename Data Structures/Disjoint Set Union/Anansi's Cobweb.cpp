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


vector<int>Parent;
vector<int>Size;
int Connected_Components;

int find(int x) {
	if (x == Parent[x])
		return x;
	return Parent[x] = find(Parent[x]);
}

void Union(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b)
		return;
	Connected_Components -= 1;
	if (Size[a] < Size[b])
		swap(a, b);
	Parent[b] = a;
	Size[a] += Size[b];
}



int main()
{
	fastio;
	debugMode();
	// int t=1;cin>>t;while(t--)
	{
		int N, M;
		cin >> N >> M;
		vector<pair<int, int>>Thread(M + 1);
		for (int i = 1; i <= M; i++) {
			cin >> Thread[i].first >> Thread[i].second;
		}
		int Q;
		cin >> Q;
		vector<int> Queries(Q);
		vector<bool> attacked(M + 1, false);
		for (int i = 0; i < Q; i++) {
			cin >> Queries[i];
			attacked[Queries[i]] = true;
		}




		Connected_Components = N; // each node is saparate
		Parent.resize(N + 1);
		Size.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			Parent[i] = i;
			Size[i] = 1;
		}

		for (int i = 1; i <= M; i++) {
			if (attacked[i]) {
				// cout << i << "\n";
				continue;
			}
			Union(Thread[i].first, Thread[i].second);
		}

		// cout << Connected_Components << "\n";

		vector<int>Answer(Q);
		for (int i = Q - 1; i >= 0; i--) {
			Answer[i] = Connected_Components;
			int x = Thread[Queries[i]].first;
			int y = Thread[Queries[i]].second;
			Union(x, y);
		}


		for (int i = 0; i < Q; i++)
			cout << Answer[i] << " ";

	}




}
