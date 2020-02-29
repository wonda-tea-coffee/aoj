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
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int H, W;

void show(vector<string> v) {
  REP(i, v.size()) {
    cout << v[i] << endl;
  }
  cout << endl;
}

void dfs(vector<string> &v, int y, int x, char c) {
  v[y][x] = '.';

  // cout << "y = " << y << ", x = " << x << endl;
  REP(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // cout << "  ny = " << ny << ", nx = " << nx << ", c = " << c << endl;

    if (0 <= nx && nx < W && 0 <= ny && ny < H && v[ny][nx] == c) {
      dfs(v, ny, nx, c);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    cin >> H >> W;

    if (H == 0 && W == 0) break;

    vector<string> v(H);
    REP(i, H) cin >> v[i];

    int ans = 0;

    REP(i, H)REP(j, W) {
      if (v[i][j] == '.') continue;

      // cout << "------------------------------" << endl;
      dfs(v, i, j, v[i][j]);
      // show(v);
      ans++;
    }

    cout << ans << endl;
  }
}