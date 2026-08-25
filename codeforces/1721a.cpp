#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string top, down;
    cin >> top >> down;

    string all = top + down;
    unordered_map<char, int> char_dict;
    for (auto c : all) {
      char_dict[c] += 1;
    }

    multiset<int> ordered_count;
    for (auto pair : char_dict) {
      ordered_count.insert(pair.second);
    }

    vector<int> counts;
    for (auto e : ordered_count) {
      counts.push_back(e);
    }

    // if (counts.size() == 1) {
    //   cout << 0;
    // } else if (counts.size() == 2) {
    //   cout << 1;
    // } else if (counts.size() == 3) {
    //   cout << 2;
    // } else {
    //   cout << 3;
    // }

    cout << counts.size() - 1 << '\n';
  }

  return 0;
}
