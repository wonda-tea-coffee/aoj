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
// #define sort(a)         sort(all(a))
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

bool asc(const tuple<ll, ll, ll>& left, const tuple<ll, ll, ll>& right) {
  if (get<0>(left) != get<0>(right)) return get<0>(left) > get<0>(right);
  if (get<1>(left) != get<1>(right)) return get<1>(left) < get<1>(right);
  return get<2>(left) > get<2>(right);
}

void solve() {
  while (true) {
    ll m, t, p, r; cin >> m >> t >> p >> r;
    if (m == 0 && t == 0 && p == 0 && r == 0) break;

    const ll MAX_T = 50, MAX_P = 10;
    ll pnl[MAX_T][MAX_P] = {{}};
    vector<tuple<ll, ll, ll>> result(t); // 左から正解数、所要時間、チーム番号
    for (int i = 0; i < t; i++)
      result[i] = make_tuple(0, 0, i+1);
    
    for (int i = 0; i < r; i++) {
      ll mi, ti, pi, ji; cin >> mi >> ti >> pi >> ji;

      if (ji == 0) {
        get<0>(result[ti-1])++;
        get<1>(result[ti-1]) += mi + pnl[ti-1][pi-1] * 20;
      } else {
        pnl[ti-1][pi-1]++;
      }
    }

    sort(all(result), asc);

    vector<vector<ll>> ans(1);
    ans[0].emplace_back(get<2>(result[0]));
    for (int i = 1; i < t; i++) {
      ll lac = get<0>(result[i-1]);
      ll ltm = get<1>(result[i-1]);
      ll nac = get<0>(result[i]);
      ll ntm = get<1>(result[i]);
      if (lac == nac && ltm == ntm) {
        ans[ans.size() - 1].push_back(get<2>(result[i]));
      } else {
        ans.push_back(vector<ll>{get<2>(result[i])});
      }
    }

    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        if (j != 0) cout << "=";
        cout << ans[i][j];
      }

      if (i != ans.size()-1) cout << ",";
    }
    cout << endl;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
