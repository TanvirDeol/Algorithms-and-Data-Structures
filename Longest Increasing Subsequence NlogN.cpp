#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
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
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX = 4294967295;


int main() {
    int N; cin>>N;
    vi arr(N);
    F0R(i,N)cin>>arr[i];
    vi seq;
    seq.pb(arr[0]);
    for(int i=1;i<N;i++){
        if(arr[i]>seq.back())seq.pb(arr[i]);
        else {
            int idx = lb(all(seq),arr[i])-seq.begin();
            seq[idx]=arr[i];
        }
    }
    cout<<seq.size()<<endl;
    return 0;
}
