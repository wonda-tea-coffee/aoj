// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/12/ALDS1_12_A

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
#include <vector>

#define fix(n) cout<<fixed<<setprecision(n);
#define rep(i,n)   for (int i = 0; i < (n); ++i)
#define sort(a)    sort((a).begin(), (a).end());
#define uniq(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
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

static const int MAX_N = 105;
int n, costs[MAX_N][MAX_N];
vector<vector<int>> lists(MAX_N);

int mst() {
  int ret = __INT_MAX__;

  queue<pair<set<int>, int>> q;
  
  rep(i, n) {
    q.push(make_pair(set<int>{i}, 0));
  }

  while (!q.empty()) {
    pair<set<int>, int> v = q.front(); q.pop();
    set<int> s = v.first;
    int sum = v.second;

    cout << q.size() << endl;
    cout << "s.size() = " << s.size() << ", sum = " << sum << endl;

    if (s.size() == n) {
      ret = min(ret, sum);
      continue;
    }

    for (int i = 0; i < n; i++) {
      if (s.find(i) != s.end()) continue;

      // cout << "  i = " << i << ", lists[i].size() = " << lists[i].size() << endl;

      for (int j = 0; j < lists[i].size(); j++) {
        int l = lists[i][j];

        if (s.find(l) == s.end()) continue;

        assert(l != -1);

        if (sum + costs[i][l] < ret) {
          set<int> ns = s;
          ns.insert(i);

          assert(costs[i][l] > 0);

          q.push(make_pair(ns, sum + costs[i][l]));
        }
      }
    }
  }

  return ret;
}

void make_list() {
  rep(i, n) {
    rep(j, n) {
      if (costs[i][j] != -1) {
        lists[i].push_back(j);
        lists[j].push_back(i);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12)

  cin >> n;
  rep(i, n)rep(j, n) cin >> costs[i][j];

  make_list();

  outl(int(sizeof(lists)))

  outl(mst())
}
