#include <bits/stdc++.h>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pdd;
typedef pair<double,double>pd;
typedef vector<int> vi;
typedef vector<ld> vdd;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
#define setp ios_base::sync_with_stdio(0); cin.tie(0)
#define usaco(a,b) ofstream cout(a); ifstream cin(b);
#define FOR(i, a, b) for (int i=a; i<(b); i++) 
#define F0R(i, a) for (int i=0; i<(a); i++) 
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--) 
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size() 
#define mkp make_pair 
#define pb push_back 
#define fs first 
#define sc second 
#define lb lower_bound 
#define ub upper_bound 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 4294967295;

namespace io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
    }
}

using namespace io;

int N;
unordered_map<int,vi>graph; //node ids must be distinct
int logn; 
vector<vi>up; //ancestor table for 2^ith ancestor
vi lvl; //depth arr

void dfs(int u,int par){ //creates ancestor table
    up[u][0]=par;
    for(int i=1;i<=logn;i++) up[u][i]=up[up[u][i-1]][i-1]; //recurrence formula
    for(int x:graph[u]){ //dfs for all edges
        if(x!=par){
            lvl[x]=lvl[u]+1;
            dfs(x,u); 
        }
    }
}
int lca(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v); //make u always below v
    for(int i=logn;i>=0;i--){ //move u to the same lvl as v
        if(lvl[u]-pow(2,i)<=lvl[v]){
            u=up[u][i];
        }
    }
    if(u==v)return u; //for if v = ancestor(u)
    for(int i=logn;i>=0;i--){ //goes up tree to find x, which is !ancestor of u and v
        if(up[u][i]!=up[v][i]){
            u=up[u][i]; v=up[v][i];
        }
    }
    return up[u][0]; //returns parent of x
}

int main() {
    cin>>N;
    logn = (int)ceil(log2(N));
    up.resize(N+1,vi(logn+1,-1));
    lvl.resize(N+1);
    int a,b;
    F0R(i,N-1){
        cin>>a>>b;
        graph[a].pb(b);
    }
    dfs(1,1);
    print2dArr(up,up.size(),up[0].size());
    cout<<lca(4,5)<<endl;
    return 0;
}
