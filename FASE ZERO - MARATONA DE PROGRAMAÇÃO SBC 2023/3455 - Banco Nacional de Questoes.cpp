#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using ld = long double;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  i64 a, b, c; cin >> a >> b >> c;

  char ch; cin >> ch;

  if (ch == 'A') {
    ld ans = a;

    ans += (ld)(b / 2.0) * 3;
    ans += (ld)(c / 2.0) * 5;

    cout << i64(floor(ans)) << '\n';
  } else if (ch == 'B') {
    ld ans = b;

    ans += (ld)(a / 3.0) * 2;
    ans += (ld)(c / 3.0) * 5;

    cout << i64(floor(ans)) << '\n';
  } else {
    ld ans = c;

    ans += (ld)(a / 5.0) * 2;
    ans += (ld)(b / 5.0) * 3;

    cout << i64(floor(ans)) << '\n';
  }
}