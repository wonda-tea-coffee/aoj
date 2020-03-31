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
using P = pair<ll,ll>;

void solve() {
  stack<ll> S1; // \の位置を格納
  stack<P> S2;
  string s; cin >> s;
  ll sum = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '\\') S1.push(i);
    else if (s[i] == '/' && S1.size() > 0) {
      int j = S1.top(); S1.pop();
      sum += i - j;
      int a = i - j;
      while (S2.size() > 0 && S2.top().first > j) {
        a += S2.top().second; S2.pop();
      }
      S2.push(make_pair(j, a));
    }
  }

  vector<ll> ans;
  while (S2.size() > 0) {
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans);
  outl(sum);
  cout << ans.size();
  for (int ai : ans) cout << " " << ai;
  cout << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
