#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int n, k;
int a[MAXN], dp[MAXN], best[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp[n] = 0;
	for (int i = n-1; i >= 1; --i) {
		dp[i] = 1e9+5;
		for (int j = i+1; j <= min(n, i+k); ++j) {
			dp[i] = min(dp[i], dp[j]+abs(a[i]-a[j]));
		}
	}
	cout << dp[1] << '\n';
}