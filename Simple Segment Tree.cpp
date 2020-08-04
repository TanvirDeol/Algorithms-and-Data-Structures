#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
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

const int N = 50;
int n;
vi arr;

void build() {
  for (int i = n - 1; i > 0; --i) arr[i] = arr[i*2] + arr[(i*2)+1];
}

void modify(int p, int value) {  // set value at position p
  for (arr[p += n] = value; p > 1; p/=2) arr[p/2] = arr[p] + arr[p^1]; 
  //XOR turns even to odd and vice versa
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l /=2, r /=2) {
    if (l&1) res += arr[l++];
    if (r&1) res += arr[--r];
  }
  return res;
}

int main() {
  cin>>n;
  arr.resize(2*n);
  int x;
  for (int i = 0; i < n; ++i) {cin>>x; arr[i+n]=x;}
  build();
  modify(0, 1);
  cout<<query(3, 7)<<endl;
  return 0;
}
