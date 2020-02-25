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
#include <tuple>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int mini = a[0];
  int ans = -pow(10, 9) - 1;
  for (int i = 1; i < n; i++)
  {
    ans = max(ans, a[i] - mini);
    mini = min(mini, a[i]);
  }

  cout << ans << endl;
}