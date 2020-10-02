
// find longest subarray which follow -> 2*min >= max
// sliding window, segment tree

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> nums;
typedef vector<vector<char>> vec;

vector<pair<int, int>>seg;
int size=1;

void build (vector<int>& nums, int l, int r, int index) {
    if (l-r == 0) {
        if (l < nums.size())
            seg[index]={nums[l], nums[l]};
        return;
    }
    int mid=(l+r)>>1;

    build (nums, l, mid, index*2+1);
    build (nums, mid+1, r, index*2+2);

    seg[index]={min (seg[index*2+1].first,seg[index*2+2].first), max (seg[index*2+1].second,seg[index*2+2].second)};

    return;
}
pair<int, int> query (int lx, int ly, int l, int r, int index) {
    if (lx > r || ly < l) {
        return {INT32_MAX, INT32_MIN};
    }
    if (l >= lx && r <= ly) {
        return seg[index];
    }
    int mid=(l+r)>>1;

    auto p1 = query (lx, ly, l, mid, index*2+1);
    auto p2 = query (lx, ly, mid+1, r, index*2+2);

    return {min (p1.first, p2.first), max (p1.second, p2.second)};
}
int solve(vector<int>& nums, int n) {
    int l, r;
    l=r=0;
    int cost=INT32_MAX;
    while (n > size) {
        size *= 2;
    }
    seg.assign(size*2-1, {0, 0});
    build (nums, 0, size-1, 0);
    while (r < n) {
        auto p = query (l, r,0, size-1, 0);
        cout << p.first << " " << p.second << "\n";
        if (p.first*2 >= p.second) {
            cost=min (cost, n-(r-l+1));
            r++;
        } else {
            l++;
        }
    }
    return cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int>nums(n);
        for (int i=0; i<n; ++i) {
            int in;
            cin >> in;
            nums[i]=in;
        }
        sort (nums.begin(), nums.end());
        cout << solve (nums, n)<<"\n";
        seg.clear();
        size=1;
    }
}
