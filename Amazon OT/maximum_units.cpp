#include<bits/stdc++.h>
using namespace std ;

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& A, vector<int>& B) {
        return A[1] > B[1] ;
    }) ;
    int ans = 0 ;
    for (auto& boxType : boxTypes) {
        if (truckSize - boxType[0] >= 0) {
            ans += boxType[0] * boxType[1] ;
            truckSize -= boxType[0] ;
        } else {
            ans += truckSize * boxType[1] ;
            break ;
        }
    }
    return ans ;
}
int main() {
    return 0 ;
}