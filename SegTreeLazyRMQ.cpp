void update(int pos, int s, int e, int l, int r, ll val) {
    if (lazy[pos] != 0) {
        tree[pos] += lazy[pos];
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
        tree[pos] +=  val;
        if (s != e) {
            lazy[pos * 2] += val;
            lazy[pos * 2 + 1] += val;
        }
        return;
    }
    int mid = s + (e - s)/2;
    update(pos * 2, s, mid, l, r, val);
    update(pos * 2 + 1, mid + 1, e, l, r, val);
    tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);    
}
 
ll query(int pos, int s, int e, int l, int r) {
    if (s > e || s > r || e < l) {
        return INT_MAX;
    }
    if (lazy[pos] != 0) {
        tree[pos] += lazy[pos];
        if (s != e) {
            lazy[pos * 2] += lazy[pos];
            lazy[pos * 2 + 1] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (s >= l && e <= r) {
        return tree[pos];
    }
    int mid = (e+s)/2;
    ll p1 = query(pos * 2, s, mid, l, r);
    ll p2 = query(pos * 2 + 1, mid + 1, e, l, r);
    return min(p1, p2);
}
