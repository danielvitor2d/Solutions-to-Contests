#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;

int n;
int a[MAXN], dp[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	dp[n] = 0;
	dp[n-1] = abs(a[n]-a[n-1]);
	for (int i = n-2; i >= 1; --i) {
		dp[i] = min(dp[i+1]+abs(a[i]-a[i+1]), dp[i+2]+abs(a[i]-a[i+2]));
	}
	cout << dp[1] << '\n';
}