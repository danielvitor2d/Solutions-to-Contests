#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 x; cin >> x;

  do {
    cout << x << '\n';
    if (x > 9) {
      x = 3 * (x / 10) + x % 10;
    } else break;
  } while (x > 0);
}