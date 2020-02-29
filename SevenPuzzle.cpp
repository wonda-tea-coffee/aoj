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
// using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7

struct P {
	int x, y;
};

struct Puzzle {
	int peace[2][4], t;
	P zero_p;
};

int toHash(int arr[][4]) {
	int res = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			res = (res << 3) + arr[i][j];
		}
	}
	return res;
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
	map<int, int> ps;
	queue<Puzzle> pq;

	Puzzle f_puzzle;
	REP(i, 8) f_puzzle.peace[i / 4][i % 4] = i;
	f_puzzle.t = 1;
	f_puzzle.zero_p = {0, 0};

	pq.push(f_puzzle);

	while (!pq.empty()) {
		Puzzle p = pq.front();pq.pop();
		int h_value = toHash(p.peace);

		if (ps[h_value] != 0) continue;

		P zero_p = p.zero_p;
		REP(i, 4) {
			int mx = zero_p.x + dx[i];
			int my = zero_p.y + dy[i];

			if (0 <= mx && mx < 4 && 0 <= my && my < 2) {
				Puzzle temp_p = p;
				temp_p.peace[zero_p.y][zero_p.x] = temp_p.peace[my][mx];
				temp_p.peace[my][mx] = 0;
				temp_p.zero_p = {mx, my};
				temp_p.t++;
				pq.push(temp_p);
			}
		}

		ps[h_value] = p.t;
	}

	int arr[2][4];
	while (true) {
		cin >> arr[0][0];

		if (cin.eof()) return 0;

		for (int i = 1; i < 8; i++)
			cin >> arr[i / 4][i % 4];

		cout << ps[toHash(arr)] - 1 << endl;
	}
}