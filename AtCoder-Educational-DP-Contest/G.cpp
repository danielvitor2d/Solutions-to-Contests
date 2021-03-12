#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

int n, m;
int in[MAX], dp[MAX];
vector<int> gr[MAX];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		gr[u].push_back(v);
		++in[v];
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (!in[i]) {
			q.push(i);
			dp[i] = 0;
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int to : gr[u]) {
			--in[to];
			dp[to] = max(dp[to], dp[u] + 1);
			if (in[to] == 0) {
				q.push(to);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
}