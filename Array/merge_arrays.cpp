#include<iostream>
#include <vector>
using namespace std;

void fix(vector<int>& arr) {
    int size = arr.size();

    for(int i = 0; i < size - 1; ++i) {
        if(arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}
void merge(vector<int>& arr1, vector<int>& arr2) {
    int size1 = arr1.size(), size2 = arr2.size();
    int p1 = 0;

    while(p1 < size1) {
        if(arr1[p1] > arr2[0]) {
            swap(arr1[p1], arr2[0]);
            p1++;
            fix(arr2);
        } else {
            p1++;
        }
    }

}
void print(vector<int>& vec1, vector<int>& vec2) {
    for(int i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << " ";
    }
    for(int i = 0; i < vec2.size(); ++i) {
        cout << vec2[i] << " ";
    }
    cout << "\n";
}
int main()
 {
     int T;
     cin >> T;
     
     while(T--) {
	    
	    
	    int x, y;
	    cin >> x >> y;
	    vector<int> arr1(x), arr2(y);
	    
	    for(int i = 0; i < x; ++i) {
	        int in;
	        cin >> in;
	        arr1[i] = in;
	    }
	    for(int i = 0; i < y; ++i) {
	        int in;
	        cin >> in;
	        arr2[i] = in;
	    }
	    
	    merge(arr1, arr2);
	    print(arr1, arr2);
     }
	
	return 0;
}