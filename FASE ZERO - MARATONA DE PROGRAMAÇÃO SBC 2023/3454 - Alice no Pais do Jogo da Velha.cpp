#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

using i64 = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  int cntO = count(s.begin(), s.end(), 'O');
  int cntX = 3 - cntO;

  if (cntX != 2) {
    cout << "?\n";
    exit(0);
  }

  if ((s[0] == s[1] or s[1] == s[2]) and s[1] == 'X') {
    cout << "Alice\n";
  } else {
    cout << "*\n";
  }
}