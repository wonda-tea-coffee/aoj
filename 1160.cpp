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
#define uniq(a)         sort(a);(a).erase(unique(all(a), (a).end())
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

void solve2(ll w, ll h) {
  vector<vector<int>> grid(h);
  rep(i, h) {
    grid[i].resize(w);
    rep(j, w) cin >> grid[i][j];
  }

  ll ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] != 1) continue;

      queue<ll> qx, qy;
      qx.push(j); qy.push(i); grid[i][j] = -1;
      while (!qx.empty()) {
        ll x = qx.front(); qx.pop();
        ll y = qy.front(); qy.pop();

        for (int k = 0; k < 8; k++) {
          ll nx = x + dx[k];
          ll ny = y + dy[k];

          if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] == 1) {
            grid[ny][nx] = -1;
            qx.push(nx);
            qy.push(ny);
          }
        }
      }

      ans++;
    }
  }
  outl(ans);
}

void solve() {
  while (true) {
    ll w, h; cin >> w >> h;
    if (w == 0 && h == 0) break;
    solve2(w, h);
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
