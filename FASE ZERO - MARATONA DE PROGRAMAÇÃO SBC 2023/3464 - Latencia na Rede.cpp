#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void add(int x, int y, int r, vector<vector<int>> &gr) {
  int n = gr.size() - 1, m = gr[0].size() - 1;

  ++gr[max(1, x - r)][max(1, y - r)];
  if  (y + r + 1 <= m) --gr[max(1, x - r)][y + r + 1];
  if (x + r + 1 <= n) --gr[x + r + 1][max(1, y - r)];
  if (x + r + 1 <= n and y + r + 1 <= m) ++gr[x + r + 1][y + r + 1];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> gr(n + 1, vector<int>(m + 1, 0));

  int s; cin >> s;
  while (s--) {
    int x, y, r; cin >> x >> y >> r;
    add(x, y, r, gr);
  }

  double cnt = 0.0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      gr[i][j] += gr[i-1][j] + gr[i][j-1] - gr[i-1][j-1];
      cnt += gr[i][j];
    }
  }

  cnt /= n; cnt /= m;

  cout << int(floor(cnt)) << '\n';
}