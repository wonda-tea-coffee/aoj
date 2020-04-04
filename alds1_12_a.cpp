#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <regex>
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define all(a)          (a).begin(), (a).end()
#define sort(a)         sort(all(a))
#define uniq(a)         sort(a);(a).erase(unique(all(a)), (a).end())
#define reverse(a)      reverse(all(a))
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define YES()           cout << "YES" << endl
#define NO()            cout << "NO" << endl
#define Yes()           cout << "Yes" << endl
#define No()            cout << "No" << endl
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }
#define pb              push_back
#define fst             first
#define int             long long
#define INF             __LONG_LONG_MAX__

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

const int MAX = 100;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n, M[MAX][MAX];

ll prim() {
  ll d[MAX], p[MAX], color[MAX];

  rep(i, n) {
    d[i] = INF;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while(1) {
    ll u = -1, minv = INF;
    rep(i, n) {
      if (d[i] < minv && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1) break;
    color[u] = BLACK;
    rep(v, n) {
      if (color[v] != BLACK && d[v] > M[u][v]) {
        d[v] = M[u][v];
        p[v] = u;
        color[v] = GRAY;
      }
    }
  }
  ll sum = 0;
  rep(i, n) {
    if (p[i] != -1) sum += M[i][p[i]];
  }
  return sum;
}

void solve() {
  cin >> n;
  rep(i, n)rep(j, n) {
    cin >> M[i][j];
    if (M[i][j] == -1) M[i][j] = INF;
  }

  outl(prim());
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
