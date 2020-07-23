#include <iostream>
#include <vector>


using namespace std;

typedef long long int ln;
const ln st = 1000000007;

class hashing {
    vector<ln> pow;
    vector<ln> hash;
    ln P;
    ln MOD;
    ln size;

public :
    hashing(ln P, ln MOD, string s) {
        this->P = P;
        this->MOD = MOD;
        size = s.size();

        pow.assign(size, 0LL);
        hash.assign(size, 0LL);

        initialize(s);
    }
    ln initialize(string s) {
        pow[0] = 1;
        hash[0] = s[0] - 'a' + 1;

        for(ln i = 1; i < size; ++i) {
            pow[i] = ((pow[i - 1] % MOD) * (P % MOD)) % MOD;
            hash[i] = (hash[i - 1] + (s[i] - 'a' + 1)*pow[i]) % MOD;
        }
    }
    //get hash in rage i to j including
    ln get_hash(ln l, ln r) {
        
        if(l == 0) {
            return hash[r];
        }
        // ln res = ((hash[r] - hash[l - 1])) % MOD;
        
        // if(res<0) return (res+MOD) / pow[l];
        // return res / pow[l];

        return (hash[r] - (hash[l - 1] * pow[r - l + 1]) % MOD + MOD) % MOD;

    }
};
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ln T;
    cin >> T;
    
    while (T--)
    {
        string s;
        cin >> s;
        ln size = s.size();
        hashing h(31, st, s);
        ln cnt = 0;

        for(ln i = 2; i < size; i += 2) {
            ln p1 = 0;
            ln p2 = i / 2;
            ln p3 = i;
            ln p4 = (size + i) / 2;

            ln h1 = h.get_hash(p1, p2 - 1);
            ln h2 = h.get_hash(p2, p3 - 1);
            ln h3 = h.get_hash(p3, p4 - 1);
            ln h4 = h.get_hash(p4, size - 1);

            if(h1 == h2 &&  h3 == h4) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
