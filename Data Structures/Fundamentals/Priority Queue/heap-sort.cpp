#include<iostream>
#include <time.h>
#include <vector>
using namespace std;

void shift_down(vector<int>&V, int i, int Size) {
	int next = i;
	int L = 2 * i + 1;
	if (L <= Size and V[L] > V[next])
		next = L;
	int R = 2 * i + 2;
	if (R <= Size and V[R] > V[next])
		next = R;
	if (i != next) {
		swap(V[i], V[next]);
		shift_down(V, next, Size);
	}
	return;
}

void BuildHeap(vector<int>&V) {
	int Size = V.size() - 1; // zero to n-1
	for (int j = Size / 2; j >= 0; j--) {
		shift_down(V, j, Size);
	}
}

void HeapSort(vector<int>&V) {
	int Size = V.size() - 1;
	BuildHeap(V);
	for (int i = 0; i < V.size(); i++) {
		swap(V[0], V[Size]);
		Size--;
		shift_down(V, 0, Size);
	}
}

bool Sorted(vector<int>&V) {
	for (int i = 1; i < V.size(); i++)
		if (V[i] < V[i - 1])
			return false;
	return true;
}

int main() {
	srand(0);
	vector<int>V(int(1e6));
	for (auto&x : V) x = rand() % 100;

	clock_t t;
	t = clock();
	HeapSort(V);

	t = clock() - t;
	printf("Run-Time: (%f seconds)\n", ((float)t) / CLOCKS_PER_SEC);
	cout << "Sorted(V): " << (Sorted(V) ? "True\n" : "False\n");

	// for (auto x : V) cout << x << " "; cout << endl;
}


/*
Run-Time: (0.605000 seconds)
Sorted(V): True
[Finished in 1.4s]
*/
