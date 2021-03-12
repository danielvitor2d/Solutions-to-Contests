#include <bits/stdc++.h>
using namespace std;
const int64_t LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 405;

int n;
int a[MAX];
int64_t acc[MAX];
int64_t dp[MAX][MAX];

inline int64_t get_sum(int l, int r) {
	int64_t sum = acc[r];
	if (l > 0) sum -= acc[l-1];
	return sum;
}

int64_t solve(int l, int r) {
	if (l == r) return 0;
	if (~dp[l][r]) return dp[l][r];
	int64_t ans = LINF;
	for (int i = l; i < r; ++i) {
		ans = min(ans, solve(l, i) + solve(i+1, r) + 
				           get_sum(l, i) + get_sum(i+1, r));
	}
	return dp[l][r] = ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		acc[i] = a[i];
		if (i > 0) acc[i] += acc[i-1];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, n-1) << '\n';
}