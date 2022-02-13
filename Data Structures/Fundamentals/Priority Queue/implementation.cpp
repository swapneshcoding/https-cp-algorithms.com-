// Push an element with priority p
// Pop element with aximum priority
// Additional operations
// 1 remove an element with priority p
// get an element with max priority
// change priority of an element


// A binary tree is binary max heap if value of a node is atleast the value of its childs

#include<iostream>
#include<vector>
using namespace std;


class priorityQueue {                               //        1
public:												//     2     3
	vector<int>V;                                   //    4 5   6 7
	int Size;

	priorityQueue() {
		V.push_back(0); // 1 indexed array
		Size = 0;
	}

	int parent(int index) {
		return index / 2;
	}
	int L_child(int index) {
		return 2 * index;
	}
	int R_child(int index) {
		return 2 * index + 1;
	}

	void shift_up(int index) {
		while (index > 1 and V[parent(index)] < V[index]) {
			swap(V[parent(index)], V[index]);
			index = parent(index);
		}
		return;
	}
	void shift_down(int index) {
		int maxIndex = index;
		int L = L_child(index);
		if (L <= Size and V[L] > V[maxIndex])
			maxIndex = L;
		int R = R_child(index);
		if (R <= Size and V[R] > V[maxIndex])
			maxIndex = R;
		if (index != maxIndex) {
			swap(V[index], V[maxIndex]);
			shift_down(maxIndex);
		}
		return;
	}


	void insert(int n) {
		V.push_back(n);
		Size += 1;
		shift_up(Size);
	}

	void pop() {
		if (Size < 1)
			return;
		swap(V[1], V[Size]);
		Size -= 1;
		shift_down(1);
	}
	int top() {
		if (Size < 1)
			return INT_MIN;
		return V[1];
	}
	bool empty() {
		return Size < 1;
	}

};

int main() {
	priorityQueue Q;
	vector<int>V(20);
	for (auto&x : V) x = rand() % 100;
	for (auto x : V)
		Q.insert(x);

	while (!Q.empty()) {
		cout << Q.top() << " ";
		Q.pop();
	}
}
