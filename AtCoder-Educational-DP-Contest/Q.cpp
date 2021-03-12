#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+5;

int n;
int a[MAX], h[MAX];
int64_t dp[MAX];
int64_t b[MAX];

int64_t query(int idx) {
	int64_t res = 0;
	for (; idx > 0; idx -= (idx & -idx)) {
		res = max(res, b[idx]);
	}
	return res;
}

void update(int idx, int64_t val) {
	for (; idx <= n; idx += (idx & -idx)) {
		b[idx] = max(b[idx], val);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int64_t ans = 0;
	for (int i = 1; i <= n; ++i) {
		dp[i] = query(h[i]-1) + a[i];
		update(h[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}