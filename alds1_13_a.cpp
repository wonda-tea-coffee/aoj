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
#define uniq(a)         sort(a);(a).erase(unique(all(a), (a).end()))
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
const int dx[4] = {1, 1, -1, -1};
const int dy[4] = {-1, 1, 1, -1};

ll k;
const int SIZE = 8;
vector<string> grid(SIZE);

bool back_track(int n) {
  if (n == 0) return true;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {

      if (grid[i][j] == 'Q') continue;

      // 行チェック
      int cnt = 0;
      for (int k = 0; k < SIZE; k++) {
        if (grid[i][k] == 'Q') cnt++;
      }
      if (cnt > 0) continue;

      // 列チェック
      cnt = 0;
      for (int k = 0; k < SIZE; k++) {
        if (grid[k][j] == 'Q') cnt++;
      }
      if (cnt > 0) continue;

      // 斜めチェック
      // 右上, 右下, 左下, 左上
      cnt = 0;
      bool ok = true;
      for (int k = 0; k < 4; k++) {
        int ni = i + dy[k];
        int nj = j + dx[k];

        while (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE) {
          if (grid[ni][nj] == 'Q') cnt++;
          ni += dy[k];
          nj += dx[k];
        }
        if (cnt > 0) { ok = false; break; }
      }
      if (!ok) continue;

      grid[i][j] = 'Q';

      if (back_track(n-1)) return true;

      grid[i][j] = '.';
    }
  }

  return false;
}

void solve() {
  cin >> k;
  rep(i, SIZE) grid[i] = "........";
  rep(i, k) {
    ll ri, ci; cin >> ri >> ci;
    grid[ri][ci] = 'Q';
  }

  if (back_track(8-k)) {
    rep(i, SIZE) outl(grid[i]);
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
