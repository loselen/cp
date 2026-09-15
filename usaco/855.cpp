#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  vector<pair<int, int>> bucket_milk(3);
  for (auto &bm : bucket_milk) {
    cin >> bm.first >> bm.second;
  }

  for (int i = 0; i < 100; i++) {
    int from = i % 3;
    int to = (i + 1) % 3;

    bucket_milk[to].second += bucket_milk[from].second; // action
    bucket_milk[from].second = 0;                       // update
    if (bucket_milk[to].second > bucket_milk[to].first) {
      bucket_milk[from].second +=
          bucket_milk[to].second - bucket_milk[to].first; // action
      bucket_milk[to].second = bucket_milk[to].first;     // update
    }
  }

  for (auto bm : bucket_milk) {
    cout << bm.second << '\n';
  }

  return 0;
}
