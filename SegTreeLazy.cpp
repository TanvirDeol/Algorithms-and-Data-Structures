#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long double ll;

const int MAXN = 1e3+5;
int tree[MAXN*4];
bool marked[MAXN*4] = {0};

void pushup(int pos) {
    tree[pos] = tree[pos*2] + tree[pos*2 + 1];
}

void build(int a[], int pos, int tree_l, int tree_r) {
	if (tree_l == tree_r){
		tree[pos] = a[tree_l];
	}  
	else {
	    int tree_m = (tree_l + tree_r) / 2;
	    build(a, pos*2, tree_l, tree_m);
	    build(a, (pos*2)+1, tree_m + 1, tree_r);
	    pushup(pos);
	}
}

void pushdown(int pos) {
    if (marked[pos]) {
        tree[pos*2] = tree[pos*2 + 1] = tree[pos];
        marked[pos*2] = true;
        marked[pos*2 + 1] = true;
        marked[pos] = false;
    }
}

void update(int pos, int tree_l, int tree_r, int l, int r, int val) {
    if (l > r) {
        return;
    }
    if (l == tree_l && r == tree_r) {
        tree[pos] = val;
        marked[pos] = true;
    }
    else {
        pushdown(pos);
        int tree_m = (tree_l + tree_r) / 2;
        update(pos*2, tree_l, tree_m, l, min(r, tree_m), val);
        update(pos*2 + 1, tree_m + 1, tree_r, max(l, tree_m + 1), r, val);
        pushup(pos);
    }
}

int query(int pos, int tree_l, int tree_r, int l, int r) {
    if (l > tree_r || r < tree_l) {
        return 0;
    }
    if (l <= tree_l && r >= tree_r) {
        return tree[pos];
    }
    int tree_m = (tree_l + tree_r) / 2;
    pushdown(pos);
    return query(pos*2, tree_l, tree_m, l, r) + query(pos*2 + 1, tree_m + 1, tree_r, l, r);
}


int main() {
    int a[5] = {1,2,3,4,5};
    build(a, 1, 0, 5-1);
    char c;
    int l, r, val;
    while(scanf(" %c", &c) == 1) {
        if (c == 'U') {
            scanf("%d %d %d", &l, &r, &val);
            update(1, 0, 5-1, l, r, val);
        } 
        else if (c == 'Q') {
            scanf("%d %d", &l, &r);
            cout << "SUM: "<< query(1, 0, 5-1, l, r) << endl;
        }
    }
    return 0;
}

