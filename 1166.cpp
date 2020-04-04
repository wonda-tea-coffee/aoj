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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll HMAX, WMAX;

bool isin(ll x, ll y) {
  return x >= 0 && x < WMAX && y >= 0 && y < HMAX;
}

void solve() {
  const ll MAX = 2 * 30;
  while (true) {
    ll W, H;
    cin >> W >> H; cin.ignore();

    if (W==0 && H==0) break;

    HMAX = 2*H-1, WMAX = 2*W-1;
    vector<string> grid(HMAX);
    rep(i, HMAX) {
      getline(cin, grid[i]);
      if (grid[i].size() < WMAX) grid[i] += ' ';
    }

    // debug2(HMAX, WMAX);

    queue<ll> qx, qy, qc;
    qx.push(0); qy.push(0); qc.push(0);
    ll mins[MAX][MAX] = {{}};
    rep(i, MAX)rep(j, MAX) mins[i][j] = INF;
    mins[0][0] = 0;

    bool ok = false;
    while (!qx.empty()) {
      ll x = qx.front(); qx.pop();
      ll y = qy.front(); qy.pop();
      ll c = qc.front(); qc.pop();

      // debug3(x, y, c);

      if (x == WMAX-1 && y == HMAX-1) {
        outl(c+1);
        ok = true;
        break;
      }

      rep(i, 4) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        ll nnx = nx + dx[i];
        ll nny = ny + dy[i];
        if (isin(nx, ny) && grid[ny][nx] == '0' && isin(nnx, nny) && c+1 < mins[nny][nnx]) {
          qx.push(nnx);
          qy.push(nny);
          qc.push(c+1);
          mins[nny][nnx] = c+1;
        }
      }
    }
    if (!ok) outl(0);
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
