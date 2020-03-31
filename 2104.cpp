#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define all(a)          (a).begin(), (a).end()
#define sort(a)         sort(all(a))
#define outl(d)         std::cout<<(d)<<"\n"
#define int             long long

using namespace std;
using ll = long long;

ll n, k;

ll solve2(vector<ll> x) {
  vector<ll> y(n-1);
  for (int i = 1; i < n; i++)
    y[i-1] = x[i] - x[i-1];
  sort(y);

  ll ans = x[n-1] - x[0];
  for (int i = 0; i < k-1; i++)
    ans -= y[n-2-i];
  return max(ans, 0ll);
}

void solve() {
  ll t; cin >> t;
  rep(i, t) {
    cin >> n >> k;
    vector<ll> x(n); rep(j, n) cin >> x[j];
    outl(solve2(x));
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();
}
