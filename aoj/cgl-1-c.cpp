#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

#define int long long

struct Point {
  int x;
  int y;
};

Point operator-(Point a, Point b) { return Point{a.x - b.x, a.y - b.y}; }

int cross(Point vec_1, Point vec_2) {
  return vec_1.x * vec_2.y - vec_1.y * vec_2.x;
}

int dot(Point vec_1, Point vec_2) {
  return vec_1.x * vec_2.x + vec_1.y * vec_2.y;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Point a, b;
  cin >> a.x >> a.y >> b.x >> b.y;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    Point c;
    cin >> c.x >> c.y;

    Point vec_1 = b - a;
    Point vec_2 = c - a;

    int parall_area = cross(vec_1, vec_2);

    if (parall_area < 0) {
      cout << "CLOCKWISE";
    } else if (parall_area > 0) {
      cout << "COUNTER_CLOCKWISE";
    } else {
      int dot_prod = dot(vec_1, vec_2);
      int first_vec_squared = dot(vec_1, vec_1);

      if (dot_prod < 0) {
        cout << "ONLINE_BACK";
      } else if (dot_prod > first_vec_squared) {
        cout << "ONLINE_FRONT";
      } else {
        cout << "ON_SEGMENT";
      }
    }

    cout << '\n';
  }

  return 0;
}
