#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    vector<string> strs(num);
    unordered_map<char, int> dicts;
    for (int j = 0; j < num; j++) {
      cin >> strs[j];
      for (int k = 0; k < strs[j].size(); k++) {
        dicts[strs[j][k]] += 1;
      }
    }

    bool valid = true;
    for (auto pair : dicts) {
      if (pair.second % num != 0) {
        valid = false;
        break;
      }
    }

    if (valid) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }

  return 0;
}
