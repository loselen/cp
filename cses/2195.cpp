#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;

  Point operator-(Point other) { return {x - other.x, y - other.y}; }
};

__int128 det(Point a, Point b) {
  return (__int128)a.x * b.y - (__int128)a.y * b.x;
}

int orient(Point a, Point b, Point c) {
  a = a - c;
  b = b - c;
  if (det(a, b) == 0) {
    return 0;
  }
  if (det(a, b) > 0) {
    return 1;
  } else {
    return -1;
  }
}

signed main() {
  int n;
  cin >> n;

  vector<Point> points(n);
  for (auto &p : points) {
    cin >> p.x >> p.y;
  }

  Point left_bottom = points[0];
  for (auto &p : points) {
    if (p.x < left_bottom.x) {
      left_bottom = p;
    } else if (p.x == left_bottom.x) {
      if (p.y < left_bottom.y) {
        left_bottom = p;
      }
    }
  }

  for (auto &p : points) {
    p.x -= left_bottom.x;
    p.y -= left_bottom.y;
  }

  sort(points.begin(), points.end(), [](auto a, auto b) {
    int det = a.x * b.y - a.y * b.x;
    if (det == 0) {
      return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
    }

    return det > 0;
  });
  points.push_back(points[0]);

  vector<Point> convex_hull;
  convex_hull.push_back(points[0]);
  convex_hull.push_back(points[0]);
  convex_hull.push_back(points[1]);

  for (int i = 2; i < n + 1; i++) {
    while (orient(points[i], convex_hull[convex_hull.size() - 1],
                  convex_hull[convex_hull.size() - 2]) > 0) {
      convex_hull.pop_back();
    }
    convex_hull.push_back(points[i]);
  }

  cout << convex_hull.size() - 2 << '\n';
  for (int i = 1; i < convex_hull.size() - 1; i++) {
    cout << convex_hull[i].x + left_bottom.x << ' '
         << convex_hull[i].y + left_bottom.y << '\n';
  }

  return 0;
}
