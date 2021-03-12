#include <bits/stdc++.h>
using namespace std;

/*
dp[i][j] — The number of ways to make a permutation of length i + 1 
that respects the first i signs and the last element is j (j ≤ i + 1).
*/

string s;
int n;

int solve(int i, int j) {
	if (i == 0) return 0;
	int ans = 0;
	for (int k = j-1; k >= 1; --k) {
		ans += solve(i-1, k);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> s;
	cout << solve(n-1, ) << '\n';

}