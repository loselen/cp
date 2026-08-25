#include <bits/stdc++.h>
using namespace std;

#define int long long

int count_unique(vector<int> nums) {
  unordered_set<int> unq_nums;
  for (auto num : nums) {
    unq_nums.insert(num);
  }
  return unq_nums.size();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int size;
    cin >> size;

    vector<int> a(size), b(size);
    for (auto &j : a) {
      cin >> j;
    }
    for (auto &j : b) {
      cin >> j;
    }

    int unq_1 = count_unique(a);
    int unq_2 = count_unique(b);

    if (unq_1 >= 3 || unq_2 >= 3) {
      cout << "YES";
    } else if (unq_1 == 2 && unq_2 == 2) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }

  return 0;
}
