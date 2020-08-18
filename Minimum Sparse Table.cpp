#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double,double>pd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<bool> vb;
#define setp ios_base::sync_with_stdio(0); cin.tie(0);
#define usaco(a,b) ofstream cout(a); ifstream cin(b);
#define FOR(i, a, b) for (int i=a; i<(b); i++) 
#define F0R(i, a) for (int i=0; i<(a); i++) 
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--) 
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(x) (int)(x).size() 
#define mp make_pair 
#define pb push_back 
#define fs first 
#define sc second 
#define lb lower_bound 
#define ub upper_bound 
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const ll MOD = 1000000007;
const ll INF = 1e18;
const int MAX = 1e6;

vi log_2;
vector<vi>sp;
int P;

int o1query(int l,int r){
    int len = r-l+1;
    int p = log_2[len];
    return min(sp[p][l],sp[p][r-(1<<p)+1]);
}
int lognquery(int l, int r){
    int len = r-l+1;
    int res = INT_MAX;
    int p;
    while(len){
        p = log_2[len];
        res = min(res,sp[p][l]);
        l+=p+1;
        len-=p;
    }
    return res;
}

int main() {
    int N; cin>>N;
    vi arr(N);
    F0R(i,N)cin>>arr[i];

    log_2.resize(N+1,0);    
    FOR(i,2,N+1) log_2[i]=log_2[i/2]+1;
    P = log_2[N];

    sp.resize(P+1,vi(N+1,0));
    for(int q=1;q<=P;q++){
        for(int i=0;i+(1<<q)<=N;i++){
            sp[q][i]=min(sp[q-1][i],sp[q-1][i+(1<<q-1)]);
        }
    }
    
 	return 0;
}
