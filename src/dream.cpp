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

vector<string> ev,tmpv;
set<string> es;
map<string,int> idx;
int n;

void solve() {
  scanf("%d",&n);
  char tmps[30];
  FORZ(i,n) {
    tmpv.clear();
    scanf("%s",tmps);
    char q=tmps[0];
    if (q=='E') {
      scanf("%s",tmps);
      string s(tmps);
      ev.pb(s);
      es.insert(s);
      idx[s]=(int)ev.size()-1;
    } else if (q=='D') {
      int d;
      scanf("%d",&d);
      FORZ(j,d) {
        string s = ev[ev.size()-1];
        es.erase(s);
        ev.pop_back();
      }
    } else {
      int m;
      scanf("%d",&m);
      int r=-1;
      bool valid=true;
      FORZ(j,m) {
        scanf("%s",tmps);
        string s(tmps);
        if (s[0]=='!') {
          s = s.substr(1);
          if (es.find(s)!=es.end()) {
            r = max(r,(int)ev.size()-idx[s]);
          }
        } else {
          if (es.find(s)==es.end()) {
            valid=false;
          } else {
            tmpv.pb(s);
          }
        }
      }
      if (valid) {
        if (r<0) {
          printf("Yes\n");
        } else {
          int cut = (int)ev.size()-r;
          bool valid2 = true;
          FORZ(j,tmpv.size()) {
            if (idx[tmpv[j]]>=cut) {
              valid2=false;
              break;
            }
          }
          if (valid2) printf("%d Just A Dream\n",r);
          else printf("Plot Error\n");
        }
      } else {
        printf("Plot Error\n");
      }
    }
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
