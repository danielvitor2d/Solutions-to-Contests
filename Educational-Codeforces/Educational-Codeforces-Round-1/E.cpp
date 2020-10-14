/*
	Author: [UFC-QXD] Daniel Vitor Pereira Rodrigues <danielvitor@alu.ufc.br>
	Problem: Chocolate Bar
	Link: https://codeforces.com/contest/598/problem/E
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
const int maxn = 1e5+5;
const int mod = 1e9+7;

int dp[31][31][51];

int solve(int n, int m, int k) {
	if (k == 0 or n * m == k) return 0;
	if (~dp[n][m][k]) return dp[n][m][k];
	int ans = inf;
	for (int i = 1; i <= n-i; ++i) {
		for (int j = 0; j <= k; ++j) {
			ans = min(ans, m*m + solve(i, m, k-j) + solve(n-i, m, j));
		}
	}
	for (int i = 1; i <= m-i; ++i) {
		for (int j = 0; j <= k; ++j) {
			ans = min(ans, n*n + solve(n, i, k-j) + solve(n, m-i, j));
		}
	}
	return dp[n][m][k] = ans;
}

int tc;
int n, m, k;

int main() {
	fastIO();
	ms(dp, -1);
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		cout << solve(n, m, k) << '\n';
	}
	return 0;
}