#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

string s;
int d;
int dp[10001][2][2][101];

int solve(int idx = 0, int can = 0, int put = 0, int mod = 0) {
	if (idx == (int)s.size()) return (put and !mod);
	if (~dp[idx][can][put][mod]) return dp[idx][can][put][mod];
	int ans = 0;
	int mx = (can ? 9 : s[idx]-'0');
	if (!idx or !put) {
		for (int i = 0; i <= mx; ++i) {
			ans = (ans + solve(idx+1, can | (i != mx), put | (i > 0), (mod + i)%d))%MOD;
		}
	} else {
		for (int i = 0; i <= mx; ++i) {
			ans = (ans + solve(idx+1, can | (i != mx), 1, (mod + i)%d))%MOD;
		}
	}
	return dp[idx][can][put][mod] = ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> s >> d;
	memset(dp, -1, sizeof(dp));
	cout << solve() << '\n';
}