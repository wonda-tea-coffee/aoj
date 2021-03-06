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

ll mypow(ll x, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x;
    x = x * x;
    n >>= 1;
  }
  return res;
}

vector<P> factor(ll n) {
  vector<P> ret;
  ll q = n;
  for (ll d = 2; d * d <= n; d++) {
    if (q % d > 0) continue;
    ll cnt = 0;
    while (q % d == 0) {
      cnt++;
      q /= d;
    }
    ret.push_back(make_pair(d, cnt));
  }
  if (q > 1) ret.push_back(make_pair(q, 1));
  return ret;
}

void solve() {
  ll n; cin >> n;
  map<ll, ll> map;
  rep(i, n) {
    ll ai; cin >> ai;
    vector<P> v = factor(ai);
    for (P vi : v) {
      if (map.find(vi.first) == map.end()) map.insert(make_pair(vi.first, vi.second));
      else map[vi.first] = max(map[vi.first], vi.second);
    }
  }

  ll ans = 1;
  for (auto it : map) {
    ans *= mypow(it.first, it.second);
  }
  outl(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
