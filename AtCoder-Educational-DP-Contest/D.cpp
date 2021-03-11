#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int MAXW = 1e5+5;

int v[MAXN], w[MAXN];
int64_t dp[MAXW];
int n, W;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> W;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = W; j >= w[i]; --j) {
			dp[j] = max(dp[j], v[i] + dp[j-w[i]]);
		}
	}
	cout << dp[W] << '\n';
}