#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cstring>
#include <string>
using namespace std;

typedef pair<int,int> pairii;
typedef long long llong;

#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))
#define pb push_back

// This problem can be reduced to a max independent set problem.
// A max IS problem is equivalent to a min VC problem.
// In bipartite graph, a min VC problem is also a max matching problem.

typedef vector<int> VI;
typedef vector<VI> VVI;

bool bpm(int i, const VVI &w, VI &mr, VI &mc, VI &vis) {
  FORZ(j,w[i].size()) {
    if (w[i][j] && !vis[j]) {
      vis[j] = true;
      if (mc[j] < 0 || bpm(mc[j], w, mr, mc, vis)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int maxBPM(const VVI &w) {
  VI mr = VI(w.size(), -1);
  VI mc = VI(w[0].size(), -1);
  int res = 0;
  for (int i = 0; i < w.size(); i++) {
    VI vis(w[0].size());
    if (bpm(i, w, mr, mc, vis)) res++;
  }
  return res;
}

vector<pairii> cv, dv;
VVI G;

void solve() {
  cv.clear();
  dv.clear();
  G.clear();
  int c,d,v;
  scanf("%d%d%d",&c,&d,&v);
  FORZ(V,v) {
    char s1[10],s2[10];
    scanf("%s %s",s1,s2);
    int a = atoi(s1+1);
    int b = atoi(s2+1);
    if (s1[0]=='C') {
      cv.pb(pairii(a,b));
    } else {
      dv.pb(pairii(a,b));
    }
  }
  int n = (int)cv.size();
  int m = (int)dv.size();
  G.resize(n,VI(m,0));
  FORZ(i,n) {
    FORZ(j,m) {
      if (cv[i].first == dv[j].second || cv[i].second == dv[j].first) {
        G[i][j]=1;
      }
    }
  }
  int res = n+m-maxBPM(G);
  printf("%d\n",res);
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int t;
  scanf("%d",&t);
  FORZ(i,t) solve();
  return 0;
}
