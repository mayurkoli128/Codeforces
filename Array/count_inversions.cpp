// #include <memory.h>
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vec;

int global = 0;
void merge (vector<int>& nums, int l, int mid, int r) {
    vector<int> p1, p2;
    for (int i=l; i <= mid; ++i) p1.push_back (nums[i]);
    for (int i=mid+1; i <= r; ++i) p2.push_back (nums[i]);
    int ptr1 = 0, ptr2 = 0, s1=p1.size(), s2=p2.size();
    int inversion = 0;
    while (ptr1 < s1 && ptr2 < s2) {
        if (p1[ptr1] <= p2[ptr2]) {
            nums[l++] = p1[ptr1++];
        } else {
            inversion += (s1-ptr1);
            nums[l++] = p2[ptr2++];
        }
    }
    global += inversion;
    while (ptr1 < s1)    nums[l++] = p1[ptr1++];
    while (ptr2 < s2)    nums[l++] = p2[ptr2++];
}
void mergeSort (vec& nums, int l, int r) {
    if (l == r) {
        return ;
    }
    int mid = (l+r) >> 1;

    mergeSort(nums, l, mid);
    mergeSort(nums, mid+1, r);

    merge (nums, l, mid, r);
}
int main() {
    vector<int> vec = {8,3,1,2};
    mergeSort (vec, 0, vec.size()-1);

    for (int i=0; i < vec.size();++i) {
        cout << vec[i] << " ";
    }
    return 0;
}