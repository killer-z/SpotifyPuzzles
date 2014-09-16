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
#define FOR(i,s,n) for (int (i) = (s); (i) < (n); (i)++)
#define FORZ(i,n) FOR((i),0,(n))

char full[8][10] = {"thou","inch","foot","yard","chain","furlong","mile","league"};
char part[8][10] = {"th","in","ft","yd","ch","fur","mi","lea"};
double coef[8] = {1,1000,12,3,22,10,8,3};

void solve() {
  double d;
  char a[10],b[10],c[10];
  scanf("%lf%s%s%s",&d,a,b,c);
  int x,y;
  FORZ(i,8) {
    if (strcmp(full[i],a)==0 || strcmp(part[i],a)==0) x=i;
    if (strcmp(full[i],c)==0 || strcmp(part[i],c)==0) y=i;
  }
  double f=1.0;
  if (x<y) {
    for (int i=x+1; i<=y; i++) f*=coef[i];
  } else if (x>y) {
    for (int i=x; i>=y+1; i--) f/=coef[i];
  }
  printf("%.12f",d/f);
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}
