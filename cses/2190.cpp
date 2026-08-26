#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;

  Point operator-(Point other) { return Point{x - other.x, y - other.y}; }
};

int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

int orient(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;

  int parall_area = cross(b, c);
  if (parall_area < 0) {
    return -1;
  } else if (parall_area > 0) {
    return 1;
  } else {
    return 0;
  }
}

int dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }

int segment_check(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;

  int dot_prod = dot(b, c);
  if (dot_prod < 0) {
    return -1;
  } else if (dot_prod > 0) {
    return 1;
  } else {
    return 0;
  }
}

bool on_segment(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;

  if (0 <= dot(b, c) && dot(b, c) <= dot(b, b)) {
    return true;
  } else {
    return false;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    vector<int> orients_vec;
    orients_vec.push_back(orient(a, b, c));
    orients_vec.push_back(orient(a, b, d));
    orients_vec.push_back(orient(c, d, a));
    orients_vec.push_back(orient(c, d, b));

    if (orients_vec[0] == 0 && orients_vec[1] == 0 && orients_vec[2] == 0 &&
        orients_vec[3] == 0) {
      if (on_segment(a, b, c) || on_segment(a, b, d)) {
        cout << "YES\n";
        continue;
      }

      if (segment_check(a, b, c) == segment_check(a, b, d)) {
        cout << "NO";
      } else {
        cout << "YES";
      }
      cout << '\n';
      continue;
    }

    if (orients_vec[0] == orients_vec[1] || orients_vec[2] == orients_vec[3]) {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << '\n';
  }

  return 0;
}
