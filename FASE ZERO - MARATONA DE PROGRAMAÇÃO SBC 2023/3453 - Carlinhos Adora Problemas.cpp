#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 n, k; cin >> n >> k;
  i64 base = (n << 1) + 1;

  for (i64 i = 2 * n; i >= 1; --i) {
    i64 curr = i * i;
    if (curr != k and llabs(curr - k) % base == 0) {
      cout << curr << '\n';
      break;
    }
  }
}