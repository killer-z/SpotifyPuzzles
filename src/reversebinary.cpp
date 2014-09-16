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

typedef unsigned int uint;

bool b[32];

uint bin(uint x) {
  uint i = 0;
  while (x>0) {
    b[i] = x%2;
    x/=2;
    i++;
  }
  return i;
}

uint dec(uint len) {
  uint x = 0;
  uint base = 1;
  for (uint i = len; i >0; i--) {
    x += (uint)b[i-1]*base;
    base*=2;
  }
  return x;
}

void solve() {
  uint x;
  scanf("%u",&x);
  uint n = bin(x);
  printf("%u", dec(n));
}

int main() {
#ifdef DEBUG
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  solve();
  return 0;
}
