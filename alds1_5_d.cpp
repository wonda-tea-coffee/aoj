#include <iostream>
#define MAX      200000
#define SENTINEL 2000000000
using namespace std;
using ll = long long;

int L[MAX / 2 + 2], R[MAX / 2 + 2];

ll merge(int A[], int n, int left, int mid, int right) {
  ll ret = 0;
  ll n1 = mid - left;
  ll n2 = right - mid;
  for (int i = 0; i < n1; i++) L[i] = A[left + i];
  for (int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;
  
  int li = 0, ri = 0;
  for (int k = left; k < right; k++) {
    if (L[li] <= R[ri]) {
      A[k] = L[li++];
    } else {
      A[k] = R[ri++];
      ret += n1 - li; // = mid + j - k - 1
    }
  }
  return ret;
}

ll merge_sort(int A[], int n, int left, int right) {
  if (right - left > 1) {
    ll mid = (left + right) / 2;
    ll v1 = merge_sort(A, n, left,  mid);
    ll v2 = merge_sort(A, n,  mid, right);
    ll v3 = merge(A, n, left, mid, right);
    return v1 + v2 + v3;
  } else {
    return 0;
  }
}

int main() {
  int A[MAX], n; cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];

  ll ans = merge_sort(A, n, 0, n);

  cout << ans << endl;
}
