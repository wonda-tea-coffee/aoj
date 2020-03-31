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
#include <regex>
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define all(a)          (a).begin(), (a).end()
#define sort(a)         sort(all(a))
#define uniq(a)         sort(a);(a).erase(unique(all(a)), (a).end())
#define reverse(a)      reverse(all(a))
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define YES()           cout << "YES" << endl
#define NO()            cout << "NO" << endl
#define Yes()           cout << "Yes" << endl
#define No()            cout << "No" << endl
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }
#define pb              push_back
#define fst             first
#define int             long long
#define INF             __LONG_LONG_MAX__
#define MAX             200000
#define SENTINEL        2000000000

using namespace std;
using ll = long long;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

ll merge(int A[], int n, int left, int mid, int right) {
  ll i, j, k;
  ll cnt = 0;
  ll n1 = mid - left;
  ll n2 = right - mid;
  for (i = 0; i < n1; i++) L[i] = A[left + i];
  for (i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
      cnt += n1 - i; // = mid + j - k - 1
    }
  }
  return cnt;
}

ll mergeSort(int A[], int n, int left, int right) {
  int mid;
  ll v1, v2, v3;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    v1 = mergeSort(A, n, left, mid);
    v2 = mergeSort(A, n, mid, right);
    v3 = merge(A, n, left, mid, right);
    return v1 + v2 + v3;
  } else {
    return 0;
  }
}

void solve() {
  int A[MAX], n, i;

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];
  ll ans = mergeSort(A, n, 0, n);
  cout << ans << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
