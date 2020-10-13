/*
	Author: [UFC-QXD] Daniel Vitor Pereira Rodrigues <danielvitor@alu.ufc.br>
	Problem: Nearest vectors
	Link: https://codeforces.com/contest/598/problem/C
	Origin: Educational Codeforces Round 1
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef pair<int, int> ii;
typedef pair<i64, i64> ll;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

const double eps = 1e-16;

#define eq(a, b) (abs(a - b) < eps)
#define lt(a, b) ((a + eps) < b)
#define gt(a, b) (a > (b + eps))
#define le(a, b) (a < (b + eps))
#define ge(a, b) ((a + eps) > b)

#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ms(a, x) memset(a, x, sizeof(a))
#define len(x) (x).size()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

const int dtx[] = { 0, 0, -1, 1, 1, -1,  1, -1};
const int dty[] = {-1, 1,  0, 0, 1, -1, -1,  1};
const int dtxc[] = {1,  1, 2,  2, -1, -1, -2, -2};
const int dtyc[] = {2, -2, 1, -1,  2, -2,  1, -1};

const long double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;

int n, a, b;
long double x, y, mn = inf;

vector<pair<long double, int>> v;

int main() {
	fastIO();
	
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		long double angle = atan2(y, x) * 180.0 / pi + 360.0;
		if (ge(angle, 360.0)) angle -= 360.0;
		v.eb(angle, i+1);
	}

	sort(all(v));

	v.pb(v[0]);

	for (int i = 0; i < n; ++i) {
		long double dif = v[i+1].fi - v[i].fi;
		if (lt(dif, 0.0)) dif += 360.0;
		if (lt(dif, mn)) {
			mn = dif;
			a = v[i+1].se;
			b = v[i].se;
		}
	}

	cout << a << ' ' << b << '\n';

	return 0;
}