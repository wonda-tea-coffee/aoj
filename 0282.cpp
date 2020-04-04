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

void solve() {
  ll N, R, L; cin >> N >> R >> L;
  vector<ll> time(N, 0), score(N, 0);
  priority_queue<P> pq; rep(i, N) pq.emplace(0, -i);

  ll prevtime = 0, looks, lookt;
  rep(i, R) {
    while (1) {
      tie(looks, lookt) = pq.top();
      lookt *= -1;
      if (score[lookt] == looks) break;
      else pq.pop();
    }
    ll d, t, x; cin >> d >> t >> x; d--;

    time[lookt] += t - prevtime;
    prevtime = t;

    score[d] += x;
    pq.emplace(score[d], -d);
  }

  while (1) {
    tie(looks, lookt) = pq.top();
    lookt *= -1;
    if (score[lookt] == looks) break;
    else pq.pop();
  }
  time[lookt] += L - prevtime;

  ll ans, maxt = -1;
  rep(i, N) {
    if (time[i] > maxt) {
      maxt = time[i];
      ans = i;
    }
  }

  outl(ans+1);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
