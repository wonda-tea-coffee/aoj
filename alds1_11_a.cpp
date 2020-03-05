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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  int n; cin >> n;
  int mat[n][n]; memset(mat, 0, sizeof(mat));

  for (int i = 0; i < n; i++) {
    int u; cin >> u;
    int k; cin >> k;
    for (int ki = 0; ki < k; ki++) {
      int v; cin >> v;
      mat[u - 1][v - 1] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << mat[i][0];
    for (int j = 1; j < n; j++) {
      cout << " " << mat[i][j];
    }
    cout << endl;
  }
}
