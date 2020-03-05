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
int d[MAX_N + 1];
int N;
vector<vector<int>> g(MAX_N + 1);

void bfs() {
  queue<P> q;
  q.push(make_pair(1, 0));

  while (!q.empty()) {
    P p = q.front(); q.pop();
    int node = p.first;
    int dist = p.second;

    if (d[node] >= 0) continue;

    d[node] = dist;
    for (int i = 0; i < g[node].size(); i++) {
      q.push(make_pair(g[node][i], dist + 1));
    }
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
  memset(d, -1, sizeof(d));

  bfs();

  for (int i = 1; i <= N; i++) {
    cout << i << " " << d[i] << endl;
  }
}
