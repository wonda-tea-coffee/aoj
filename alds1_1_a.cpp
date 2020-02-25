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

void show(int a[], int n)
{
  cout << a[0];
  for (int i = 1; i < n; i++)
  {
    cout << " " << a[i];
  }
  cout << endl;
}

void insertion_sort(int a[], int n)
{
  show(a, n);
  for (int i = 1; i < n; i++)
  {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v)
    {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    show(a, n);
  }
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  insertion_sort(a, n);
}