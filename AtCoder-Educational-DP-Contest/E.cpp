#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 110;
const int MAXW = 1e5+5;

int v[MAXN], w[MAXN];
int64_t dp[MAXW];
int n, W, S;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> W;
	for (int i = 0; i < n; ++i) {
		cin >> w[i] >> v[i];
		S += v[i];
	}
	for (int i = 1; i <= S; ++i) {
		dp[i] = INF;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = S; j >= v[i]; --j) {
			dp[j] = min(dp[j], w[i] + dp[j-v[i]]);
		}
	}
	int ans = -1;
	for (int i = 0; i <= S; ++i) {
		if (dp[i] <= W) {
			ans = i;
		}
	}
	cout << ans << '\n';
}