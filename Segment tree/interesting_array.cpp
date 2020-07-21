#include <iostream>
#include <vector>
using namespace std;

typedef long long int ln;
typedef vector<int> vec;
int const N = 100002;

vec segment(5*N);
vec result(N);
vec L(N), R(N), VAL(N);

void update(int l, int r, int lx, int rx, int val, int index, int size) {
	if(lx >= l && rx <= r) {
		if(index < size*2 - 1)
			segment[index] |= val;
		return;
	}
	int mid = (lx + rx) >> 1;

	if(r <= mid) {
		update(l, r, lx, mid, val, index*2 + 1, size);
	}
	else if(mid < l) {
		update(l, r, mid + 1, rx, val, index*2 + 2, size);
	} 
	else {
		update(l, r, lx, mid, val, index*2 + 1,size);
		update(l, r, mid + 1, rx, val, index*2 + 2, size);
	}
}
int query(int at, int lx, int rx, int index) {
	if(lx - rx == 0) {
		return segment[index];
	} 
	int mid = (lx + rx) >> 1;

	int val = segment[index];

	if(mid >= at) {
		return val | query(at, lx, mid, index*2 + 1);
	}
	return val | query(at, mid + 1, rx, index*2 + 2);
}
void result_array(int N, int size) {
	for(int i = 0; i < N; ++i) {
		result[i] = query(i, 0, size - 1, 0);
	}
}
void build(vector<int>& vec, int lx, int rx, int index, int N) {
	if(lx - rx == 0) {
		if(N > lx)
			segment[index] = vec[lx];
		return;
	}
	int mid = (lx + rx) >> 1;

	build(vec, lx, mid, index*2 + 1, N);
	build(vec, mid + 1, rx, index*2 + 2, N);

	segment[index] = (segment[index*2 + 1] & segment[index*2 + 2]);
}
int get_or(int l, int r, int lx, int rx, int index) {
	if(l > rx || r < lx) {
		return INT32_MAX;
	}
	if(lx >= l && rx <= r)  return segment[index];

	int mid = (lx + rx) >> 1;

	return (get_or(l, r, lx, mid, index*2 + 1) & get_or(l, r, mid + 1, rx, index*2 + 2));
}

bool is_valid(vector<int> vec, int size, int N, int M) {
	build(vec, 0, size - 1, 0, N);
	// check...
	bool flag = true;

	for(int i = 0; i < M; ++i) {
		int res = get_or(L[i], R[i], 0, size - 1, 0);

		//cout << res << " " << VAL[i] << "\n";

		if(res != VAL[i]) {
			flag = false;
		}
	}
	return flag;
}
int main() {
	int N, M;
	cin >> N >> M;	
	int size = 1;

	while(size < N) {
		size *= 2;
	}
	for(int i = 0; i < M; ++i) {
		int l, r, val;
		cin >> l >> r >> val;
		L[i] = --l;
		R[i] = --r;
		VAL[i] = val;
		update(l, r, 0, size - 1,val, 0, size);
	} 
	result_array(N, size);

	if(is_valid(result, size, N, M)) {
		cout << "YES\n";
		for(int i = 0; i < N; ++i) {
			cout << result[i] << " ";
		}
		cout << "\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}