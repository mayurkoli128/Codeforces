#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vec;
const int N = 1000000;

vec heap(N);
vector<string> operations_list;
int size = 0;

void perculate_up(int index) {
	if(index == 0) {
		return;
	}
	int parent = (index - 1) / 2;

	if (heap[parent] > heap[index]) {
		swap(heap[parent], heap[index]);
		perculate_up(parent);
	}
} 
void perculate_down(int index) {
	int l_child = index*2 + 1;
	int r_child = index*2 + 2;

	if(l_child >= size) {
		return;
	}
	int swap_with = l_child;

	if(r_child < size && heap[l_child] > heap[r_child]) {
		swap_with = r_child;
	}

	if(heap[index] > heap[swap_with]) {
		swap(heap[index], heap[swap_with]);
		perculate_down(swap_with);
	}
}
int getMin() {
	return heap[0];
}

void insert(int val) {
	operations_list.push_back("insert " + to_string(val));
	heap[size++] = val;
	perculate_up(size - 1);
}
void removeMin() {
	operations_list.push_back("removeMin");
	swap(heap[0], heap[size-- - 1]);
	perculate_down(0);
}

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

	int N;
	cin >> N;

	for(int i = 0; i < N; ++i) {
		string operation;
		int val;
		cin >> operation;

		if(operation == "insert") {
			cin >> val;
			insert(val);
		} else if(operation == "getMin") {
			cin >> val;
			// operations_list.push_back("getMin " + to_string(val));
			while (size > 0 && getMin() < val)
			{
				removeMin();
			}
			if(size <= 0 || getMin() != val)
				insert(val);

			operations_list.push_back("getMin " + to_string(getMin()));

		} else if(operation == "removeMin") {
			if(size <= 0) {
				insert(0);
			} 
			removeMin();
		}
	}
	cout << operations_list.size() << "\n";
	for(int i = 0; i < operations_list.size(); ++i) {
		cout << operations_list[i] << "\n";
	}
	return 0;
}

// 4
// insert 1
// insert 1
// removeMin
// getMin 2
// outputCopy
// 6
// insert 1
// insert 1
// removeMin
// removeMin
// insert 2
// getMin 2