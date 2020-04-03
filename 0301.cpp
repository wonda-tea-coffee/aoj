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

void solve() {
  int N, M, Q; cin >> N >> M >> Q;
  vector<ll> a(M), q(Q), prev(N), next(N), flag(N);
  rep(i, M) cin >> a[i];
  rep(i, Q) cin >> q[i];
  rep(i, N) {
    flag[i] = 1;
    prev[i] = (i - 1 + N) % N;
    next[i] = (i + 1) % N;
  }

  ll p = 0;
  rep(i, M) {
    if (a[i] % 2 == 0)
      rep(j, a[i]) p = next[p];
    else
      rep(j, a[i]) p = prev[p];

    // 列から抜ける
    flag[p] = 0;

    // 自身が抜けた分のポインタを付け替える
    prev[next[p]] = prev[p];
    next[prev[p]] = next[p];

    // 時計回りで次の人にバトンを渡す
    p = next[p];
  }
  rep(i, Q) outl(flag[q[i]]);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
