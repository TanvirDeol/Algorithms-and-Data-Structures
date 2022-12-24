#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+5;
int tree[MAXN*4];
int lazy[MAXN*4];

void update(int pos, int s, int e, int l, int r, int val) {
    if (lazy[pos] != 0) {
        tree[pos] += (e - s + 1) * lazy[pos];
        if (s != e) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (s > e || s > r || e < l) {
        return;
    }
    if (s >= l && e <= r) {
        seg[pos] += (e - s + 1) * val;
        if (s != e) {
            lazy[pos * 2] += val;
            lazy[pos * 2 + 1] += val;
        }
        return;
    }
    int mid = s + (e - s)/2;
    update(pos * 2, s, mid, l, r, val);
    update(pos * 2 + 1, mid + 1, end, l, r, val);
    seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];    
}

int query(int pos, int s, int e, int l, int r) {
    if (s > e || s > r || e < l) {
        return 0;
    }
    if (lazy[pos] != 0) {
        tree[pos] += (e - s + 1) * lazy[pos];
        if (s != e) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (s >= l && e <= r) {
        return seg[pos];
    }
    int mid = s + (e - s)/2;
    int p1 = query(pos * 2, s, mid, l, r);
    int p1 = query(pos * 2 + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    int N,M;
    cin>>N>>M;
    vector<int>a(N,0);
    // populate tree with a[] if needed
    memset(tree, 0, MAXN*4);
    memset(marked, false, MAXN*4);
    int x, l, r, val;
    while(M--) {
        cin>>x>>l>>r;
        if (x == 0) {
            cin>>val;
            update(1, 0, N-1, l-1, r-1, val);
        } 
        else if (x == 1) {
            printf("%d\n", query(1, 0, N-1, l-1, r-1));
        }
    }
    return 0;
}
