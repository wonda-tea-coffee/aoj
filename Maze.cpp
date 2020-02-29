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

const int MOD = 1000000007; // 10^9 + 7
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W; cin >> H >> W;
  vector<string> v(H);
  REP(i, H) cin >> v[i];

  int mins[101][101] = {{}};
  REP(i, 101)REP(j, 101) mins[i][j] = 100005;

  int sy = -1, sx = -1;
  REP(i, H)REP(j, W) {
    if (v[i][j] == 'S') {
      sy = i;
      sx = j;
    }
  }

  assert(sy != -1 && sx != -1);

  queue<tuple<int, int, int>> q; q.push(make_tuple(sy, sx, 0));

  while (!q.empty()) {
    tuple<int, int, int> t = q.front(); q.pop();
    int y = get<0>(t);
    int x = get<1>(t);
    int c = get<2>(t);

    mins[y][x] = c;
    // cout << "y = " << y << ", x = " << x << ", c = " << c << endl;

    if (v[y][x] == 'G') {
      cout << c << endl;
      break;
    }

    REP(i, 4) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      // cout << "nx = " << nx << ", ny = " << ny << endl;
      if (0 <= nx && nx < W && 0 <= ny && ny < H && v[ny][nx] != '#' && c + 1 < mins[ny][nx]) {
        q.push(make_tuple(ny, nx, c + 1));
      }
    }
  }
}