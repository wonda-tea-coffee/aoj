#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
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

using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7
const int INF = 1000000000;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int H, W, N;
int mins[1000][1000];

int getMinPath(string m[], int sy, int sx, int gy, int gx) {
  queue<tuple<int, int, int>> q; q.push(make_tuple(sy, sx, 0));

  mins[sy][sx] = 0;

  while (!q.empty()) {
    tuple<int, int, int> t = q.front(); q.pop();
    int y = get<0>(t);
    int x = get<1>(t);
    int c = get<2>(t);

    // cout << "y = " << y << ", x = " << x << ", c = " << c << endl;

    if (y == gy && x == gx) return c;

    mins[y][x] = c;

    REP(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < W && 0 <= ny && ny < H && m[ny][nx] != 'X' && c + 1 < mins[ny][nx]) {
        q.push(make_tuple(ny, nx, c + 1));
        mins[ny][nx] = c + 1;
      }
    }
  }

  assert(false);
  return -1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> H >> W >> N;
  string m[H]; REP(i, H) cin >> m[i];
  vector<P> v(N + 1);
  int ans = 0;

  REP(i, H)REP(j, W) {
    int n = m[i][j] - '0';
    P p = make_pair(i, j);

    if (1 <= n && n <= N)
      v[n] = p;
    else if (m[i][j] == 'S')
      v[0] = p;
  }

  // for (int i = 0; i < v.size(); i++) {
  //   cout << "(" << v[i].first << "," << v[i].second << ")" << endl;
  // }

  for (int i = 1; i <= N; i++) {
    REP(i, H)REP(j, W) mins[i][j] = INF;

    ans += getMinPath(m, v[i - 1].first, v[i - 1].second, v[i].first, v[i].second);
  }

  cout << ans << endl;
}