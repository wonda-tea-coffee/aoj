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

#define rep(i,n)   for (int i = 0; i < (n); ++i)
#define sort(a)    sort((a).begin(), (a).end());
#define uniq(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define find(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define reverse(a) reverse((a).begin(), (a).end());
#define out(d) cout << (d);
#define outl(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define ceil(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

const int MAX_N = 100;
int s[MAX_N + 1], e[MAX_N + 1];
int N, t = 1;
vector<vector<int>> g(MAX_N + 1);

void dfs(int i) {
  if (s[i] > 0) return;

  s[i] = t++;
  for (int j = 0; j < g[i].size(); j++) {
    dfs(g[i][j]);
  }
  e[i] = t++;
}

void dfs() {
  for (int i = 1; i <= N; i++) {
    if (s[i] > 0) continue;
    dfs(i);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  cin >> N;
  for (int i = 0; i < N; i++) {
    int u; cin >> u;
    int k; cin >> k;
    for (int ki = 0; ki < k; ki++) {
      int tmp; cin >> tmp;
      g[u].push_back(tmp);
    }
    sort(g[u])
  }

  memset(s, 0, sizeof(s));
  memset(e, 0, sizeof(e));

  dfs();

  for (int i = 1; i <= N; i++) {
    cout << i << " " << s[i] << " " << e[i] << endl;
  }
}
