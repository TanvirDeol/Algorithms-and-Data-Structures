#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long double ll;

const int MAXN = 1e3+5;
int tree[MAXN*4];
bool marked[MAXN*4] = {0};

// helper method to make parent node get sum of its two children
void pushup(int pos) {
    tree[pos] = tree[pos*2] + tree[pos*2 + 1];
}

// recursive build function
// initially called by client with args build(a, 1, 0, N-1);
// starts from root, goes down to children, populates leaf nodes
//      with elements from a[]
void build(int a[], int pos, int tree_l, int tree_r) {
	if (tree_l == tree_r){
		tree[pos] = a[tree_l];
	}  
	else {
	    int tree_m = (tree_l + tree_r) / 2;
	    build(a, pos*2, tree_l, tree_m);
	    build(a, (pos*2)+1, tree_m + 1, tree_r);
	    //tree[pos] = 0;
	    pushup(pos);
	}
}

// helper method to push node and marked information from a node to its 2 children
// assigns same node value to child nodes
// marks child nodes to true and itself to false
void pushdown(int pos) {
    if (marked[pos]) {
        tree[pos*2] = tree[pos*2 + 1] = tree[pos];
        marked[pos*2] = true;
        marked[pos*2 + 1] = true;
        marked[pos] = false;
    }
}


// initially called by client with args update(1, 0, N-1, l, r, val);
// if l and r match with current tree bounds (tree_l, tree_r) then set that node to val
//      mark that node true to signify that the entire subtree has single value "val", and 
//      it is not fully propagated (lazy)
// if tree bounds are partially inside l and r, then push node info to its children
//      then split bounds and l, r, and recursively call update
// this way only the subtrees fully inside l and r are lazily assigned a val, very efficient
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

// initially called by client with args query(1, 0, N-1, l, r);
// if l and r have no overlap with bounds, return 0
// if bounds are inside l and r, return node val
// otherwise split the tree bounds and calculate query() again
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

