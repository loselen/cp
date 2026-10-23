#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Point {
  int x;
  int y;
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Point> points(n);
  for (auto &p : points) {
    cin >> p.x >> p.y;
  }

  int ord = 0;
  vector<pair<Point, int>> points_upper;
  vector<pair<Point, int>> points_lower;
  vector<pair<Point, int>> pos_x;
  vector<pair<Point, int>> neg_x;
  for (auto &p : points) {
    ord++;

    if (p.y == 0) {
      if (p.x < 0) {
        neg_x.push_back({p, ord});

      } else {
        pos_x.push_back({p, ord});
      }
      continue;
    }

    if (p.y > 0) {
      points_upper.push_back({p, ord});
    } else {
      points_lower.push_back({p, ord});
    }
  }

  sort(points_upper.begin(), points_upper.end(), [](auto p, auto n) {
    Point a = p.first;
    Point b = n.first;
    __int128 det = (__int128)a.x * b.y - (__int128)a.y * b.x;
    return (det > 0);
  });
  sort(points_lower.begin(), points_lower.end(), [](auto p, auto n) {
    Point a = p.first;
    Point b = n.first;
    __int128 det = (__int128)a.x * b.y - (__int128)a.y * b.x;
    return (det > 0);
  });

  for (auto &p : points_lower) {
    cout << p.second << ' ';
  }
  for (auto &p : pos_x) {
    cout << p.second << ' ';
  }
  for (auto &p : points_upper) {
    cout << p.second << ' ';
  }
  for (auto &p : neg_x) {
    cout << p.second << ' ';
  }
  cout << '\n';

  return 0;
}
