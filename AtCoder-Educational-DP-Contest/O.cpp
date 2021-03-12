#include <bits/stdc++.h>
using namespace std;
const int MAX = 22;
const int MOD = 1e9+7;

int n, target;
int a[MAX][MAX];
int dp[1 << MAX];

int solve(int mask) {
	if (mask == target) return 1;
	if (~dp[mask]) return dp[mask];
	int i = __builtin_popcount(mask);
	int ans = 0;
	for (int k = 0; k < n; ++k) {
		if ((mask & (1 << k)) == 0 and a[i][k] == 1) {
			ans = (ans + solve(mask | (1 << k)))%MOD;
		}
	}
	return dp[mask] = ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	target = (1 << n)-1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0) << '\n';
}