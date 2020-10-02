#include <bits/stdc++.h>
#define all(nums) nums.begin(), nums.end()
typedef long long int ll;
const int imax = INT32_MAX;
const int imin = INT32_MIN;
using namespace std;
const int mx = 10e5 + 10;

vector<ll>segment;
vector<ll>nums;
ll size=1;

ll func (ll a, ll b) {
    return a^b;
}
void build (ll l, ll r, ll index) {
    ll n=nums.size();
    if (r-l==0) {
        if (r<n) {
            segment[index]=nums[r];
        }
        return ;
    }
    ll mid=(l+r)>>1;
    build (l, mid, index*2+1);
    build (mid+1, r, index*2+2);
    segment[index]=func(segment[index*2+1], segment[index*2+2]);
}
ll query(ll lx, ll ly, ll l, ll r, ll index) {
    if (l>ly || r < lx) {
        return 0;
    }
    if (l>=lx && r<=ly) {
        return segment[index];
    } 
    ll mid=(l+r)>>1;
    ll x=query (lx, ly, l, mid, index*2+1);
    ll y=query (lx, ly, mid+1, r, index*2+2);
    return func (x, y);
}
void update(ll at, ll l, ll r, ll index) {
    ll n=nums.size();
    if (l-r==0) {
        segment[index]=nums[at];
        return ;
    }
    ll mid=(l+r)>>1;
    if (at<=mid) {
        update (at, l, mid, index*2+1);
    } else {
        update (at, mid+1, r, index*2+2);
    }
    segment[index]= func (segment[index*2+1], segment[index*2+2]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) {
        ll n,q;
        cin>>n>>q;
        nums.resize(n);
        for(ll& in:nums)   cin>>in;

        while(size<n) {
            size*=2;
        }
        segment.resize(2*size-1, 0);
        build(0, n-1, 0);

        while (q--) {
            ll c=2;
            // cin>>c;
            if(c==2) {
                ll l, r;  
                cin>>l>>r;
                l--, r--;
                cout<<query (l, r, 0, n-1, 0)<<"\n";
            }// else {
            //     ll k, u;
            //     cin>>k>>u;
            //     k--; 
            //     nums[k]=u;
            //     update (k, 0, n-1, 0);
            // }
        }
    }
    return 0;
}
// 8
// 2 5 1 4 8 3 2 5