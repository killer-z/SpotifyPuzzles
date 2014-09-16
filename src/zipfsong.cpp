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

#define pairii pair<int, int>
#define llong long long
#define pb push_back
#define sortall(x) sort((x).begin(), (x).end())
#define INFI  numeric_limits<int>::max()
#define INFLL numeric_limits<llong>::max()
#define INFD  numeric_limits<double>::max()
#define FOR(i,s,n) for (llong (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

const int MAXN = 50005;
char name[MAXN][35];
llong f[MAXN];
int idx[MAXN];

inline bool comp(int i, int j) {
  if (f[i]==f[j]) return i < j;
  return f[i] > f[j];
}

void solve() {
  int n,m;
  scanf("%d%d",&n,&m);
  FORZ(i,n) {
    scanf("%lld%s",f+i,name[i]);
    idx[i] = (int)i;
    f[i] *= (i+1);
  }
  sort(idx, idx+n, comp);
  FORZ(i,m) {
    printf("%s\n",name[idx[i]]);
  }
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}
