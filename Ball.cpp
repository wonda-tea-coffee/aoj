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

int a[10];

bool dfs(int i, int b, int c) {
  if (i == 10) return true;

  if (a[i] > b && dfs(i + 1, a[i], c)) return true;
  if (a[i] > c && dfs(i + 1, b, a[i])) return true;
  return false;
}

bool solve() {
  return dfs(0, -1, -1);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  REP(i, n) {
    REP(j, 10) cin >> a[j];
    cout << (solve() ? "YES" : "NO") << endl;
  }
}