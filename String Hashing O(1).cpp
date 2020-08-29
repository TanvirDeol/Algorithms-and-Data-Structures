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

int main() {
        //find number of occurences of substring p in string s
    string s,p; cin>>s>>p;
    int A = 47;
    vl hash(s.size(),(ll)0);
    vl pw(s.size(),(ll)0); //(A^K)%MOD
    hash[0]=s[0];
    pw[0]=1;
    for(int i=1;i<hash.size();i++){
        hash[i]=(((hash[i-1]%MOD)*A)+s[i])%MOD;
    }
    for(int i=1;i<pw.size();i++){
        pw[i]=((pw[i-1]%MOD)*A)%MOD;
    }
    vl chsh(p.size());
    chsh[0]=p[0];
    for(int i=1;i<p.size();i++){
        chsh[i]=(((chsh[i-1]%MOD)*A)+p[i])%MOD;
    }
    ll compHash = chsh[chsh.size()-1];
    int cnt=0;
    for(int i=s.size()-1;i>=(int)(p.size()-1);i--){
        if(i-p.size()==-1){
            ll h = hash[i]%MOD; 
            if(h==compHash)cnt++;
            continue;
        }
        ll mult = (hash[i-p.size()]*pw[p.size()])%MOD;
        ll h = (hash[i]-mult)%MOD;
        if(h==compHash)cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
