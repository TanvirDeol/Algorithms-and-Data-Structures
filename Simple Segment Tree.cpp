#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long double ll;


void add(vector<int> &seg, int len, int idx, int val) { // 1-based indexing
    seg[idx+=len]+=val;
    for (idx/=2;idx>=1;idx/=2) 
    seg[idx] = seg[2*idx] + seg[2*idx+1]; 
}

ll query(vector<int> &seg, int len, int l, int r) {  //interval [l, r]
  ll res = 0; l+=len; r+=len;
  while(l<=r){
      if(l&1)res+=seg[l++];
      if(!(r&1))res+=seg[r--];
      l/=2;r/=2;
  }
  return res;
}

int main() {
  int N;
  cin>>N;
  vector<int> segs; 
  segs.resize(2*(N+5));
  char c; 
  int a,b;
  while (true) {
      scanf("%c %d %d", &c, &a, &b);
      if (c == 'A'){
          add(segs, N, a, b);
      }
      else if (c == 'Q') {
          cout << "SUM: " << query(segs, N, a, b) << endl;
      }
  }
  return 0;
}
