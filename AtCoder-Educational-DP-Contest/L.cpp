#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e3+5;

int n;
int a[MAX];
int64_t dp[MAX][MAX];

int64_t solve(int l, int r) {
	if (r < l) return 0;
	if (~dp[l][r]) return dp[l][r];
	return dp[l][r] = max(a[l] - solve(l+1, r), a[r] - solve(l, r-1));
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n-1) << '\n';
}