#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e3+5;

int n, m;
int a[MAX][MAX];
int dp[MAX][MAX];
char c;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> c;
			a[i][j] = (c=='#');
		}
	}
	dp[n-1][m-1] = 1;
	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (i==n-1 and j==m-1) {
				continue;
			}
			int res = 0;
			if (i < n-1 and a[i+1][j] == 0) {
				res += dp[i+1][j];
				if (res >= MOD) res -= MOD;
			}
			if (j < m-1 and a[i][j+1] == 0) {
				res += dp[i][j+1];
				if (res >= MOD) res -= MOD;
			}
			dp[i][j] = res;
		}
	}
	cout << dp[0][0] << '\n';
}