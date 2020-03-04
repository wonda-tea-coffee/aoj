#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i,n)   for (int i = 0; i < (n); ++i)
#define SORT(a)    sort((a).begin(), (a).end());
#define UNIQ(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define REVERSE(a) reverse((a).begin(), (a).end());
#define OUT(d) cout << (d);
#define OUT_L(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define CEIL(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

const int MAX_N = 100;
ll N;
ll dp[MAX_N][MAX_N];
vector<ll> p(MAX_N + 1);

ll solve(int l, int r) {
  if (dp[l][r] != 0) return dp[l][r];
  if (l == r) return 0;

  ll ret = __INT_MAX__;
  REP(i, r - l) {
    ret = min(ret, solve(l, l + i) + solve(l + i + 1, r) + p[l] * p[l + i + 1] * p[r + 1]);
  }
  return dp[l][r] = ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  cin >> N;

  cin >> p[0];
  for(int i = 1; i <= N - 1; i++) {
    cin >> p[i];
    cin >> p[i];
  }
  cin >> p[N];
  memset(dp, 0, sizeof(dp));

  OUT_L(solve(0, N - 1))
}
