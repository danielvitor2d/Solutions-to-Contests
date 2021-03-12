#include <bits/stdc++.h>
using namespace std;
typedef long double db;
const int MAX = 3000;

int n;
db p[MAX];
db dp[MAX][MAX];
int calc[MAX][MAX];

db solve(int i, int heads) {
	if (i == n) return (2*heads >= n);
	if (calc[i][heads]) return dp[i][heads];
	calc[i][heads] = true;
	return dp[i][heads] = p[i]*solve(i+1, heads+1)+(1-p[i])*solve(i+1, heads);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	cout << fixed << setprecision(9) << solve(0, 0) << '\n';
}