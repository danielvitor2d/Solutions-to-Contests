#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e3+5;

int n, m;
int dp[MAX][MAX];
string s, t, ans;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s >> t;
	n = s.size(); m = t.size();
	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (s[i] == t[j]) {
				dp[i][j] = max(dp[i][j], dp[i+1][j+1] + 1);
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	int i = 0, j = 0;
	while (i < n and j < m) {
		if (s[i] == t[j]) {
			ans += s[i];
			++i; ++j;
		} else if (dp[i][j+1] > dp[i+1][j]) {
			++j;
		} else {
			++i;
		}
	}
	cout << ans << '\n';
}