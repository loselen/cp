#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> cur_pos(3);
  for (int i = 0; i < 3; i++) {
    cur_pos[i] = i + 1;
  }
  vector<int> each_ans(3, 0);

  for (int i = 0; i < n; i++) {
    int a, b, g;
    cin >> a >> b >> g;

    for (int j = 0; j < 3; j++) {
      if (cur_pos[j] == a)
        cur_pos[j] = b;
      else if (cur_pos[j] == b)
        cur_pos[j] = a;
    }

    for (int j = 0; j < 3; j++) {
      if (cur_pos[j] == g)
        each_ans[j]++;
    }
  }

  auto max_val = max_element(each_ans.begin(), each_ans.end());
  cout << *max_val << '\n';

  return 0;
}
