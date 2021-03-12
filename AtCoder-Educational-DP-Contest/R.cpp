#include <bits/stdc++.h>
using namespace std;
const int MAX = 51;
const int MOD = 1e9+7;
const int D = 51;

int d = D;

struct M {
	int64_t m[D][D];
	int64_t* operator[](int i) {
		return m[i];
	}
	M operator*(M oth) {
		M res;
		for (int i = 0; i < d; ++i) {
			for (int j = 0; j < d; ++j) {
				res[i][j] = 0;
				for (int k = 0; k < d; ++k) {
					res[i][j] = (res[i][j] + m[i][k] * oth[k][j] % MOD + MOD) % MOD;
				}
			}
		}
		return res;
	}	
	M exp(int64_t e) {
		M res;
		for (int i = 0; i < d; ++i)
			for (int j = 0; j < d; ++j)
				res[i][j] = (i==j);
		M base = *this;
		while (e > 0) {
			if (e & 1LL) res = res * base;
			base = base * base;
			e >>= 1LL;
		}
		return res;
	}
};

int n;
int64_t k;
M a;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k; d = n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	a = a.exp(k);
	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ans = (ans + a[i][j])%MOD;
		}
	}
	cout << ans << '\n';
}