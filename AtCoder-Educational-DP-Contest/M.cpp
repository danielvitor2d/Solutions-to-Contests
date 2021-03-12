#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;
const int MOD = 1e9+7;

int n, K;
int a[MAX];
int64_t dp[MAX][100001];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> K;	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp[n][0] = 1;
	for (int i = n-1; i >= 0; --i) {
		int64_t acc = 0;
		for (int k = 0; k <= K; ++k) {
			acc = (acc + dp[i+1][k])%MOD;
			if (k >= a[i]+1) acc = (acc - dp[i+1][k-a[i]-1] + MOD)%MOD;
			dp[i][k] = acc;
		}
	}
	cout << dp[0][K] << '\n';
}