#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double lld;
int __i__,__j__;
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
ll MOD = 1000000007;


vector<int>arr;
int ternary (int l,int r){
    while(r-l>=3){ //cant divide int by 3
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        if(arr[m1]>arr[m2])l = m1;
        else r = m2;
    }
    int mn = INT_MAX; //loop thru margin of error to find actual min
    for(int i=l;i<min((int)arr.size(),l+2);i++)mn=min(mn,arr[i]);
    return mn;
}
int main() {
    arr = {18,13,12,9,8,5,2,6,10,12,19,22}; //arr is unimodal, has min in interval
    cout<<ternary(0,arr.size()-1)<<endl;
    return 0;
}
