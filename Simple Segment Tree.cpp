#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long double ll;


int N; 

void add(vector<int> &seg, int idx, int val) { // 1-based indexing
    seg[idx+=N]+=val;
    for (idx/=2;idx>=1;idx/=2) 
    seg[idx] = seg[2*idx] + seg[2*idx+1]; 
}

ll query(vector<int> &seg, int l, int r) {  //interval [l, r]
  ll res = 0; l+=N; r+=N;
  while(l<=r){
      if(l&1)res+=seg[l++];
      if(!(r&1))res+=seg[r--];
      l/=2;r/=2;
  }
  return res;
}

int main() {
  cin>>N;
  vector<int> segs; 
  segs.resize(2*(N+1));
  char c; 
  int a,b;
  while (true) {
      scanf("%c %d %d", &c, &a, &b);
      if (c == 'A'){
          add(segs, a, b);
      }
      else if (c == 'Q') {
          cout << "SUM: " << query(segs, a, b) << endl;
      }
  }
  
  
  return 0;
}
