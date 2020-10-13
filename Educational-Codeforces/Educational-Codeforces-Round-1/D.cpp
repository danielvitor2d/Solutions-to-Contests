/*
	Author: [UFC-QXD] Daniel Vitor Pereira Rodrigues <danielvitor@alu.ufc.br>
	Problem: Igor In the Museum
	Link: https://codeforces.com/contest/598/problem/D
	Origin: Educational Codeforces Round 1
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> ii;
typedef pair<i64, i64> ll;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const double eps = 1e-9;

#define eq(a, b) (abs(a - b) < eps)
#define lt(a, b) ((a + eps) < b)
#define gt(a, b) (a > (b + eps))
#define le(a, b) (a < (b + eps))
#define ge(a, b) ((a + eps) > b)

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, x) memset(a, x, sizeof(a))
#define len(x) (x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const int dtx[] = { 0, 0, -1, 1, 1, -1,  1, -1};
const int dty[] = {-1, 1,  0, 0, 1, -1, -1,  1};
const int dtxc[] = {1,  1, 2,  2, -1, -1, -2, -2};
const int dtyc[] = {2, -2, 1, -1,  2, -2,  1, -1};

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;

int n, m, k, cnt;
int gr[maxn][maxn], ans[maxn][maxn];
int used[maxn][maxn];

void dfs(int i, int j, int mk) {
	used[i][j] = mk;

	int ok = 0;
	for (int x = 0; x < 4; ++x) {
		int ni = i + dtx[x], nj = j + dty[x];		
		if (ni < 1 or n < ni or nj < 1 or m < nj) continue;
		ok += (gr[ni][nj] == 1);
		if (used[ni][nj] == mk or gr[ni][nj] == 1) continue;
		dfs(ni, nj, mk);
	}

	cnt += ok;
}

void color(int i, int j, int mk) {
	used[i][j] = mk;
	ans[i][j] = cnt;

	for (int x = 0; x < 4; ++x) {
		int ni = i + dtx[x], nj = j + dty[x];		
		if (ni < 1 or n < ni or nj < 1 or m < nj) continue;
		if (used[ni][nj] == mk or gr[ni][nj] == 1) continue;
		color(ni, nj, mk);
	}
}

int main() {
	fastIO();
	
	cin >> n >> m >> k;

	char c;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> c;
			gr[i][j] = (c == '*');
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (used[i][j] > 0 or gr[i][j] == 1) continue;
			cnt = 0;
			dfs(i, j, 1);
			color(i, j, 2);
		}
	}

	int a, b;
	while (k--) {
		cin >> a >> b;
		cout << ans[a][b] << '\n';
	}

	return 0;
}