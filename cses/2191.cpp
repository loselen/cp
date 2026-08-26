#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;
};

int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

int polygon_area_doubled(vector<Point> points) {
  int sum = 0;
  int n = points.size();

  for (int i = 1; i < n; i++) {
    sum += cross(points[i - 1], points[i]);
  }
  sum += cross(points[n - 1], points[0]);

  return abs(sum);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<Point> points(n);
  for (auto &p : points) {
    cin >> p.x >> p.y;
  }

  cout << polygon_area_doubled(points) << '\n';

  return 0;
}
