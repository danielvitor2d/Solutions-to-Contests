#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
const int MOD = 1e9+7;

int n;
vector<int> gr[MAX];
int dp[MAX][2];

int64_t solve(int u, int par, int par_color) {
	if (~dp[u][par_color]) return dp[u][par_color];
	int64_t ans1 = 1, ans2 = 0;
	for (int to : gr[u]) if (to != par)  {
		ans1 = (ans1 * solve(to, u, 0))%MOD;
	}
	if (par_color == 0) {
		ans2 = 1;
		for (int to : gr[u]) if (to != par)  {
			ans2 = (ans2 * solve(to, u, 1))%MOD;
		}	
	}
	return dp[u][par_color] = (ans1 + ans2)%MOD;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	if (n == 1) {
		cout << "2\n";
		exit(0);
	}
	for (int i = 0, u, v; i < n-1; ++i) {
		cin >> u >> v, --u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << '\n';
}