#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][3];
int n;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	dp[n-1][0] = a[n-1];
	dp[n-1][1] = b[n-1];
	dp[n-1][2] = c[n-1];
	for (int i = n-2; i >= 0; --i) {
		dp[i][0] = a[i] + max(dp[i+1][1], dp[i+1][2]);
		dp[i][1] = b[i] + max(dp[i+1][0], dp[i+1][2]);
		dp[i][2] = c[i] + max(dp[i+1][0], dp[i+1][1]);
	}
	cout << max({dp[0][0], dp[0][1], dp[0][2]}) << '\n';
}