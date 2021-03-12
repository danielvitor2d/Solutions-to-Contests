#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

int n, K;
int a[MAX];
int dp[2][MAX];

int solve(int davez, int k) {
	if (k == 0) return false;
	if (~dp[davez][k]) return dp[davez][k];
	bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (a[i] <= k) ok &= solve(1-davez, k-a[i]);
	}
	return dp[davez][k] = (ok ? false : true);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> K;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << (solve(0, K) ? "First\n" : "Second\n");
}