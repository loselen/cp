#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

#define int long long

vector<pair<int, int>> return_factors(int area) {
  vector<pair<int, int>> factors;
  for (int i = 1; i * i <= area; i++) {
    if (area % i == 0) {
      factors.push_back({i, area / i});
    }
  }

  int to_add = factors.size() - 1;
  if (factors.back().first == factors.back().second) {
    to_add -= 1;
  }

  for (int i = to_add; i >= 0; i--) {
    factors.push_back({factors[i].second, factors[i].first});
  }

  return factors;
}

vector<pair<int, int>> compute_prefix(int area,
                                      vector<pair<int, int>> &factors) {
  int n = factors.size();
  vector<pair<int, int>> res;
  res.push_back({1, area});
  for (int i = 1; i < n; i++) {
    res.push_back({factors[i].first, (factors[i].first - factors[i - 1].first) *
                                             factors[i].second +
                                         res.back().second});
  }

  return res;
}

void print_vec_pair(vector<pair<int, int>> &vec) {
  for (auto pair : vec) {
    cout << '(' << pair.first << ',' << pair.second << "), ";
  }
  cout << '\n';
}

struct Point {
  int x;
  int y;
};

const int INF = 1e18;

pair<pair<int, int>, pair<int, int>>
find_closest_pair_and_next_factor(vector<pair<int, int>> &prefix_sum,
                                  vector<pair<int, int>> &factors, int a) {
  int n = prefix_sum.size();

  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;

    if (prefix_sum[mid].first > a) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  lo -= 1;

  pair<int, int> next_factor;
  if (lo + 1 == n) {
    next_factor = {INF, 0};
  } else {
    next_factor = factors[lo + 1];
  }

  return {prefix_sum[lo], next_factor};
}

int area_query(vector<pair<int, int>> &prefix_sum,
               vector<pair<int, int>> &factors, Point q, int area) {
  pair<pair<int, int>, pair<int, int>> clonext_x =
      find_closest_pair_and_next_factor(prefix_sum, factors, q.x);
  pair<pair<int, int>, pair<int, int>> clonext_y =
      find_closest_pair_and_next_factor(prefix_sum, factors, q.y);

  pair<int, int> clo_x = clonext_x.first;
  pair<int, int> clo_y = clonext_y.first;
  pair<int, int> fac_x = clonext_x.second;
  pair<int, int> fac_y = clonext_y.second;

  // case inside (<) area
  if (q.y < area / fac_x.first && q.x < area / fac_y.first) {
    return q.x * q.y;
  }

  int horizontal_area = clo_x.second + (q.x - clo_x.first) * fac_x.second;
  int to_remove = prefix_sum.back().second -
                  (clo_y.second + (q.y - clo_y.first) * fac_y.second);

  return horizontal_area - to_remove;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    int area, query;
    cin >> area >> query;

    vector<pair<int, int>> factors = return_factors(area);
    vector<pair<int, int>> prefix_sum = compute_prefix(area, factors);

    for (int j = 1; j <= query; j++) {
      Point q;
      cin >> q.x >> q.y;
      cout << area_query(prefix_sum, factors, q, area) << '\n';
    }
  }

  return 0;
}
