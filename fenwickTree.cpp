#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long double ll;

vector<int>B1;
vector<int>B2;
int N;

void add(vector<int>&b, int idx, int x) {
    while (idx <= N) {
        b[idx] += x;
        idx += (idx) & (-idx);
    }
}

// client uses this
void range_add(int l, int r, int x){
    add(B1, l, x);
    add(B1, r+1, -x);
    add(B2, l, x*(l-1));
    add(B2, r+1, -x*r);
}

int sum(vector<int>&b, int idx){
    int total = 0;
    while (idx > 0) {
        total += b[idx];
        idx -= (idx) & (-idx);
    }
    return total;
}

int prefix_sum(int idx){
    return sum(B1, idx)*idx -  sum(B2, idx);
}

// client uses this
int range_sum(int l, int r){
    return prefix_sum(r) - prefix_sum(l-1);
}

int main() {
    cin >> N;
    B1.resize(N+1,0);
    B2.resize(N+1,0);
    char c; 
    int l,r,x;
    while(scanf(" %c",&c) == 1) {
        if (c == 'A') {
            scanf("%d %d %d", &l, &r, &x);
            range_add(l,r,x);
        } 
        else if (c == 'S'){
            scanf("%d %d", &l, &r);
            cout << range_sum(l, r) << endl;
        }
    }
    return 0;
}
